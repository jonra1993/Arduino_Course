
#define wait 1
#define time 10
int freq = 0;
//SE USARA LA CONEXIÓN DE RGB
int pinRed=6;
int pinGreen=10;
int pinBlue=9;

void setup()
{
}

void loop() 
{
  for (freq = 150; freq < 1800; freq += 1) {
    tone(5, freq, time);     // Beep pin, freq, time
    if(freq<820)
    {
    setColor(255,0,0); //ROJO
    }
    else 
    {
    setColor(0,0,255); //AZUL
    }
    delay(wait);
  }
  for (freq = 1800; freq > 150; freq -= 1) 
  {
    tone(5, freq, time);     // Beep pin, freq, time
    if(freq>820)
    {
    setColor(255,0,0); //ROJO
    }
    else 
    {
    setColor(0,0,255); //AZUL
    }
    delay(wait);
  }
}



void setColor(int red, int green, int blue)
{ 
  green=map(green,0,255,255,0);
  analogWrite(pinBlue, 255-blue); 
  analogWrite(pinRed, 255-red);
  analogWrite(pinGreen, green);
  
}
