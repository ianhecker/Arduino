int redPin = 10;
int greenPin = 9;
int bluePin = 8;

int INTERVAL = 5000;
int SECONDS = 5;

//storing ints for previous color
int prevRed = 0;
int prevGreen = 0;
int prevBlue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
    red();
    orange();
    yellow();
    green();
    aqua();
    lightBlue();
    blue();
    purple();
    pink();
    white();
  */
  
  //colorFadeSystem();
  fade();     
}

void red() {
  specificColor(255, 0, 0);
}
void orange() {
  specificColor(255, 15, 0);
}
void yellow() {
  specificColor(255, 123, 0);
}
void green() {
  specificColor(0, 255, 0);
}
void aqua() {
  specificColor(0, 255, 150);  
}
void lightBlue() {
  specificColor(0, 255, 255); 
}
void blue() {
  specificColor(0, 0, 255);
}
void purple() {
  specificColor(255, 0, 255);
}
void pink() {
  specificColor(255, 20, 150);  
}
void white() {
  specificColor(200, 200, 200);  
}
void specificColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  
  //delay(INTERVAL);
  prevRed = red;
  prevGreen = green;
  prevBlue = blue;
}
//End of Rainbow methods

/*
void colorFadeSystem() {
  //fadeToColor(0, 0, 0);//Black
  
  fadeToColor(255, 0, 0);

  fadeToColor(255, 0, 255);

  fadeToColor(255, 255, 255);

  //fadeToColor(0, 0, 0);
}
void fadeToColor(int newRed, int newGreen, int newBlue) {
  int diffRed, diffGreen, diffBlue;
    diffRed = 0; diffGreen = 0; diffBlue = 0;
  double stepRed, stepGreen, stepBlue;
    stepRed = 0.0; stepGreen = 0.0; stepBlue = 0.0;
  double countRed, countGreen, countBlue;
    countRed = 0.0; countGreen = 0.0; countBlue = 0.0;
  
  diffRed = newRed - prevRed;
  diffGreen = newGreen - prevGreen;
  diffBlue = newBlue - prevBlue;

  stepRed = diffRed / (SECONDS * 20);//Points per red step
  stepGreen = diffGreen / (SECONDS * 20);//Points per green step
  stepBlue = diffBlue / (SECONDS * 20);//Points per blue step

  boolean keepGoing = true; 
  
  while(keepGoing) {
    countRed += stepRed;
    countGreen += stepGreen;
    countBlue += stepBlue;

    if(countRed > 255.0){
      countRed = 255.0;
    }
      if(countRed < -255.0){
        countRed = -255.0;
      } 
    if(countGreen > 255.0){
      countGreen = 255.0;  
    }
      if(countGreen < -255.0){
        countGreen = -255.0;
      }
    if(countBlue > 255.0){
      countBlue = 255.0;
    }
      if(countBlue < -255.0){
        countBlue = -255.0;
      }
    
    int inputRed = prevRed + (int)(countRed);
    int inputGreen = prevGreen + (int)(countGreen);
    int inputBlue = prevBlue + (int)(countBlue);
    
    analogWrite(redPin, abs(inputRed));
    analogWrite(greenPin, abs(inputGreen));
    analogWrite(bluePin, abs(inputBlue));

    int milliseconds = (SECONDS * 1000) / (20 * SECONDS);
    
    delay(milliseconds);    
    
    if(abs((int)countRed) == newRed){
      keepGoing = false;
    }
    else if(abs((int)countGreen) == newGreen){
      keepGoing == false;
    }
    else if(abs((int)countBlue) == newBlue){
      keepGoing == false;
    }    
 }
 prevRed = newRed;
 prevGreen = newGreen;
 prevBlue = newBlue; 
}*/

void fade() {
  boolean quit = false;
  
  int colorValue;
  int counter = 0;//Shared; Needs to be reset each while loop
  int pointStep = 1;

  int UPPER_BOUND = 30;
  
  while(quit == false){
    colorValue = (pointStep * counter);
    
    specificColor(255, colorValue, 0);
      delay(150);
      counter++;

    if(colorValue >= UPPER_BOUND){                       
      quit = true;
      counter = 0;//counter reset               
    }    
  }//End of While
  quit = false;  
  delay(2000);
  
  while(quit == false){
    colorValue = UPPER_BOUND - (pointStep * counter);
    
    specificColor(255, colorValue, 0);
      delay(150);
      counter++;
    
    if(colorValue <= 0){ 
      quit = true;//Exit loop
      //counter = 0;//counter reset
    }   
  }//End of While
  delay(5000);   
}
