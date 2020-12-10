#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


/// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Lm3xb6IQkesmM9AJYBkQN1vwPMYOo9Ud";


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "2P net";
char pass[] = "Sirs@k2p";

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
