#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "DHT.h"
#include "html.h"

const char* WIFI_SSID = "SSID";
const char* WIFI_PASSWORD = "PASSWORD";
const char* DNS_NAME = "growtracker"; // im browser über locales netzwerk http://growtracker.local

const char* API_POST_URL = "https://growtracker.io/api/data-entries";
const char* API_TOKEN = "TOKEN";
const char* CHIP_ID_KEY = "12345"; // UNIQUE KEY FOR THIS CHIP ONLY

const int NUMBER_OF_SOIL_SENSORS = 8; // MAX 8
const int MAP_TOP_ANALOG_VALUE = 300; // 100%
const int MAP_BOTTOM_ANALOG_VALUE = 640; // 0%

#define DHTPin D1
#define DHTTYPE DHT22

DHT dht(DHTPin, DHTTYPE);

ESP8266WebServer server(80);

// the setup function runs once when you press reset or power the board
void setup() {
  initESP();
  initWiFi();
  initDNS();
  initWebServer();
}

// the loop function runs over and over again forever
void loop() {
  MDNS.update();
  server.handleClient();

  if(Serial.available()){
    String input = Serial.readString();
    input.trim();

    String payload = getApiPayload(input);

    sendApiPostRequest(payload);
  }
}

int getAnalogData(int number){

  delay(1);

  if(number <= 0 || number > 8){
    digitalWrite(D5,0);
    digitalWrite(D6,0);
    digitalWrite(D7,0);
    return 0;
  }

  if(number % 2 == 0){
    digitalWrite(D5,1);
  } else {
    digitalWrite(D5,0);
  }

  if(number == 3 || number == 4 || number == 7 || number == 8){
    digitalWrite(D6,1);
  } else {
    digitalWrite(D6,0);
  }

  if(number > 4){
    digitalWrite(D7,1);
  } else {
    digitalWrite(D7,0);
  }

  delay(1);
  
  int value = analogRead(A0);
  int mappedValue = map(value, MAP_BOTTOM_ANALOG_VALUE, MAP_TOP_ANALOG_VALUE, 0, 100);

  if(mappedValue < 0){
    return 0;
  } else if(mappedValue > 100){
    return 100;
  } else {
    return mappedValue;
  }
}

String getSensorData() {
  String Temperature = "{\"type\": \"Temperature\", \"value\": "+String(dht.convertFtoC(dht.readTemperature(true)),1)+"}";
  String Humidity = "{\"type\": \"Humidity\", \"value\": "+String(dht.readHumidity(),1)+"}";

  String data = "\"data\": ["+Temperature+", "+Humidity;

  if(NUMBER_OF_SOIL_SENSORS > 0){
    data += ", {\"type\": \"Soil\", \"sensors\": [";
    for(int i = 1; i <= NUMBER_OF_SOIL_SENSORS; i++){
      if(i != 1){
        data += ", ";
      }
      data += "{\"number\": " + String(i) + ", \"value\": " + String(getAnalogData(i)) + "}";
    }
    data += "]}";
    // Reset digital pins
    getAnalogData(0);
  }

  return data+"]";
}

String getApiPayload(String input){
  return "{\"chipIdKey\": \""+String(CHIP_ID_KEY)+"\", \"message\": \""+input+"\", "+getSensorData()+"}";
}

void sendApiPostRequest(String payload){
  digitalWrite(LED_BUILTIN, LOW);

  HTTPClient http;
  WiFiClientSecure wfc;

  wfc.setInsecure();

  http.begin(wfc, API_POST_URL);
  http.addHeader("Content-Type", "application/json;charset=utf-8");
  http.addHeader("Accept", "application/json");
  http.addHeader("cache-control", "no-cache");
  http.addHeader("Authorization", "Bearer " + String(API_TOKEN));

  int httpCode = http.POST(payload);
  String response = http.getString();

  Serial.println(httpCode);
  Serial.println(response);

  http.end();

  digitalWrite(LED_BUILTIN, HIGH);
}

void indexHTML() {
  server.send(200, "text/html", PAGE_MAIN);
}

void responseSensorData() {
  server.send(200, "text/application-json", String("{"+getSensorData()+"}"));
}

// SETUP FUNCTIONS

void initESP(){
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // Controller pins for analog multiplexer
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(A0, INPUT);

  dht.begin();

  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.println("ESP Start");
}

void initWiFi(){
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("WLAN-Verbindung wird hergestellt ...");
  while (!WiFi.isConnected()){
    delay(500);
    Serial.print(".");
    //Serial.print(WiFi.status());
  }
  Serial.println();
  Serial.print("Verbunden mit ");
  Serial.println(WIFI_SSID);
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());
}

void initDNS(){
  if(MDNS.begin(DNS_NAME)){
    Serial.println("DNS gestartet!");
    Serial.print("Erreichbar unter http://");
    Serial.print(DNS_NAME);
    Serial.println(".local");
  }
}

void initWebServer(){
  server.onNotFound([]() {
    server.send(404, "text/plain", "Seite nicht gefunden!");
  });

  server.on("/", indexHTML);
  server.on("/sensorData", responseSensorData);

  server.begin();
}