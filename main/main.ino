#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>


#include "uts_wifi.h"

char ssid[] = "SSID";
char pass[] = "PassWord";
int thermistor = 2;
int heatbelt = 4;
double Vt;
double R2=10;
double T;
unsigned long startime=0;
unsigned long stoptime=0;
unsigned long ontime=0;
void setup() {
  pinMode (thermistor, INPUT);
  pinMode (heatbelt, OUTPUT);
  // initialize serial:
  Serial.begin(9600);
  uts_wifi wifi = uts_wifi(ssid,pass);
  if(WL_CONNECTED != wifi.uts_wifi_setup()) {
    Serial.println("Error connecting to WiFi");
  }

}

void loop() {
 /*Equation for the temp to R:
  T = 62.433*e^(0.091*R [kOhm])
  Vt = V(R2/(Rt + R2))
  =>V=5v
  Rt= R2(5/Vt - 1)
  T= 62.433* e^(0.091*(R2(5/Vt-1))
*/ 
 Vt=analogRead(thermistor);
 T=62.433*(pow(2.7182,(-0.091*(R2*((5/Vt)-1)))));
  if (bitRead(PORTD,heatbelt) == HIGH)
    {
      if (T>20)
        {
          digitalWrite(heatbelt, LOW);
          stoptime=millis();
        }
      
    }
  else if (digitalRead(T<17))
    {
      digitalWrite(heatbelt, HIGH);
      startime = millis();
    }
//ontime = ontime + (stoptime-startime);  


 delay(300000);    
}
