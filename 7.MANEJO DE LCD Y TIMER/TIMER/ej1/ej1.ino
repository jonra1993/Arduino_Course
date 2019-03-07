#include <TimerOne.h>

const int led = 13;  

volatile unsigned long contador = 0;
int estado = LOW;

void setup(void)
{
  pinMode(led, OUTPUT);
  digitalWrite(led,estado);
  Timer1.initialize(1000000);  //esta en microsegundos
  Timer1.attachInterrupt(blinkLED); // activa interrupcion del timer1
  Serial.begin(9600);
}

void loop(void)
{
  

}

void blinkLED(void)
{
  if (estado == LOW) {
    estado = HIGH;
    contador++;  // increase when LED turns on
    Serial.print("# Veces que se enciende = ");
    Serial.println(contador);
    
  } else {
    estado = LOW;
  }
  digitalWrite(led, estado);
  
}
