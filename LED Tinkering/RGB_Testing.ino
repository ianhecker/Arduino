int redPin = 10;
int greenPin = 9;
int bluePin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);  
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  red();
    fiveSec();
  green();
    fiveSec();
  /*blue();
    fiveSec();
  yellow();
    fiveSec();
  purple();
    fiveSec();
  aqua();
    fiveSec();*/
}

void red() {
  specificColor(255, 0, 0);    
}
void green() {
  specificColor(0, 255, 0);  
}
void blue() {
  specificColor(0, 0, 255);  
}
void yellow() {
  specificColor(255, 255, 0);  
}
void purple() {
  specificColor(80, 0, 80);  
}
void aqua() {
  specificColor(0, 255, 255);  
}
void specificColor(int red, int green, int blue) {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);  
    analogWrite(bluePin, blue);
}
void fiveSec() {
  delay(5000);  
}
