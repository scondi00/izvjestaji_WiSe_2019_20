// pin definitions
int ledPin = 13;
int buttonPin = 2;

// global variables
byte pinState = LOW;

void setup () {
 // setup pin modes
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), glow, CHANGE);

}

void loop() {
  //glow();
  delay(10000);
  
}

void glow(){
 //int buttonState = digitalRead(buttonPin);
 //if (buttonState > 0){
   digitalWrite(ledPin, pinState);
   pinState = !pinState;
 //}
 //delay(100);

}