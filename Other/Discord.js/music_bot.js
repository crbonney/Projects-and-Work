const Discord = require("discord.js");
const YTDL = require("ytdl-core");
const fs = require("fs");

// app info
const package = require("./package.json");
const token = package.token; //bot secret token
const prefix = package.prefix; //command prefix so the bot knows you're talking to it

// initialize bot
var bot = new Discord.Client();

// object containing servers that the bot is being used in
var servers = {};

var title;
var temp;

// triggers once bot initializes
bot.on("ready", function () {

    console.log("Ready");
});

// triggers when a message is posted in a channel
bot.on("message", function (message) {


    // if the message author is a bot, or it doesn't start with the command prefix, ignore message
    if (message.author.equals(bot.user)) return;
    if (!message.content.startsWith(prefix)) return;

    // process message info, and discard prefix
    var args = message.content.substring(prefix.length).split(" ");

    // load the server that the message is from
    var server = servers[message.guild.id];

    // switch statement checks what the command is
    switch (args[0].toLowerCase()) {
        // debug command, checks if bot is responding
        case "ping": message.channel.send("Ping!");
            break;

        // turns the automated playlist function on/off, or if given a video link, will make a playlist from that and start playing
        case "playlist":

        // if server hasn't been used before, create an object for it
        if (!server) {
            servers[message.guild.id] = {
                queue: [],
                likedCodes: [],
                likedTags: [],
                playedSongs: [],
                currentSong: [],
                playlistOn: false,
                volume: 10
            };
            var server = servers[message.guild.id];
        }

        // if not given a video link, switch playlist on/off and return
        if (!args[1]) {
          server.playlistOn = !server.playlistOn;
          console.log(`Playlist on: ${server.playlistOn}`);
          message.channel.send(`Automated playlist function is ${server.playlistOn ? "ON" : "OFF"}`);
          return;
        }

        server.playlistOn = true;

        while (server.queue.length > 0) {
            server.queue.pop();
        }
        // if given a video link, continue into case "play"


        // plays audio from specified youtube video link
        case "play":

            if (!args[1]) {
                message.channel.send("Give a link to a youtube video.");
                return;
            }
            if (!message.member.voice.channel) {
                message.channel.send("You must be in a voice channel.");
                return;
            }

            // if server hasn't been used before, create an object for it
            if (!server) {
                servers[message.guild.id] = {
                    queue: [],
                    likedCodes: [],
                    likedTags: [],
                    playedSongs: [],
                    currentSong: [],
                    playlistOn: false,
                    volume: 10
                };
                var server = servers[message.guild.id];
            }

            // create url from command
            var song = args.slice(1).join(" ");

            // load song info, then call play method
            if (args[1].includes("youtube")) {
                YTDL.getInfo(song, (err, info) => {
                    if (err) console.log(err);
                }).then(info => {
                  title = info.videoDetails.title;
                  console.log(title);
                  server.queue.push([song, title]);
                  message.channel.send(`${title} has been added to the queue!`);
                  console.log(server.queue[server.queue.length - 1]);
                  if (!server.dispatcher || server.dispatcher.finished) {
                    play(message);
                  }
                });
            }

            break;

        // pauses the current audio
        case "pause":
            var server = servers[message.guild.id];

            if (!server.dispatcher.paused) {
                server.dispatcher.pause();
                message.channel.send(`Pausing ${server.currentSong[1]}`);
            }
            break;

        // resumes the current audio
        case "resume":
            var server = servers[message.guild.id];
            if (server.dispatcher.paused) {
                server.dispatcher.resume();

                message.channel.send(`Resuming ${server.currentSong[1]}`);
            }
            break;

        // skips the current video
        case "skip":
            var server = servers[message.guild.id];

            if (server.dispatcher) {
                server.dispatcher.end();
            }
            else {
                message.channel.send("There is nothing to skip");
            }
            break;

        // lists the current volume, or if given an argument, adjusts it
        case "volume":
            var server = servers[message.guild.id];

            if (!server) {
              message.channel.send("There is nothing playing!");
              return;
            }

            if (!args[1]) {
              message.channel.send(`The current volume is ${server.volume}`);
              return;
            }
            args[1] = parseInt(args[1]);

            if (isNaN(args[1]) || args[1] > 100 || args[1] < 1) {
              message.channel.send("Please input a number between 1 and 100");
              return;
            }

            if (server.dispatcher) {
                server.volume = args[1];
                server.dispatcher.setVolume(server.volume/100);
                message.channel.send(`Setting volume to ${server.volume}.`);
            }

            break;

        // stops playing music, pops the queue, and disconnects bot from voice channel
        case "stop":

            var server = servers[message.guild.id];

            if (server) {
                console.log("playlist off");
                server.playlistOn = false;

                while (server.queue.length > 0) {
                    server.queue.pop();
                }

                server.dispatcher.end();
            }

            break;

        //list of song ids that have already been played (debug command)
        case "played":
            console.log(servers[message.guild.id].playedSongs);
            break;



            /* DISUSED - like videos to get similar kinds of videos in playlist function
        case "like":

            var code = /.*?=(.*)/.exec(server.currentSong[0])[1];
            var matchFound = false;
            for (var i = 0; i < server.likedCodes.length; i++) {
                if (code == server.likedCodes[i][0]) {
                    server.likedCodes[i][1]++;
                    console.log("++code");
                    fs.writeFile(__dirname + "/" + message.guild.id + "/likedCodes.txt", server.likedCodes, 'utf8', (err) => {
                        if (err) throw err;
                    });
                    matchFound = true;
                    break;
                }
            }
            if (!matchFound) {
                console.log("new code");
                server.likedCodes.push([code, 1]);
                fs.writeFile(__dirname + "/" + message.guild.id + "/likedCodes.txt", server.likedCodes, 'utf8', (err) => {
                    if (err) throw err;
                });
            }

            YTDL.getInfo(server.currentSong[0], (err, info) => {

                for (var i = 0; i < info.keywords.length; i++) {
                    for (var j = 0; j < server.likedTags.length; j++) {
                        if (info.keywords[i] == server.likedTags[j][0]) {
                            server.likedTags[j][1]++;
                            console.log(info.keywords);
                            info.keywords.splice(i, 1);
                            i = -1;
                            break;
                        }
                    }
                }
                console.log(info.keywords);
                for (var i = 0; i < info.keywords.length; i++) {
                    server.likedTags.push([info.keywords[i], 1]);
                    console.log("added tag");
                }

                fs.writeFile(__dirname + "/" + message.guild.id + "/likedTags.txt", server.likedTags, 'utf8', (err) => {
                    if (err) throw err;
                });
            });

            break;

        case "showlikes":

            if (!servers[message.guild.id]) {
                servers[message.guild.id] = {
                    queue: [],
                    likedCodes: [],
                    likedTags: [],
                    playedSongs: [],
                    currentSong: [],
                    playlistOn: false
                };

                var dir = __dirname + "/" + message.guild.id;

                try {
                    fs.statSync(dir);
                } catch (e) {
                    fs.mkdirSync(dir);
                    fs.writeFileSync(dir + "likedCodes.txt", "");
                    fs.writeFileSync(dir + "likedTags.txt", "");
                }

                fs.readFile(__dirname + "/" + message.guild.id + "/likedCodes.txt", 'utf8', (err, data) => {

                    if (err) throw err;

                    var regex = /(.*?),\s*?(\d*?)(,|$)/g;

                    while (match = regex.exec(data)) {
                        server.likedCodes.push([match[1], parseInt(match[2])]);
                    }
                    console.log(server.likedCodes);
                });
                fs.readFile(__dirname + "/" + message.guild.id + "/likedTags.txt", 'utf8', (err, data) => {

                    if (err) throw err;

                    var regex = /(.*?),\s*?(\d*?)(,|$)/g;

                    while (match = regex.exec(data)) {
                        server.likedTags.push([match[1], parseInt(match[2])]);
                    }
                    console.log(server.likedTags);
                });

            }

            server = servers[message.guild.id];

            console.log(server.likedCodes);
            console.log(server.likedTags);

            break;
            */

        // displays the current song's name
        case "currentsong":

            message.channel.send(`The current song is: ${servers[message.guild.id].currentSong[1]}`);

            break;

        // shows an embed showing the song queue
        case "queue":

            var server = servers[message.guild.id];

            var queue = new Discord.MessageEmbed()
                .setColor([40, 110, 200])
                .setTitle("Queued Songs:")
                .setThumbnail(bot.user.avatarURL);

            if (server.queue.length == 0) {
                queue.addField("There are no songs queued", "to add a song, use the ~play command");
            }

            for (var i = 0; i < server.queue.length; i++) {
                queue.addField(server.queue[i][1], server.queue[i][0]);
            }

            if (server.playlistOn) {
                queue.addField("Playlist turned on: ", "The bot will pick the next song for you.");
            }

            message.channel.send(queue);
            break;

        // if invalid commmand, send error statement
        default:
            message.channel.send(args + " is an invalid command. use '~help' for a list of commands.");
            break;

        // sends command list as embed
        case "help":
        case "commands":

            var commands = new Discord.MessageEmbed()
                .setColor([40, 110, 200])
                .setTitle("MuBot Commands:")
                .addField("~play 'youtube link'", "plays youtube link", true)
                .addField("~playCode 'yt video code'", "plays youtube video code", true)
                .addField("~playlist 'youtube link'", "starts a playlist", true)
                .addField("~playlist", "turns playlist on/off", true)
                .addField("~pause", "pauses song", true)
                .addField("~resume", "resumes song", true)
                .addField("~skip", "skips current song", true)
                .addField("~queue", "shows queue of songs", true)
                .addField("~currentSong", "shows current song", true)
                .addField("~stop", "stops playing and cancels queue", true)
                .setThumbnail(bot.user.avatarURL);

            message.channel.send(commands);
            break;
    }

});

function showQueue(message) {

    var server = servers[message.guild.id];

    message.channel.send(server.queue);

}

// picks a random video from the "related videos" list from youtube
function pickSong(message,server) {

    // remove all but the next song
    while (server.queue.length > 1) {
        server.queue.pop();
    }

    console.log("looking for next video: ");
    // get info from current video
    YTDL.getInfo(server.currentSong[0], (err, info) => {
        if (err) return console.log(err)
      }).then(info => {

        var index = 0;
        var tries = 0;
        // randomly select next video from expanding list
        for (; ;) {
            index = Math.floor(Math.random() * (tries+2)); // increase search range on fail

            // related_videos[1] is not a video for some reason
            if (index == 1) {
                index++;
            }

            // get the video code id
            var code = (info.related_videos[index].id) ? info.related_videos[index].id : info.related_videos[index].video_id;

            // check if code id exists, and if it is in the "already played" list
            if (!code) {
                console.log(info.related_videos);
            }
            else {
                console.log(index + ": " + code);
                // if video hasn't been played yet, select it as next video
                if (!server.playedSongs.includes(code)) {
                    console.log(info.related_videos[index].title);
                    break;
                }
            }

            // if id is invalid or has already been played, try again
            tries++;
        }

        console.log("https://www.youtube.com/watch?v=" + code);
        // add next video to queue, and send message
        server.queue.push(["https://www.youtube.com/watch?v=" + code, info.related_videos[index].title]);
        message.channel.send(`the next song will be ${info.related_videos[index].title}`)
    });


}

// plays next song in the queue
function play(message) {

    var server = servers[message.guild.id];

    // join the required voice channel, if not already in it
    message.member.voice.channel.join().then(function (connection) {
      if (server.queue[0][0].includes("youtube")) {
          // create audio stream from video
          server.dispatcher = connection.play(YTDL(server.queue[0][0], { filter: "audioonly" }));

          // add video to list of played songs, set as current, and remove from the queue
          server.playedSongs.push(/.*?=(.*)/.exec(server.queue[0][0])[1]);
          server.currentSong = server.queue[0];
      } else {
        console.log("invalid video link");
        message.channel.send("Invalid video link, removing from queue")
        server.queue.shift();
        return play(message);
      }

      // makes sure volume is set correctly
      server.dispatcher.setVolume(server.volume/100);

      // if automated playlist function is on, it picks the next song
      if (server.playlistOn) {
          pickSong(message,server);
      }

      // when video is comlete, play next in queue, or if queue is empty, disconnect
      server.dispatcher.on("finish", function () {
        console.log("done");
          if (server.queue.length > 0) {
              message.channel.send(`Playing ${server.queue[0][1]}`)
              return play(message);
          }
          else {
              message.channel.send("The queue is finished, disconnecting.")
              return connection.disconnect();
          }
      });
    });


}

// logs the bot in with secret token
bot.login(token);
