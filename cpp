#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  
  
  float t = dht.readTemperature();


  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.println(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));


  if (t>25) {
    tone(4, 523, 1000); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(13, LOW);
    digitalWrite(4, LOW);
  }
  delay(100);

 }
