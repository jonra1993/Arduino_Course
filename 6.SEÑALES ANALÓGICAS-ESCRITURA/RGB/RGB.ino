int pinRed=11;
int pinGreen=10;
int pinBlue=9;

void setup() 
{

}

void setColor(int red, int green, int blue)
{ 
  green=map(green,0,255,255,0);
  analogWrite(pinBlue, 255-blue); 
  analogWrite(pinRed, 255-red);
  analogWrite(pinGreen, green);
  
}

void loop()
{
  
  setColor(100,100,100);
  delay(500);
  setColor(255,110,100);
  delay(500);
  setColor(0,110,255);
  delay(500);
  
}
