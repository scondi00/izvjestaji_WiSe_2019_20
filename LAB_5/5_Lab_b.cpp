#include "Sensors.h"
#include<LowPower.h>

SENSORS sensors;

void setup() {
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.BH1750_init();
  
}

void loop() {
  sensors.readTempHum();
  sensors.readLight();

  delay(50);

  int i =0;
  while(i<8){
     LowPower.powerDown(SLEEP_8S,ADC_OFF,BOD_OFF); 
     i+=1;
  }
  
  delay(50);

}