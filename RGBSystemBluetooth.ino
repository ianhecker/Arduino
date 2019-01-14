int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int redInt = 0;
int greenInt = 0;
int blueInt = 0;

char acceptedLetters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

const int numChars = 6;
char receivedChars[numChars];
int index = 0;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  //writeColor(0, 0, 0);
  
  char letter;
  
  if(Serial.available() > 0) {
    letter = Serial.read();

    //Serial.print(letter);
    //Serial.print((int)letter);
    Serial.print('\n');
    //Serial.print("index = " + String(index) + "\n");

    if(letter < 71){
      if(index <= 5){
        receivedChars[index] = letter;
        Serial.print("receivedChars[" + String(index) + "] is " + String(letter) + "\n");
        index++;
      }
          
      if(index >= 6){
        translateFromHex();
        writeColor(redInt, greenInt, blueInt);
        index = 0;
      }
    }       
  }
}

void receiveData() {

  char letter;
  int index = 0;
  
  if(Serial.available() > 0) {
      letter = Serial.read();

      Serial.print(letter);
      Serial.print('\n');
      Serial.print("index = " + String(index) + "\n");
      
      index++;
      
  }
}

void translateFromHex() {
  
  char r1 = receivedChars[0];
  char r2 = receivedChars[1];
  
  char g1 = receivedChars[2];
  char g2 = receivedChars[3];
  
  char b1 = receivedChars[4];
  char b2 = receivedChars[5];
  
  redInt = convertHex(r1)*16 + convertHex(r2);

  greenInt = convertHex(g1)*16 + convertHex(g2);

  blueInt = convertHex(b1)*16 + convertHex(b2);  

  Serial.print("red: " + String(redInt) + "\n");
  Serial.print("green: " + String(greenInt) + "\n");
  Serial.print("blue: " + String(blueInt) + "\n");
}

int convertHex(char letter) {

  switch (letter) {
    case 'A':
      return 10;     
    case 'B':
      return 11;
    case 'C':
      return 12;
    case 'D':
      return 13;
    case 'E':
      return 14;
    case 'F':
      return 15;
    default:
      return int(letter) - 48; 
  }
}

void writeColor(int r, int g, int b) { 

  analogWrite(redPin, r);  
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}


