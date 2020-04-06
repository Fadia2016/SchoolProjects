var weather;

var api = 'http://api.openweathermap.org/data/2.5/weather?q=';
var apiKey = '&APPID=f844636e8d55a17a12ed525bee1cd278';
var units = '&units=metric';
var input;
function setup(){
	createCanvas(400,200);

	var button = select('#submit');
	button.mousePressed(weatherAsk);
	input= select('#city');
}
function weatherAsk(){

	var url = api+input.value()+apiKey+units;
	loadJSON(url,gotData);
}

function gotData(data){
	weather = data;
	var temp = Math.floor(weather.main.temp);
	var wea = weather.weather[0].main;
	var description	= weather.weather[0].description;
	var cityName= weather.name;
	
	//var icon= "http://openweathermap.org/img/w/"+data.weather[0].icon+".png";
	
	document.getElementById("temp").innerHTML ="The Temperature in celsius is:  "+temp;
	document.getElementById("weather").innerHTML ="The weather is:  " +wea;
	document.getElementById("description").innerHTML ="The description of the weather is  :  " + description;
	document.getElementById("cityname").innerHTML = "The name of the City is:  " + cityName;

}
