#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "SmawiKmb7SDY8ido8DIZEvrRH01iVzwv"; //token dari Blynk
char ssid[] = "D-Link_DIR"; //User hostspot dari hp nya masing masing
char pass[] = "abcde1234"; //Password dari  hostpot

WidgetLED led1(V1);


int sensor1 = D1;


void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  
  pinMode(sensor1,INPUT);

  while (Blynk.connect() == false) {
  }
}

void loop() {
  int sensorval1 = digitalRead(sensor1);
 
  Serial.println(sensorval1);
  
  delay(1000);
  
    if (sensorval1 == 1)
    {
  led1.on();
  }


    if (sensorval1 == 0)
    {
  led1.off();
  }
 
  Blynk.run();
}
