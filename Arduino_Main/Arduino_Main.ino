/* BIM 110 - UC Davis Senior Design 
  authors: Deesha Patel, Maya Bartels */

//initialize variables
const int redPin = 11;
const int IRPin = 10;
const int buttonPin = 4;

int buttonState = 0;

void startMeasurement(){
  //redLED light
  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(redPin, LOW);
  delay(1000);

  //photodiode red
  
  //IRLED light
  digitalWrite(IRPin, HIGH);
  delay (1000);
  digitalWrite(IRPin, LOW);
  delay (1000);

  //photodiode IR
}

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(IRPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  //button on or off
  buttonState = digitalRead(buttonPin);

  //detect if button has been pressed
  if (buttonState == HIGH) {
    startMeasurement();
  } else {
  }
}
