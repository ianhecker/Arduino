int LEDPin = 11;

void setup()
{ 
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int numba = 255;

  lightThatShitUp(numba);
}

// Just a wee bit of recursion
void lightThatShitUp(int numba)
{
  if(numba <= -255)  {analogWrite(LEDPin, abs(numba));
                      return;}
                  
  else if(numba <= 0){delay(50);
                      analogWrite(LEDPin, abs(numba));
                      lightThatShitUp(numba - 5);}

  else                {delay(50);
                      analogWrite(LEDPin, abs(numba));
                      lightThatShitUp(numba - 5);}
}
