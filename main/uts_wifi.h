/* 
	uts_wifi.h
	Setup library for uts thermistor
	
*/
	
#ifndef uts_wifi_h
#define uts_wifi_h

#include "Arduino.h"
#include <Wifi.h>

class uts_wifi
{
	public:
		uts_wifi(string ssid, string password);
		int uts_wifi_setup();	
	private:
		string _ssid;
		string _password;
			
		
};


