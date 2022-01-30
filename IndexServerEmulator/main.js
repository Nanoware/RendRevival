const express = require('express');
const app = express();
const dgram = require('dgram');
const udpclient = dgram.createSocket('udp4');
const { Pool } = require('pg');
const pool = new Pool({
  connectionString: (process.env.DATABASE_URL || "postgres://qawibafazghqkc:cfd06118864d938c5b0ea37fbc8f5f3b40c951562c7b7be4b494ec7e362e34f8@ec2-34-255-134-200.eu-west-1.compute.amazonaws.com:5432/daf15h1i001itj"),
  ssl: {
    rejectUnauthorized: false
  }
});
const somebytes = Buffer.from('a');

var client;

async function startDB() {
	try {
		console.log('Connecting to DB');
		client = await pool.connect();
		console.log('Conencted to DB!');
		const result = await client.query('CREATE TABLE IF NOT EXISTS servers (server_unique_id TEXT NOT NULL, server_id TEXT NOT NULL, ip TEXT NOT NULL, port int NOT NULL, properties TEXT NOT NULL, updated int NOT NULL)');
		
		console.log('Created table!');
	} catch (err) {
      console.error(err);
    }
}
startDB()


app.use(express.json());

app.get('/', function (req, res) {
  res.send('OwO')
})


function getTime(){
	return Math.round(new Date().getTime()/1000)
}

const static_update_response = {
	"Pending": [],
	"Queue": [],
	"Time": 1632083347,
	"Commands": []
}

function makeid(length) {
    var result           = '';
    var characters       = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    var charactersLength = characters.length;
    for ( var i = 0; i < length; i++ ) {
      result += characters.charAt(Math.floor(Math.random() * 
 charactersLength));
   }
   return result;
}

app.put('/update/:server_uid', async (req, res) => {
	var server_uid = req.params.server_uid
	var myquery = await client.query('SELECT * FROM servers WHERE server_unique_id=$1', [server_uid]);
	if (myquery.rowCount < 1) {
		res.send({"SUCCESS": false, "ERROR": "Invalid server uid:"+server_uid})
	} else if (myquery.rowCount > 1) {
		res.send({"SUCCESS": false, "ERROR": "Found more than one server with uid:"+server_uid})
	} else {
		var store_properties = JSON.parse(myquery.rows[0].properties)
		Object.assign(store_properties, req.body.properties)
		//console.log(store_properties)
		client.query('UPDATE servers SET properties=$1, updated=$2 WHERE server_unique_id=$3',
		[JSON.stringify(store_properties), getTime(), server_uid], (err, qres) => {
			if (err) {
				console.log(err.stack)
				res.send({"SUCCESS": false})
			} else {
				res.send(static_update_response)
				console.log("Updated server "+server_uid)
			}
		})
	}
})

app.post('/register', async (req, res) => {
	var data = req.body

	var server_id = data.id
	var server_port = data.port
	var server_properties = data.properties

	var ipAddr = req.headers["x-forwarded-for"];
	if (ipAddr){
		var list = ipAddr.split(",");
		ipAddr = list[list.length-1];
	} else {
		ipAddr = "127.0.0.1";
	}
	
	if (server_id == "Test"){
		server_id = ipAddr
	}

	var result = await client.query('SELECT * FROM servers WHERE ip=$1', [ipAddr]);
	
	if (result.rowCount >= 1) {
		client.query('UPDATE servers SET server_id=$1, port=$2, properties=$3, updated=$4 WHERE ip=$5',
		[server_id, server_port, JSON.stringify(server_properties), getTime(), ipAddr], (err, qres) => {
			if (err) {
				console.log(err.stack)
				res.send({"SUCCESS": false})
			} else {
				var uid = result.rows[0].server_unique_id
				res.send({"SUCCESS": true, "ID": uid, "Shard": "1", "PublicKey": "1"})
				console.log("Updated server "+uid)
			}
		})
	} else {
		var uid = server_id + "_" + makeid(5)
		client.query('INSERT INTO servers(server_unique_id, server_id, ip, port, properties, updated) VALUES($1, $2, $3, $4, $5, $6)',
		[uid, server_id, ipAddr, server_port, JSON.stringify(server_properties), getTime()], (err, qres) => {
			if (err) {
				console.log(err.stack)
				res.send({"SUCCESS": false})
			} else {
				res.send({"SUCCESS": true, "ID": uid, "Shard": "1", "PublicKey": "1"})
				console.log("Registered server")
			}
		})
	}
})

app.post('/test', async (req, res) => {
	var result = await client.query('SELECT * FROM servers');
	console.log(result)
})

const static_auth_response = {
	"Tickets": [
		{
			"private" : "79\nmg4E7Wmhe3Zcb1JmfRGy2dfgiFlxdMxn\n1632701837\n6ldZ+u9bYmL69GSrHBgw2z5opJ6lnoUPDwEpiD5MWYs4wICOissGXU3+yI4eAc5gwVGPAKIZUM6pnWpBeUlW87AUFJPsd/Z9iwGaQq2OUxSnaZUlzz52+4TlhlKcru8="
		}
	]
}

app.post('/auth', async (req, res) => {
	res.send(static_auth_response)
})

app.get('/ping', async (req, res) => {
	var ipAddr = req.headers["x-forwarded-for"];
	udpclient.send(somebytes,15001,ipAddr,function(error){
	  if(error){
		console.log('err');
		udpclient.close();
	  }else{
		console.log('Data sent !!!');
	  }
	})
})

var portCheckData = {}

function checkPort(ip, port, callback, callbackError){
	portCheckData[ip + ":" + port] = callback
	console.log("Checking UDP port: " + ip +":"+port)
	udpclient.send(somebytes,port,ip)
}

udpclient.on('message',function(msg,info){
  console.log('Data received from server : ' + msg.toString());
  console.log('Received %d bytes from %s:%d\n',msg.length, info.address, info.port);
  var clbck = portCheckData[info.address + ":" + info.port]

  if (clbck) {
	  clbck()
  }
})

function successPing(){
	console.log("SUCC")
	udpclient.close()
}

//checkPort("127.0.0.1", 15001, successPing)

const server_template = {
	"version": "1.0.167.14711",
	"allowQueue": true,
	"key": "KqQUBz3jwjUMVKRJb2XmdXdVD/CEb0iXUrZH+vmomRc=",
	"packet": "{}",
	"overwrite": false,
	"ticketType": "official",
	"shard": "1",
}

var dbg_test = false
var show_info_server = false

app.get('/list', async (req, res) => {
	var result = await client.query('SELECT * FROM servers');
	
	var response = { "Servers":[] }
	
	
	if (show_info_server)
	{
		for (let i = 0; i < 4; i++) {
			let tmp = Object.assign({}, server_template);
			tmp.id = "INFO_TEMPLATE" + i.toString()
			tmp.Ip = "0.0.0.0"
			tmp.port = 1
			tmp.updated = getTime()
			tmp.properties = {
				"ServerName" : "IMPORTANT: Information on how to play rend available at discord.com/invite/ybmZeuG",
				"ServerGameMode": i.toString(),
			}
			response.Servers.push(tmp)
		}
	}
	
	
	for (const element of result.rows) {
		//console.log(element);
		if (dbg_test || getTime() - element.updated < 300)
		{
			let p2 = Object.assign({}, server_template);
			p2.id = element.server_id
			p2.Ip = element.ip
			p2.port = element.port
			p2.updated = element.updated
			p2.properties = JSON.parse(element.properties)
			response.Servers.push(p2)
		}
	}
	

	res.send(response)
	//console.log(response)
})

var port = (process.env.PORT || 80)
app.listen(port)

console.log("Running on port " + port)