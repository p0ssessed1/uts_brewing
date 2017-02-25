/*
	uts_wifi.cpp - Library for wifi setup & Exec
*/
#include "Arduino.h"
#include "uts_wifi.h"

char *_ssid;
char *_pass;


int uts_wifi::uts_wifi_setup()
{
  int status = WL_IDLE_STATUS;

  // attempt to connect using WPA2 encryption:
  status = WiFi.begin(_ssid, _pass);

  return status;
}

uts_wifi::uts_wifi(char* ssid, char* password){
		_ssid = ssid;
		_password=password;
}	
