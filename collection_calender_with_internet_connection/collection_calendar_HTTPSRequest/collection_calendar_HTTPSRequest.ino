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

//#define DEBUG; //comment out to disable Serial prints

#ifdef DEBUG 
 #define DEBUG_PRINT(x)       Serial.print(x)
 #define DEBUG_PRINTDEC(x)    Serial.print(x, DEC)
 #define DEBUG_PRINTLN(x)     Serial.println(x)
#else
 #define DEBUG_PRINT(x)
 #define DEBUG_PRINTDEC(x)
 #define DEBUG_PRINTLN(x) 
#endif

const char* ssid = "CP";
const char* password = "ChristianPetri1988";

const char* host = "www.collectioncalendar.christianpetri.ch";
const int httpsPort = 443;
String url = "/plaintext/?circle_id=5";

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
//const char* fingerprint = "8e 99 24 7e 5f 65 42 c4 ac 5c 9a ec 1c 15 83 5b f2 d4 5b 78";
const char* fingerprint = "da c9 02 4f 54 d8 f6 df 94 93 5f b1 73 26 38 ca 6a d7 7c 13"; //root certificate --> until 2021

//Setup LED
const int ledPin[5] = {D8, D0, D5, D6, D7}; 
const int connectedToApiStatusLedPin = LED_BUILTIN; //on = HIGH = successful off = LOW = not connected

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 60000;        // will store last time LED was updated

// constants won't change:
const long interval = 60000;           // interval at which to blink (milliseconds) --> 60000 ms = 1 minute

void setup() {
  // set the digital pin as output: 
  for(int i = 0; i < (sizeof(ledPin)/sizeof(int)); i++){
    pinMode(ledPin[i], OUTPUT); 
  }
  pinMode(connectedToApiStatusLedPin, OUTPUT);
  digitalWrite(connectedToApiStatusLedPin,LOW); 
  #ifdef DEBUG
    Serial.begin(115200);
  #endif
  DEBUG_PRINTLN();
  DEBUG_PRINT("connecting to ");
  DEBUG_PRINTLN(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    DEBUG_PRINT(".");
  }
  DEBUG_PRINTLN("");
  DEBUG_PRINTLN("WiFi connected");
  DEBUG_PRINTLN("IP address: ");
  DEBUG_PRINTLN(WiFi.localIP());
}

// here is where you'd put code that needs to be running all the time.
void loop() { 
  //every interval get the Data from the API and display it.
  if (isIntervalDone()) { 
    int apiResponse = getDataFromAPI(); 
    if(apiResponse != -1){ //if the reponse was success full, display data
      displayData(apiResponse);
      digitalWrite(connectedToApiStatusLedPin, HIGH); //Turn LED on
    } else {
      digitalWrite(connectedToApiStatusLedPin, LOW);  //Turn LED off
    } 
  } 
}
boolean isIntervalDone(){
  if (millis() - previousMillis >= interval) {
    previousMillis = millis(); 
    return true;
  } else{
    return false;
  }
}

int getDataFromAPI(){ 
    // Use WiFiClientSecure class to create TLS connection
    WiFiClientSecure client;
    DEBUG_PRINT("connecting to ");
    DEBUG_PRINTLN(host);
    if (!client.connect(host, httpsPort)) {
      DEBUG_PRINTLN("connection failed"); 
      return -1;
    } 
    if (client.verify(fingerprint, host)) {
      DEBUG_PRINTLN("certificate matches");
    } else {
      DEBUG_PRINTLN("certificate doesn't match");
    }  
    DEBUG_PRINT("requesting URL: ");
    DEBUG_PRINTLN(url);
  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "User-Agent: ESP8266\r\n" +
                 "Connection: close\r\n\r\n"); 
                 
    DEBUG_PRINTLN("request sent");
    int counter = 0;
    while (client.connected()) {
      counter++;
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        DEBUG_PRINTLN("headers received");
        break;
      }
      if(counter > 10000){
        DEBUG_PRINTLN("Time out");
        return -1;
      }
    }
    
    String line = client.readStringUntil('\n');  
    //now output HTML data header
    client.println("HTTP/1.1 204");
    client.println();
    client.println();
    delay(1);
    //stopping client
    DEBUG_PRINTLN("closing connection");
    client.stop();
    int result = line.toInt();
    return result; 
}

void displayData(int apiResponse){
    int result = apiResponse;
    DEBUG_PRINTLN("reply was:");
    DEBUG_PRINTLN("==========");
    DEBUG_PRINTLN(result); 
    DEBUG_PRINTLN("=========="); 
    //Turn off all status leds
    for(int i = 0; i < (sizeof(ledPin)/sizeof(int)); i++){
      digitalWrite(ledPin[i], LOW); 
    } 
    if(result == 100000){
      DEBUG_PRINTLN("Nothing to do");
    } else {
      if( (result / 10000) % 10  == 1){
        DEBUG_PRINTLN("1");
        digitalWrite(ledPin[0], HIGH);
      } 
      if( (result / 1000) % 10  == 1){
        DEBUG_PRINTLN("2");
        digitalWrite(ledPin[1], HIGH);
      } 
      if( (result / 100) % 10  == 1){
        DEBUG_PRINTLN("3");
        digitalWrite(ledPin[2], HIGH);
      } 
      if( (result / 10) % 10  == 1){
        DEBUG_PRINTLN("4");
        digitalWrite(ledPin[3], HIGH);
      } 
      if( result % 10  == 1){
        DEBUG_PRINTLN("5");
        digitalWrite(ledPin[4], HIGH);
      } 
    }
    #ifdef DEBUG
      Serial.flush();
    #endif
   
}

