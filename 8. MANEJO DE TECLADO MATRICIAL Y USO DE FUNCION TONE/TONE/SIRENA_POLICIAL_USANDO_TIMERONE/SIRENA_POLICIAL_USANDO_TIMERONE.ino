#include <TimerOne.h>
#define wait 1
#define time 10
int freq = 0;
int rojo=6;  //LED DEL RGB
int azul=9;  //LED DEL RGB
//EN EL RGB EL COMUN VA A VCC Y CADA COLOR CONECTADO A UNA 
//RESISTENCIA Y LUEGO AL PIN RESPECTIVO DE ARDUINO

void setup()
{
  pinMode(rojo, OUTPUT);
  digitalWrite(rojo,LOW);
  pinMode(azul, OUTPUT);
  digitalWrite(azul,LOW);
  Timer1.initialize(150000);  //esta en microsegundos
  Timer1.attachInterrupt(cambiar_color); // activa interrupcion del timer1
}

void loop() 
{
  for (freq = 150; freq < 1800; freq += 1) {
    tone(12, freq, time);     // Beep pin, freq, time
    delay(wait);
  }
  for (freq = 1800; freq > 150; freq -= 1) 
  {
    tone(12, freq, time);     // Beep pin, freq, time
    delay(wait);
  }
}

void cambiar_color(void)
{
  if (digitalRead(rojo) == LOW) {
    digitalWrite(rojo,HIGH);
    digitalWrite(azul,LOW);
    
  } 
  else 
  {
     digitalWrite(rojo,LOW);
    digitalWrite(azul,HIGH);
  }
 
}
