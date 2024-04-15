/* BIM 110 - UC Davis Senior Design */

//initialize variables
const int redPin = 11;
const int IRPin = 10;
const int buttonPin = 4;

int photodiodePinRed = A1; //red photodiode
int photodiodePinIR = A2; //IR photodiode

int buttonState = 0; //set initial button pressed state to false

void startMeasurement(){
  //red LED light
  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(redPin, LOW);
  delay(1000);

  //read voltage for red photodiode
  photodiodeRedValue = analogRead(photodiodePinRed);
  float voltagePhotodiodeRed = photodiodeRedValue * (3.3 / 1023); // 3.3 V / 1023 analog units
  Serial.println("Red Voltage: " + voltagePhotodiodeRed);
  
  //IRLED light
  digitalWrite(IRPin, HIGH);
  delay (1000);
  digitalWrite(IRPin, LOW);
  delay (1000);

  //read voltage for IR photodiode
  photodiodeIRValue = analogRead(photodiodePinIR);
  float voltagePhotodiodeIR = photodiodeIRValue * (3.3 / 1023); // 3.3 V / 1023 analog units
  Serial.println("IR Votage: " + voltagePhotodiodeIR);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin();

  //initialize LEDs
  pinMode(redPin, OUTPUT);
  pinMode(IRPin, OUTPUT);

  //initialize Button
  pinMode(buttonPin, INPUT);

  //initialize Photodiodes
  pinMode(photodiodePinRed, INPUT);
  pinMode(photodiodePinIR, INPUT);
}

void loop() {
  //button on or off
  buttonState = digitalRead(buttonPin);

  //detect if button has been pressed, then start the pH measurement
  if (buttonState == HIGH) {
    startMeasurement();
  } else {
  }
}
