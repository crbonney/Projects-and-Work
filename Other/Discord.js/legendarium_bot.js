//dependencies
const Discord = require("discord.js");
const fs = require('fs');
const package = require('./package.json');
//const xml2js = require('xml2js');
const https = require('https');
const parseString = require('xml2js').parseString;

const xml_url = "https://feed.podbean.com/thelegendarium/feed.xml";
const gt_xml_url = "https://anchor.fm/s/19bf48c0/podcast/rss";
//1000ms*60sec*60min = 1 hr
const HOUR = 1000*60*60;
const FIVE_MIN = 1000*60*5;

//bot token ***DO NOT SHARE***
 const token = package.token;

// SETUP VARIABLES AND CONSTANTS
const SAVE_EMOJI = "✅";
const prefix = "!";
const ROLE_PREFIX = ".";
const events = {
	MESSAGE_REACTION_ADD: 'messageReactionAdd' // sets discord API to check for reactions to messages
	//MESSAGE_REACTION_REMOVE: 'messageReactionRemove',
};

const SPOILER_MESSAGE = "Don't forget to use spoiler tags when discussing books. You can use `||spoiler||` for the sensitive content or `/spoiler` to hide the entire message. Say the book you're talking about and then spoiler tags to hide the message. \nExample: (Wheel of Time book 4)||Spoilers Spoilers.||"

// stores data on the most recent podcast episode
let data;
let data_JSON;
let last_episode = "startup";
let last_episode_data = [];

// stores data on the most recent podcast episode for the green team
let gt_data;
let gt_data_JSON;
let gt_last_episode = "startup";
let gt_last_episode_data = [];

//create bot user and login
let bot = new Discord.Client();
bot.login(token);

//admin user ids
const craig_id = "520298731900239882";
let craig;
const rabbit_id = "190248534925246464";
let rabbit;

// server channel ids
const legendarium_general_id = "522815365282136080";
let legendarium_general;
const legendarium_episode_discussion_id = "522815800155963436";
let legendarium_episode_discussion;
let thelegendarium_server;
const legendarium_bot_spam_id = "522844970755817483";
let legendarium_bot_spam;
const legendarium_green_team_discussion_id = "746233855194693683";
let legendarium_green_team_discussion;
const legendarium_introduction_id = "523512119472160768";

const episode_alert_id = "746230901599633500";
const green_team_alert_id = "746230969832308847";

const bot_server_general_id = "615977860523360306";
let bot_server_general;
let bot_server;

// counters and invervals used for manually updating XML info
let update_counter;
let gt_update_counter;
let manual_update_interval;
let gt_manual_update_interval;

//names and IDs of server roles that matter to the bot
const VANITY_ROLES = ["Trusted", "Cult of Craig", "Troupe of Todd", "Knights of Kenn", "Ryan's Roughnecks", "Kyle's Congregation", "Megan's Mob", "Stephanie's Secret Society"];
const ALERT_ROLES = ["Livestream Alert", "Episode Alert", "Green Team Alert", "Pierce Book Club", "Question Alert","AmongUs","Bingo Player"];
const ADMIN_ROLES = ["Admin", "Legendarium", "Moderator"];
const REACT_ROLE_IDS = ["522817100352454656", "522817202462916617", "522817177318064135"]; // patron and admin users only

// edit console.log to give timestamp on print
console.logCopy = console.log.bind(console);

console.log = function (data) {
	var timestamp = `[${new Date().toUTCString()}]`;
	this.logCopy(timestamp, data);
};

// bot init, loads channel and user information
const on_ready = bot.on("ready", ()=> {

  // load server information
	rabbit = bot.users.get(rabbit_id);
	craig = bot.users.get(craig_id);

  //testing server and channels
	bot_server_general = bot.channels.get(bot_server_general_id);
	bot_server = bot_server_general.guild;

  //main server and channels channels
	legendarium_general = bot.channels.get(legendarium_general_id);
	legendarium_episode_discussion = bot.channels.get(legendarium_episode_discussion_id);
	legendarium_green_team_discussion = bot.channels.get(legendarium_green_team_discussion_id);
	legendarium_bot_spam = bot.channels.get(legendarium_bot_spam_id);
	thelegendarium_server = legendarium_general.guild;

  // load most recent podcast episode into storage
	updateXML();
	gt_updateXML();

	console.log("Bot ready.");

});

// handles errors from internet connection failures. Catastrophic errors are still thrown and restart the bot
const on_error = bot.on("error", (error) => {
	console.log(error);
});

// sends welcome message to new users
const on_join = bot.on("guildMemberAdd", (member) => {

	console.log("member join");
	if(member.guild == thelegendarium_server) {
		legendarium_general.send(`Welcome, <@${member.id}>, to The Legendarium! Jump over to <#${legendarium_introduction_id}> and tell us a little about yourself and how you got into the podcast. And if you have one, declare your favorite panelist and we'll sort you into the proper ~~support group~~ house.`);
	}

});

// listener triggers whenever a message is sent
const on_message = bot.on("message", (message)=> {

	//if bot sent message, ignore
	if (message.author.equals(bot.user)) return;

	//if starts with set_role prefix, skip to that function
	if (message.content.startsWith(ROLE_PREFIX)) return setRole(message);

	//if message doesn't start with command prefix, ignore
	if (!message.content.startsWith(prefix)) return;

	//filters arguments for command, and split into array
	let args = message.content.substring(prefix.length).split(" ").filter(arg => arg != '');

	//checks what command to run
	switch (args[0]) {

		//checks for new episodes manually
		case "update":
		console.log("manual update called");
		update_counter = 0;
		manual_updateXML();
		break;

		case "updategt":
		console.log("green team manual update called");
		gt_update_counter = 0;
		gt_manual_updateXML();
		break;

    //admin manually posts the last episode with alert
		case "manualpost":
    // if not admin, ignore
    if (!message.author.id == rabbit.id && !message.author.id == craig.id ) return;

		console.log("manually posting last episode");
		legendarium_episode_discussion.send(`<@&${episode_alert_id}>\n ${last_episode_data.link}`)
		break;

		case "manualpostgt":
    // if not admin, ignore
    if (!message.author.id == rabbit.id && !message.author.id == craig.id ) return;

		console.log("manually posting last gt episode");
		legendarium_green_team_discussion.send(`<@&${green_team_alert_id}>\n ${gt_last_episode_data.link}`);
		break;

    // posts a link to an episode given the episode number, or the latest episode if not
		case "postepisode":
		console.log("searching for episode");
		episode_number = args[1];
		if (!episode_number) {
			message.channel.send(`Last episode: ${last_episode_data.title[0]} \n${last_episode_data.link}`);
			break;
		}
		searchEpisode(episode_number, message);
		break;

    // bugfix command to verify bot is responding to messages
		case "ping":
		console.log('ping');
		message.channel.send('ping');
		break;

		case "spoiler":
		case "spoilers":
		message.channel.send(SPOILER_MESSAGE);
		break;

		// (not used) - post a list of the bot's commands
		// case "help":
		// default:
		//
		// break;
	}

});

// response to a message reaction
const on_event = bot.on("raw", event => {

	if (!events.hasOwnProperty(event.t)) return;

	const { d: data } = event;

	const user = bot.users.get(data.user_id);
  // console.log(user);

	// check if user is allowed to use the bot for reactions
	if (!data.member.roles.some(role=>REACT_ROLE_IDS.includes(role))) return;

  // check if the emoji is the right one
	if (data.emoji.name !== SAVE_EMOJI) return;

  // send user a private message with the text of the message they reacted to, so they have it for later reference
	if (data.guild_id) {

    // finds the message info, then sends message
		const channel = bot.channels.get(data.channel_id);
		channel.fetchMessage(data.message_id).then(msg => {
  		console.log("sending reaction reminder");
  		user.send(`${msg.author.username}: ${msg.content}`);
		});
	}
});

// checks for updates, then continues to check every five minutes for half an hour (in case the RSS feed took longer to update)
let manual_updateXML = function() {

	console.log(`manual update attempt ${update_counter}`);
	updateXML();
	update_counter++;

	manual_update_interval = setInterval(()=> {
		console.log(`manual update attempt ${update_counter}`);
		updateXML();
		if (++update_counter === 6) clearInterval(manual_update_interval);
	}, FIVE_MIN);

};

let gt_manual_updateXML = function() {

	console.log(`manual update attempt ${gt_update_counter}`);
	gt_updateXML();
	gt_update_counter++;
	gt_manual_update_interval = setInterval(()=> {
		console.log(`green team manual update attempt ${gt_update_counter}`);
		gt_updateXML();
		if (++gt_update_counter === 6) clearInterval(gt_manual_update_interval);
	}, FIVE_MIN);

};

//checks podcast's RSS feed, updates last_episode
const updateXML = function() {
	console.log("updating XML");
	data = '';
	data_JSON = {};
  // gets the RSS feed from the URL
	https.get(xml_url, (res)=>{
    // if no error, continue
		if (res.statusCode >= 200 && res.statusCode < 400) {
			res.on('data', function(data_) {
				data += data_.toString();
			});
      // when finished loading data, parse into JSON
			res.on('end', function() {
				parseString(data, function (err, result) {
					data = JSON.stringify(result);
					data_JSON = JSON.parse(data);

          // get the latest episodes title
					let this_episode = data_JSON.rss.channel[0].item[0].title[0];

          // if no changes, do nothing
          if (this_episode == last_episode) {
            //
					} // if startup, store as latest episode
          else if (last_episode == "startup") {
						last_episode = this_episode;
						last_episode_data = data_JSON.rss.channel[0].item[0];

						console.log(`Storing episode: ${this_episode} \n${last_episode_data.link}`);
					} // else, there is a new episdoe, store it as the latest and post a notification
          else {
						console.log(`NEW EPISODE: ${this_episode} \n ${last_episode_data.link}`);

						last_episode = this_episode;
						last_episode_data = data_JSON.rss.channel[0].item[0];
						legendarium_episode_discussion.send(`<@&${episode_alert_id}>\n ${last_episode_data.link}`);
					}
					console.log("XML update complete");
				});
			});
		}
	});
};


const gt_updateXML = function() {
	console.log("updating green team XML");
	gt_data = '';
	gt_data_JSON = {};
	https.get(gt_xml_url, (res)=>{
		if (res.statusCode >= 200 && res.statusCode < 400) {

			res.on('data', function(data_) {
				gt_data += data_.toString();
			});

			res.on('end', function() {
				parseString(gt_data, function (err, result) {
					gt_data_JSON = result;

					let this_episode = gt_data_JSON.rss.channel[0].item[0].title[0];
					if (this_episode == gt_last_episode) {

					} else if (gt_last_episode == "startup") {
						gt_last_episode = this_episode;
						gt_last_episode_data = gt_data_JSON.rss.channel[0].item[0];

						console.log(`Storing episode: ${this_episode} \n${gt_last_episode_data.link}`);

					} else {
						console.log(`NEW EPISODE: ${this_episode} \n ${gt_last_episode_data.link}`);
						gt_last_episode = this_episode;
						gt_last_episode_data = gt_data_JSON.rss.channel[0].item[0];
						legendarium_green_team_discussion.send(`<@&${green_team_alert_id}>\n ${gt_last_episode_data.link}`);
					}
					console.log("green team XML update complete");
				});
			});
		}
	});
};

// automatically checks for new episodes every HOUR
setInterval (updateXML, HOUR);
setInterval (gt_updateXML, HOUR);

//searches for an episode number in the RSS feeed
const searchEpisode = function(ep_num, message) {
	let episode_data = data_JSON.rss.channel[0].item;

	for (let i in episode_data) {
		if (episode_data[i].title[0].startsWith(`#${ep_num}`)) {
			message.channel.send(episode_data[i].link);
			return;
		}
	}
	message.channel.send(`Could not find episode #${ep_num}. Please check to make sure the episode is in the RSS feed.`);
};

// handles users setting their own role
const setRole = function(message) {

  //only allow function in proper channel
	if (message.channel != legendarium_bot_spam) return;

  // replace all apostraphes with a standard one
  let regex = /[‘'’]/g;
  let args = message.content.substring(ROLE_PREFIX.length);
	args = args.replace(regex,"'");

  // process command and split into array
  args = args.split(" ").filter(arg => arg != '');
	console.log(`setRole attempted: ${args}`);

	let admin = false;
	let addRole;
	let desired_role;

  // based on command:
	switch (args[0]) {

    // lists roles users can give themselves
		case "roles":
		case "list":
		let list = ":\n__**Panelist Tags:**__\n";
		for (let role in VANITY_ROLES) {
			list += VANITY_ROLES[role] + "\n"
		}
		list += "__**Alert Roles:**__\n";
		for (let role in ALERT_ROLES) {
			list += ALERT_ROLES[role] + "\n";
		}
		message.channel.send(list);
		return;

    // lets user set their own role
		case "iam":
		desired_role =  args.splice(1).join(" ");
		addRole = true;
		break;

    // lets admin set another users role
		case "sr":
		console.log(message.author.id == rabbit.id);
		if(!message.author.roles.some(role=>ADMIN_ROLES.includes(role.name)) && message.author.id != rabbit.id) {
			console.log("no permission");
			return;
		}
		admin = true;
		addRole = true;
		desired_role =  args.splice(2).join(" ");

		break;

    // lets user remove a role from themselves
		case "iamn":
		case "iamnot":
		desired_role =  args.splice(1).join(" ");
		addRole = false;

		break;

    // lets admin remove another users role
		case "rr":
		if(!message.author.roles.some(role=>ADMIN_ROLES.includes(role.name)) && message.author.id != rabbit.id) {
			console.log("no permission");
			return;
		}
		admin = true;
		addRole = false;
		desired_role =  args.splice(2).join(" ");

		break;

		//NOT USED - will post a list of the bot's commands
		// case "help":
		// default:
		//
		//
		// return;
		// break;
	}

  // finds the desired role in the server's data
	let role = message.guild.roles.find(role => role.name === desired_role);

  // checks to make sure the role exists
	if (!role) return message.channel.send("The desired role does not exist, try checking spelling and capitalization. Use `.roles` for a list of roles you can assign yourself.");

	let user;
  // if not an admin, grab the users data from the message they sent, and confirm they have permision to set that role
	if (!admin) {
		if (!VANITY_ROLES.includes(desired_role) && !ALERT_ROLES.includes(desired_role)) {
			message.channel.send("You do not have permission to change that role");
			return;
		}
		user = message.member;

	} // if an admin using set/remove role, grab the user they mentioned in the message
  else {
		user = message.mentions.users.first();
	}

  // add the role to the user
	if (addRole) {
 		if (user.roles.some(role => role.name === desired_role)) {
			return message.channel.send("User already has this role.");
		}

		user.addRole(role).then(message.channel.send("Added role to user.")).catch(console.error);

	} // remove the role from the user
  else {
		if (!user.roles.some(role => role.name === desired_role)) {
			return message.channel.send("User already doesn't have this role.");
		}

		user.removeRole(role).then(message.channel.send("Removed role from user.")).catch(console.error);
	}

}
