/*
 * Arduino Workshop - Digipurk, ylari[at]digipurk.ee
 * Lab - Pump
 */
#include <Arduino.h>

#define SENSOR A1
#define RELAY A5

#define LEVEL 60

void setup() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
  Serial.begin(9600);
}

void loop() {
  float moisture = (100 - ((analogRead(SENSOR) / 1023.00) * 100));
  Serial.print(moisture);
  Serial.println(" %");
  if (moisture < LEVEL) {
    digitalWrite(RELAY, LOW);
  } else {
    digitalWrite(RELAY, HIGH);
  }
  delay(1000);
}
