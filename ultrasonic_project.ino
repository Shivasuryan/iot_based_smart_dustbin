#include"ThingSpeak.h"
#include<ESP8266WiFi.h>
//----------enter your wifi details----//
char ssid[]="OnePlus 7";
char pass[]="Shiva12345";
//--------------------//


const int trigger = 11;
const int echo = 12;
long T;
float distanceCM;
WiFiClient  client;

unsigned long myChannelField=872815;//channel id
const int ChannelField=1;//which fields
const char * myWriteAPIKey ="SNAFXXFV1CUDCGZ0";//write api key

void setup()
{
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop()
{Serial.print("Distance in cm: ");
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = T * 0.034;
  distanceCM = distanceCM / 2;
  Serial.print("Distance in cm: ");
  Serial.println(distanceCM);
  ThingSpeak.writeField(myChannelField, ChannelField, distanceCM, myWriteAPIKey);
  delay(1000);
}
