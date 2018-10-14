/*
 *  HTTP over TLS (HTTPS) example sketch
 *
 *  This example demonstrates how to use
 *  WiFiClientSecure class to access HTTPS API.
 *  We fetch and display the status of
 *  esp8266/Arduino project continuous integration
 *  build.
 *
 *  Limitations:
 *    only RSA certificates
 *    no support of Perfect Forward Secrecy (PFS)
 *    TLSv1.2 is supported since version 2.4.0-rc1
 *
 *  Created by Ivan Grokhotkov, 2015.
 *  This example is in public domain.
 */

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "CP";
const char* password = "ChristianPetri1988";

const char* host = "www.collectioncalendar.christianpetri.ch";
const int httpsPort = 443;
String url = "/plaintext/?circle_id=5";

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char* fingerprint = "8e 99 24 7e 5f 65 42 c4 ac 5c 9a ec 1c 15 83 5b f2 d4 5b 78";

//Setup LED
const int led[5] = {D8, D0, D5, D6, D7};


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 60000;        // will store last time LED was updated

// constants won't change:
const long interval = 60000;           // interval at which to blink (milliseconds)


//Error Code
int error = 0;

void setup() {
  // set the digital pin as output: 
  for(int i = 0; i < 5; i++){
    pinMode(led[i], OUTPUT); 
  }
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

 
}

void loop() {

  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    error = 0;
      // save the last time you blinked the LED
      previousMillis = currentMillis; 
       // Use WiFiClientSecure class to create TLS connection
    WiFiClientSecure client;
    Serial.print("connecting to ");
    Serial.println(host);
    if (!client.connect(host, httpsPort)) {
      Serial.println("connection failed");
      error = 1;
      return;
    }
  
    if (client.verify(fingerprint, host)) {
      Serial.println("certificate matches");
    } else {
      Serial.println("certificate doesn't match");
    }
  
    
    Serial.print("requesting URL: ");
    Serial.println(url);
  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "User-Agent: ESP8266\r\n" +
                 "Connection: close\r\n\r\n");
  
    Serial.println("request sent");
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("headers received");
        break;
      }
    }
    String line = client.readStringUntil('\n');
    int result = line.toInt();
    Serial.println("reply was:");
    Serial.println("==========");
    Serial.println(line); 
    Serial.println("==========");
    Serial.println("closing connection");
    
    if(result == 100000){
      Serial.println("Nothing to do");
    } 

     for(int i = 0; i < 5; i++){
        digitalWrite(led[i], LOW); 
     } 
    if( (result / 10000) % 10  == 1){
      Serial.println("1");
      digitalWrite(led[0], HIGH);
    } 
    if( (result / 1000) % 10  == 1){
      Serial.println("2");
       digitalWrite(led[1], HIGH);
    } 
    if( (result / 100) % 10  == 1){
      Serial.println("3");
       digitalWrite(led[2], HIGH);
    } 
    if( (result / 10) % 10  == 1){
      Serial.println("4");
       digitalWrite(led[3], HIGH);
    } 
    if( result % 10  == 1){
      Serial.println("5");
       digitalWrite(led[4], HIGH);
    }
    
  }
  digitalWrite(LED_BUILTIN, error);
 
}
