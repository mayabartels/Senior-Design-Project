/* BIM 110 - UC Davis Senior Design 
  authors: Deesha Patel, Maya Bartels */

//initialize variables
const int redLED_pin = 11;
const int IRLED_pin = 10;
const int Button_pin = 9;

bool buttonPressed = false;

int buttonState = 0;

void startMeasurement(){
  //redLED light
  digitalWrite(redLED_pin, HIGH);
  delay(1000);
  digitalWrite(redLED_pin, LOW);
  delay(1000);

  //photodiode red
  
  //IRLED light
  digitalWrite(IRLED_pin, HIGH);
  delay (1000);
  digitalWrite(IRLED_pin, LOW);
  delay (1000);

  //photodiode IR

  buttonPressed = false; //reset button pressed state to default
}

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED_pin, OUTPUT);
  pinMode(IRLED_pin, OUTPUT);
  pinMode(Button_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //button on or off
  buttonState = digitalRead(buttonPin);

  //detect if button has been pressed
  if (buttonState  == HIGH) {
    buttonPressed = true;
  } else {
  }

  //only run when button is pressed
  if buttonPressed {
    startMeasurement();
  } else {
  }
}
