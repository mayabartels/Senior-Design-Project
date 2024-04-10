/* BIM 110 - UC Davis Senior Design */

const int photodiodeRedPin = A0;

int photodiodeRedValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photodiodeRedValue, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photodiodeRedValue = analogRead(photodiodeRedPin);
  float voltagePhotodiodeRed = photodiodeRedValue * (5 / 1023);
  Serial.println(photodiodeRedValue);
}
