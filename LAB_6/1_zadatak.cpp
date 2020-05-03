#include <Arduino.h>

#include <LowPower.h>
void setup() {
  
}

void loop() {
    delay(100000);
    LowPower.powerDown(SLEEP_FOREVER,ADC_OFF,BOD_OFF);
 
}