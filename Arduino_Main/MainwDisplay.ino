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

float red_ir_ratio = 0;
float pH = 0;


#include <SparkFun_Qwiic_OLED.h>
QwiicNarrowOLED myOLED;
String pHStr;

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

  // calculate the pH based on the ratio
  red_ir_ratio = voltagePhotodiodeRed / voltagePhotodiodeIR;
  pH = 51.4 * exp(-2.04 * red_ir_ratio);
  Serial.print("Ph: ");
  Serial.println(pH);

  delay(3000);
  // Fill a rectangle on the screen that has a 4 pixel board
  myOLED.rectangleFill(4, 4, myOLED.getWidth() - 8, myOLED.getHeight() - 8);

  String str_pH = String(pH,2); // our message

  // Center our message on the screen. Get the screen size of the "hello" string,
  // calling the getStringWidth() and getStringHeight() methods on the oled

  // starting x position - screen width minus string width  / 2
  int x0 = (myOLED.getWidth() - myOLED.getStringWidth(str_pH)) / 2;

  // starting y position - screen height minus string height / 2 
  int y0 = (myOLED.getHeight() - myOLED.getStringHeight(str_pH)) / 2;

  // Draw the text - color of black (0)
  myOLED.text(x0, y0, str_pH, 0);

  // There's nothing on the screen yet - Now send the graphics to the device
  myOLED.display();  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Wire.begin();

  // Initalize the OLED device and related graphics system
  if (myOLED.begin() == false)
  {
      Serial.println("Device begin failed. Freezing...");
      while (true)
          ;
  }
  Serial.println("Begin success");

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

  // delay(1000);
}