/*
	uts_wifi.cpp - Library for wifi setup & Exec
*/
#include "Arduino.h"
#include "uts_wifi.h"

int uts_wifi::uts_wifi_setup()
{
	// initialize serial:
	  Serial.begin(9600);

	  // attempt to connect using WPA2 encryption:
	  Serial.println("Attempting to connect to WPA network...");
	  status = WiFi.begin(_ssid, _pass);

	  // if you're not connected, stop here:
	  if ( status != WL_CONNECTED) { 
		Serial.println("Couldn't get a wifi connection");
		while(true);
	  } 
	  // if you are connected, print out info about the connection:
	  else {
		Serial.println("Connected to network");
	  }
}

uts_wifi::uts_wifi(string ssid, string password){
		_ssid=ssid;
		_password=password;
		
	}	