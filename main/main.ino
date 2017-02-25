int thermistor = 2;
int heatbelt = 4;
unsigned long startime=0;
unsigned long stoptime=0;
unsigned long ontime=0;
void setup() {
  // put your setup code here, to run once:
  pinmode (thermistor, INPUT);
  pinmode (heatbelt, OUTPUT);
}

void loop() {
 
  if (bitRead(PORTD,heatbelt) == HIGH)
    {
      if (digitalRead(thermistor)>20)
        {
          digitalWrite(heatbelt, LOW);
          stoptime=millis();
        }
      
    }
  else if (digitalREAD(thermistor)<17)
    {
      digitalWrite(heatbelt, HIGH);
      startime = millis();
    }
   
 ontime = ontime + (stoptime-startime);  
 delay(300000);    
}
