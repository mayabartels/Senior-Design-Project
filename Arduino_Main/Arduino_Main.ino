/* BIM 110 - UC Davis Senior Design */

//initialize variables
const int redPin = 11;
const int IRPin = 10;
const int buttonPin = 4;

int photodiodePinRed = A1; //red photodiode
int photodiodePinIR = A2; //IR photodiode

int buttonState = 0; //set initial button pressed state to false

int photodiodeRedValue = 0; //initialize the red photodiode sensor value
int photodiodeIRValue = 0; //initialize the IR photodiode sensor value

const int redAmpFactor = 100;
const int IRAmpFactor = 100;

void startMeasurement(){
  //red LED light
  digitalWrite(redPin, HIGH);
  delay(3000);

  //read voltage for red photodiode
  photodiodeRedValue = analogRead(photodiodePinRed);
  float voltagePhotodiodeRed = photodiodeRedValue * (3.3 / 1023) * redAmpFactor; // 3.3 V / 1023 analog units
  Serial.print("Red Voltage: ");
  Serial.println(voltagePhotodiodeRed);

  digitalWrite(redPin, LOW);
  delay(1000);
  
  //IRLED light
  digitalWrite(IRPin, HIGH);
  delay (3000);

  //read voltage for IR photodiode
  photodiodeIRValue = analogRead(photodiodePinIR);
  float voltagePhotodiodeIR = photodiodeIRValue * (3.3 / 1023) * IRAmpFactor; // 3.3 V / 1023 analog units
  Serial.print("IR Votage: ");
  Serial.println(voltagePhotodiodeIR);

  digitalWrite(IRPin, LOW);
  delay (1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

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
