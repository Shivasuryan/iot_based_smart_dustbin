#include"ThingSpeak.h"
#include<ESP8266WiFi.h>
//----------enter your wifi details------//
char ssid[]="";
char pass[]="";
//---------//


const int ldr='
int ldrVal=


void setup()
{
  
}

void loop()
{
  ldrVal=analogRead(ldr);

delay(1000);

}
const int trigPin = ; 
const int echoPin = ; 
long duration; 
int distance;

void setup() { 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
}

void loop() { 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
 distance = duration * 340 /20000; // The distance Variable will now contain the data gathered by the sensor. In this case the distance in CM.
 delay(1000); 
} 



void setup() { 
 Serial.begin(9600); 
}

void loop() {
 Serial.println(ldrVal); // Prints the ldrVal content to the Serial.Monitor.
 Serial.println(distance); // Prints the distance content to the Serial.Monitor. 
}

if (distance > 35)
  {
    digitalWrite(D3, HIGH);
    delay(500);
    digitalWrite(D3, LOW);
    delay(500);
  }
  else
  {
    digitalWrite(D3, LOW);
    delay(1000);
  }
 }
