#include <Arduino.h>
#include <avr/wdt.h>



void setup() {
  Serial.begin(9600);
  Serial.println("hello setup");
  //initialize digital pin LED_BUILTIN as output
  pinMode(LED_BUILTIN,OUTPUT);

  //watchdog timer function runs over and over again forever
  wdt_enable(WDTO_2S);
}

void loop() {
  Serial.println("hello loop");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);


  wdt_reset();
}