int ledPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnOn(255);
  delay(500);
  turnOn(192);
  delay(500);
  turnOn(129);
  delay(500);
  turnOn(63);
  delay(500);
  turnOn(0);
  delay(500);
}

void turnOn(int brightness) {
  analogWrite(ledPin, brightness);
}
