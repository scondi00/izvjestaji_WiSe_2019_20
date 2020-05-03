#include <LowPower.h>
#include "Sensors.h"

SENSORS sensors;

typedef enum{
  READ_SERIAL,
  BLINK_LED,
  READ_SENSORS,
  SLEEP_STATE,
  RADIO_COMM,
  NUM_STATES
}StateType;

StateType state = READ_SERIAL;
//---------------------------//

void blink(){

}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),blink,RISING);
  sensors.DHT_init();
  sensors.BH1750_init();
}

void loop() {


switch(state){
  case READ_SERIAL:
 
    state = READ_SENSORS;
    break;
    case READ_SENSORS:
      sensors.readTempHum();
      sensors.readLight();
    state = RADIO_COMM;
    break;
    case RADIO_COMM:
    state = SLEEP_STATE;
    break;
    case SLEEP_STATE:

delay(50);
LowPower.powerDown(SLEEP_8S,ADC_OFF,BOD_OFF);
delay(50);
  
  state = READ_SERIAL;
    break;
  
    

  }
}