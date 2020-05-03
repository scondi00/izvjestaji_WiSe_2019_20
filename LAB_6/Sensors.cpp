#include "Sensors.h"

DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter(0x23);

SENSORS::SENSORS(){}
SENSORS::~SENSORS(){}

void SENSORS::DHT_init(){
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void SENSORS::BH1750_init(){
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  Serial.println(F("BH1750 Test"));
}