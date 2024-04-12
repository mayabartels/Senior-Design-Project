/* BIM 110 - UC Davis Senior Design */

int photodiodeRedPin = A1;

int photodiodeRedValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photodiodeRedPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photodiodeRedValue = analogRead(photodiodeRedPin);
  float voltagePhotodiodeRed = photodiodeRedValue * (3.3 / 1023);
  Serial.println(voltagePhotodiodeRed);
}
