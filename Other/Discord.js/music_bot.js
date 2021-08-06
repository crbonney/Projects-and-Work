//PACKAGES
const Discord = require("discord.js");
const YTDL = require("ytdl-core");
const fs = require("fs");
const ffmpeg = require('fluent-ffmpeg');

//SEARCH KEY for Youtube API
const key = {
    maxResults: 5,
    key: "AIzaSyBp3X2KB3WXtP8rp1rNNLO7Ly9uLpNdjSs"
};

//bot token ***DO NOT SHARE***
const token = package.token;

//MESSAGE PREFIX
const prefix = "!";

//INITIALIZE BOT CLIENT
var bot = new Discord.Client();

//logs bot into discord with its token
bot.login(token);

//Channel Consts
const quest_board_id = '438050640271507466';
const chris_id = '190248534925246464';
const bot_commands_id = '441609746475122688';
const general_id = '438048843674943498';
var server;
var bot_commands;
var general_chat;

//OPEN VARIABLE TO HOLD ACTIVE SERVERS
var servers = {};

//DISPLAYS MESSAGE WHEN READY
bot.on("ready", function () {

    server = bot.channels.get(quest_board_id).guild;
    bot_commands = bot.channels.get(bot_commands_id);
    general_chat = bot.channels.get(general_id);
    console.log('Ready');
});


//TAKES MESSAGE FROM CHANNEL
bot.on("message", function (message) {

    //if bot sent message, ignore
    if (message.author.equals(bot.user)) return;

    //if message doesn't start with prefix, ignore
    if (!message.content.startsWith(prefix)) return;


    //if messege sender doesn't have permissions, notify and ignore
    // if (message.author.id != chris_id) {
    //     message.channel.send("You don't have permissions.");
    //     return;
    // }

    //split message into array based on spaces
    var args = message.content.substring(prefix.length).split(" ");

    // if user isn't in a voice channel, notify and return
    if (message.type != "dm" && message.member.voiceChannel) {

        var server = servers[message.guild.id];

        //identifies the guild (server) that sent the message, if the server doesn't exist, make it in servers
        if (!server) {

            //make new guild object with these extra properties
            servers[message.guild.id] = {
                queue: [],
                volume: 10,
                //playedSongs: [],
                currentSong: [],
                //playlistOn: false,
                //searchResults: [],
                //searching: false
            };

            server = servers[message.guild.id];

        }

        console.log(server.dispatcher);

        //SWITCH TO TEST FOR COMMAND CASES FROM MESSAGE ARRAY
        switch (args[0]) {


            //plays a youtube video from its video code or URL
            case "playyt":

                //if there are no arguments or too many arguments, notify and ignore
                if (!args[1]) {
                    message.channel.send("Give a video code or URL");
                    return;
                }

                console.log(args[1].includes("youtube"));

                //turns input into a YT video URL
                var song;
                if (args[1].includes("youtube")) {
                    //if it is a URL already, save
                    song = args[1];
                }
                else {
                    //else create a string Url from a YT video code
                    song = `https://www.youtube.com/watch?v=${args[1]}`;
                }

                console.log(song);

                //async call to get title of video
                var title;

                if (!YTDL.validateURL(song)) {
                    console.log("URL/Code invalid");
                    return;
                }

                YTDL.getInfo(song, (err, info) => {
                    if (err) throw err;
                    title = info.title;
                    console.log(title);
                    if (server.queue[server.queue.length - 1]) {
                        server.queue[server.queue.length - 1][1] = title;
                    }
                });

                //adds song to queue - title may not yet be loaded
                server.queue.push([song, title]);

                //logs the added song
                console.log(server.queue[server.queue.length - 1][0]);

                //if not already playing a song, enter recursive play method
                if (!message.guild.voiceConnection) message.member.voiceChannel.join().then(function (connection) {
                    play(connection, message);
                });

                return;

            //plays a downloaded mp3 from folder (hidden command)
            case "play":

                var song = args.slice(1).join(" ");

                server.queue.push([`${song}.mp3`, song]);

                console.log(server.queue[server.queue.length - 1][0]);

                if (!message.guild.voiceConnection) {
                    message.member.voiceChannel.join().then(function (connection) {
                        play(connection, message);
                    });
                }

                return;

            //turns playlist feature on or off
            case "playlist":

                //if playlist is off, turn on
                if (!server.playlistOn) {
                    server.playlistOn = true;
                    console.log("playlist on");

                    //remove the queue to prepare for the playlist
                    while (server.queue.length > 0) {
                        server.queue.pop();
                    }

                    //picks a song for the playlist
                    pickSong(server);
                }
                //otherwise turn it off
                else {
                    console.log("playlist off");
                    server.playlistOn = false;
                }
                message.channel.send(`Playlist on: ${server.playlistOn}`);

                return;

            //pauses the song, if playing
            case "pause":

                //if the song isn't paused, pause it
                if (!server.dispatcher.paused) {
                    server.dispatcher.pause();
                    message.channel.send("Pausing");
                }

                return;

            //resumes the song, if paused
            case "resume":

                //if the song is paused, resume it
                if (server.dispatcher.paused) {
                    servers[message.guild.id].dispatcher.resume();
                    message.channel.send("Resuming");
                }

                return;

            //skips the currently playing song
            case "skip":

                //if a song is playing, end it.
                if (server.dispatcher) {
                    server.dispatcher.end();
                }
                //else notify
                else {
                    message.channel.send("There is nothing to skip");
                }

                return;

            //adjusts the volume
            case "volume":

                var new_volume = parseInt(args[1]);

                if (!new_volume || 0 > new_volume || new_volume > 100) {
                    message.channel.send("Give a number for volume (0-100)");
                    return;
                }
                console.log(server.volume);
                //if song is playing, set volume to argument
                if (server.dispatcher) {

                    var fade = setInterval(() => {
                        console.log(server.volume);
                        if (new_volume != server.volume) {
                            server.volume = (server.volume < new_volume) ? server.volume + 1 : server.volume - 1;
                            server.dispatcher.setVolume(server.volume/1000.0);

                        } else {
                            server.dispatcher.setVolume(server.volume / 1000.0);
                            console.log(server.volume);
                            clearInterval(fade);
                        }

                    }, 50);

                } else {
                    message.channel.send("There is no music right now");

                }

                return;

            //stops current song and deletes queue
            case "stop":

                //if playing, stop and delete queue, and notify
                if (server.dispatcher) {

                    //turns off playlist
                    server.playlistOn = false;

                    //removes queue
                    while (server.queue.length > 0) {
                        server.queue.pop();
                    }

                    //ends current song
                    server.dispatcher.end();

                    //notify
                    message.channel.send("The music has stopped.");
                }
                //else notify
                else {
                    message.channel.send("There is nothing to stop.");
                }

                return;

            //hidden command to log previously played songs
            case "played":

                console.log(servers[message.guild.id].playedSongs);

                return;

            //sends message with current song
            case "currentsong":
                console.log(servers[message.guild.id].currentSong[1]);
                message.channel.send(servers[message.guild.id].currentSong[1]);

                return;

            //shows the queue and playlist status
            case "queue":

                //creates an Embed for queued songs
                var queue = new Discord.RichEmbed()
                    .setColor([40, 110, 200])
                    .setTitle("Queued Songs:")
                    .setThumbnail(bot.user.avatarURL);

                //if no songs, add to Embed
                if (server.queue.length == 0) {
                    queue.addField("There are no songs queued", "to add a song, use the ~play command");
                }

                //else add field for each song in queue
                for (var i = 0; i < server.queue.length; i++) {
                    queue.addField(server.queue[i][1], server.queue[i][0]);
                }

                //if playlist on, add field stating
                if (server.playlistOn) {
                    queue.addField("Playlist turned on: ", "The bot will pick the next song for you.");
                }

                //send Embed
                message.channel.send(queue);

                return;
        }
    }

    //SWITCH STATEMENT FOR NON-VOICE CHAT COMMANDS
    switch (args[0].toLowerCase()) {

        //hidden command to test if bot is active
        case "test":
            message.channel.send('ping!');
            break;

        //download command
        case "download":

            var infos = [];
            var streams = [];
            var starts = [];
            var ffmpegs = [];

            //if no arguments given, notify and return
            if (!args[1]) {
                console.log("Give a video code or URL");
                return;
            }

            var text = args.splice(1).join(" ");

            var regex = /\W*(.*?),\W(.*?)$/;
            var match = regex.exec(text);

            var videos = [];
            var title;
            if (!match || match.length < 2) {
                console.log(`attempting to download ${args.length - 1} videos`);

                videos = args.splice(1);

            } else {
                videos[0] = match[1];
                title = match[2];
            }


            var allvideos = videos.forEach((video, i) => {

                //gets rid of extra spaces
                video = video.trim();

                //builds URL from video code and validates
                if (video.includes("youtube")) {
                    song = video;
                } else {
                    var song = `https://www.youtube.com/watch?v=${video}`;
                }

                //if it isn't valid, return

                if (!YTDL.validateURL(song)) {
                    console.log("invalid URL");
                    return;
                }

                //does lots of stuff and gets the file
                infos[i] = YTDL.getInfo(song, (err, info) => {

                    if (err) throw err;

                    if (!title) {
                        title = info.title.match(/(\w|\s)/g).join("");
                    }

                    streams[i] = YTDL(song, {
                        quality: 'highestaudio',
                        //filter: 'audioonly',
                    });

                    starts[i] = Date.now();
                    ffmpegs[i] = ffmpeg(streams[i])
                        .audioBitrate(128)
                        .save(`${__dirname}/music/${title}.mp3`)
                        /*.on('progress', (p) => {
                            readline.cursorTo(process.stdout, 0);
                            process.stdout.write(`${p.targetSize}kb downloaded`);
                        })*/
                        .on('end', () => {
                            console.log(`${title} was downloaded in - ${(Date.now() - starts[i]) / 1000} seconds`);
                            message.channel.send(`${title} was successfully downloaded.`);
                            title = 0;
                        });
                });

            });

            break;

        //if improper command, send message with 'help'
        default:
            message.channel.send(`${args} is an invalid command. use '~help' or '~commands' for a list of commands.`);
            break;

        //command send Embed with list of MuBot commands
        case "help":
        case "commands":

            //Embed with commands
            var commands = new Discord.RichEmbed()
                .setColor([40, 110, 200])
                .setTitle("MuBot Commands:")
                .addField("~play [mp3 song name]", "Plays a mp3 file from the music folder")
                //.addField("~playyt 'youtube link'", "plays youtube link", true)
                //.addField("~playyt 'yt video code'", "plays youtube video code", true)
                //.addField("~playlist", "turns playlist on/off", true)
                .addField("~pause", "pauses song", true)
                .addField("~resume", "resumes song", true)
                .addField("~skip", "skips current song", true)
                .addField("~queue", "shows queue of songs", true)
                .addField("~volume [0-1]", "sets the volume to a level between 0 and 1. the standard is 0.05")
                .addField("~currentSong", "shows current song", true)
                .addField("~stop", "stops playing and cancels queue", true)
                //.addField("~download [yt link/code] [more yt link/codes]", "downloads a/many youtube video(s) as an mp3. Seperate with spaces or linebreaks.")
                .addField("~download [YT link/code], [desired title]", "downloads a YT video as an mp3 with alternate title.")
                //.addField("~upload 'yt video code'", "gets and uploads an audio mp3 of the video to the chat")
                .setThumbnail(bot.user.avatarURL);

            message.channel.send(commands);
            break;
    }

});


//function to pick a song when playlist is on
function pickSong(server) {

    console.log(server.currentSong);
    //retrieves info on current song (related_videos)
    YTDL.getInfo(server.currentSong[0], (err, info) => {

        //initializes variables used in forever loop
        //randomly generated index based on weights
        var index = 0;

        //picks a song, checks and accepts, or rejects and tries again
        //if it takes too many tries, breaks
        for (var tries = 0; tries < 10 ; tries++) {
            //randomly generated number with weights
            index = Math.floor(Math.random() * (tries + 2));
            //index 1 of related_videos is always a playlist, ignore
            if (index == 1) {
                index++;
            }
            //grab code of indexed video
            var code = info.related_videos[index].id;
            //make sure code was found (if not, restart)
            if (code) {
                console.log(`${index} : ${code}`);
                //if video was played before or video is too long, restart search
                if (!server.playedSongs.includes(code) && info.related_videos[index].length_seconds < 540) {
                    //else return the new song
                    console.log(info.related_videos[index].title);
                    //logs the video URL and adds it to the queue
                    console.log(`https://www.youtube.com/watch?v=${code}`);
                    server.queue.push([`https://www.youtube.com/watch?v=${code}`, info.related_videos[index].title]);
                    return;
                }
            }

        }
        console.log("song not found");

    });
}


//recursive function called to start playing, or play next from queue
function play(connection, message) {

    //server from message sender
    var server = servers[message.guild.id];

    //if youtube URL execute play youtube song
    if (server.queue[0][0].includes("youtube")) {
        //creates audio playstream of video
        server.dispatcher = connection.playStream(YTDL(server.queue[0][0], { filter: "audioonly" }));

        //adds song to played songs array
        //server.playedSongs.push(/.*?=(.*)/.exec(server.queue[0][0])[1]);

        //if too many played songs shift array
        //if (server.playedSongs.length > 20) {
        //   server.playedSongs.shift();
        //}

        //if new song's title isn't loaded, get it and save it as current song title
        if (!server.queue[0][1]) {
            YTDL.getInfo(server.queue[0][0], (err, info) => {
                server.currentSong[1] = info.title;
            });
        }
        else {
            server.currentSong[1] = server.queue[0][1];
        }

        //set the URL of new song as currently playing
        server.currentSong = server.queue[0];
    }

    //else assume it is a downloaded mp3 file
    else {
        //plays mp3 song
        server.dispatcher = connection.playFile(`./music/${server.queue[0][0]}`);
        //sets it as current song
        server.currentSong[0] = server.queue[0][0];
        server.currentSong[1] = server.queue[0][1];
    }

    //volume is naturally too loud
    server.dispatcher.setVolume(0.001);
    var new_volume = server.volume;
    server.volume = 1;
    var fade = setInterval(() => {
        console.log(server.volume);
        if (new_volume != server.volume) {

            server.volume = (server.volume < new_volume) ? server.volume + 1 : server.volume - 1;
            server.dispatcher.setVolume(server.volume / 1000.0);

        } else {
            server.dispatcher.setVolume(server.volume / 1000.0);
            console.log("final :" + server.volume);
            clearInterval(fade);
        }

    }, 150);


    //if playlist is on, pick the next song
    //if (server.playlistOn) {
    //    pickSong(server);
    //}

    //removes current song from queue
    server.queue.shift();

    //when song ends, if another play next, else end connection and leave channel
    server.dispatcher.on("end", function () {
        if (server.queue.length > 0) {
            play(connection, message);
        }
        else {
            connection.disconnect();
        }
    });
}
