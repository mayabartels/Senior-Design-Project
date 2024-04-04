//initialize variables
const int redLED_pin = 11;
const int IRLED_pin = 10;

void setup() {
  pinMode(redLED_pin, OUTPUT);
  pinMode(IRLED_pin, OUTPUT);
}

void loop() {
  //redLED light
  digitalWrite(redLED_pin, HIGH);
  delay(1000);
  digitalWrite(redLED_pin, LOW);
  delay(1000);
  
  //IRLED light
  digitalWrite(IRLED_pin, HIGH);
  delay (1000);
  digitalWrite(IRLED_pin, LOW);
  delay (1000);
}
