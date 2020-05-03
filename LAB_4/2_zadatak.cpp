int ledPinB = 13;       // the number of the LED pin
long OnTimeB = 200;     // milliseconds of on-time
long OffTimeB = 500;    // milliseconds of off-time

int ledStateB = LOW;             		// ledState used to set the LED
unsigned long previousMillisB = 0;  	// will store last time LED was updated


class  Falsher{
  int ledPinB;       // the number of the LED pin
long OnTimeB;     // milliseconds of on-time
long OffTimeB;    // milliseconds of off-time

int ledStateB;             		// ledState used to set the LED
unsigned long previousMillisB = 0;  	// will store last time LED was updated

public:
  Falsher(int pin, long ontime,long offtime){
  ledPinB=pin;
    OnTimeB=ontime;
    OffTimeB=offtime;
    ledStateB=LOW;
  	previousMillisB=0;
  }
 void Update(long currentMillis){
      if((ledStateB == HIGH) && (currentMillis - previousMillisB >= OnTimeB)){
      ledStateB = LOW;  // Turn it off
      previousMillisB = currentMillis;  // Remember the time
      digitalWrite(ledPinB, ledStateB);  // Update the actual LED
    }
    else if ((ledStateB == LOW) && (currentMillis - previousMillisB >= OffTimeB)){
      ledStateB = HIGH;  // turn it on
      previousMillisB = currentMillis;   // Remember the time
      digitalWrite(ledPinB, ledStateB);	  // Update the actual LED
    }

  }
};

Falsher ledB(13,100,200);
Falsher ledR(12,340,126);
Falsher ledO(11,480,600);

void setup(){
   
  OCR0A = 0xAF;
TIMSK0 |= _BV(OCIE0A);
}

void loop(){
	delay(1000);
}
 
SIGNAL(TIMER0_COMPA_vect){
  unsigned long currentMillis = millis();
  
  ledB.Update(currentMillis);
  ledR.Update(currentMillis);
  ledO.Update(currentMillis);
  
  }