const websocket = require("ws")
var serialP = require('serialport');

/*
serialP.list(function(err, ports){
	if(err)return "cannot read serial port";
	ports.forEach(function(port){
		console.log(port);
	});
});
*/

var myPort = new serialP("COM22", {baudRate:9600}, function(err){
	if(err)
		console.log(err.message)
});

var parser = new serialP.parsers.Readline();
myPort.pipe(parser);

myPort.on('open', function(){
	console.log("port opened");
});




parser.on('data', function(data){
	//console.log(data)
});

var wss = new websocket.Server({port:8080})

var led = "off";
console.log(led)
wss.on("connection", (ws)=>{
	console.log("incoming connection");
	ws.on("message", (m)=>{
		console.log(m);
		myPort.write(m);
	})
})