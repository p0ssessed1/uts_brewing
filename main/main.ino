#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include "uts_wifi.h"

#define R2 (10)
#define PIN_THERMISTOR (2)
#define PIN_HEATBELT (4)
#define ENTER_CHARACTER (0xD)

char ssid[MAX_SSID_NUM] = "SSID";
char pass[MAX_WPA_PASS_NUM] = "PassWord";
double Vt;
double T;
unsigned long startime=0;
unsigned long stoptime=0;
unsigned long ontime=0;


void setup() {
  // initialize serial:
  String ssid_string;
  String pass_string;
  Serial.begin(9600);

  /* Wait for user input of SSID and Password. */
  Serial.print("Input SSID: ");
  ssid_string = Serial.readStringUntil(ENTER_CHARACTER);
  Serial.println("");
  Serial.print("Input Password: ");
  pass_string = Serial.readStringUntil(ENTER_CHARACTER);
  ssid_string.toCharArray(ssid,MAX_SSID_NUM);
  pass_string.toCharArray(pass,MAX_WPA_PASS_NUM);

  uts_wifi wifi = uts_wifi(ssid,pass);
  if(WL_CONNECTED != wifi.uts_wifi_setup()) {
    Serial.println("Error connecting to WiFi");
  }

  pinMode (PIN_THERMISTOR, INPUT);
  pinMode (PIN_HEATBELT, OUTPUT);

}


void loop() {
 /*Equation for the temp to R:
  T = 62.433*e^(-0.091*R [kOhm])
  Vt = V(R2/(Rt + R2))
  =>V=5v
  Rt= R2(5/Vt - 1)
  T= 62.433* e^(-0.091*(R2(5/Vt-1))
*/ 
  Vt=analogRead(PIN_THERMISTOR);
  T=62.433*(pow(2.7182,(-0.091*(R2*((5/Vt)-1)))));

  if (bitRead(PORTD,PIN_HEATBELT) == HIGH) {
    if (T>20) {
      digitalWrite(PIN_HEATBELT, LOW);
      stoptime=millis();
//ontime += (stoptime-startime);  
    }   
  }
  else if (digitalRead(T<17)) {
    digitalWrite(PIN_HEATBELT, HIGH);
    startime = millis();
  }


 delay(300000);    
}
