#include "TimerOne.h"
 
void setup()
{
  pinMode(10, OUTPUT);
  Timer1.initialize(1000);         // 500us con lo cual se obtiene una frecuencia de 2kHz
  Timer1.pwm(9, 500);                // (pin de la pwm 9 o10, ancho de pulso hasta 1023)
  Timer1.attachInterrupt(callback);  // interrupcion por overflow
}
 
void callback()
{
  digitalWrite(10, digitalRead(10) ^ 1);
}
 
void loop()
{
  // your program here...
}
