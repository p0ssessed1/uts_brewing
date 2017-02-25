/* 
	uts_wifi.h
	Setup library for uts thermistor
	
*/
	
#ifndef UTS_WIFI_H
#define UTS_WIFI_H

#include "Arduino.h"
#include <Wifi.h>

#define MAX_WPA_PASS_NUM (12)
#define MAX_SSID_NUM (10)
class uts_wifi
{
	public:
		uts_wifi(char *ssid, char *password);
		int uts_wifi_setup();	
	private:
		char *_ssid;
		char *_password;
};

#endif /* UTS_WIFI_H */
