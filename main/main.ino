#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include "uts_wifi.h"

char ssid[] = "SSID";
char pass[] = "PassWord";

void setup() {
  // put your setup code here, to run once:
  // initialize serial:
  Serial.begin(9600);
  uts_wifi wifi = uts_wifi(ssid,pass);

  if(WL_CONNECTED != wifi.uts_wifi_setup()) {
    Serial.println("Error connecting to WiFi");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
