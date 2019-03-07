#include <Servo.h>
//VARIANTE USANDO UN POTENCIOMETRO PARA DETERMINAR EL ANGULO

Servo miServo;

int angulo=90;
int analogo;

void setup() 
{
  miServo.attach(9);
  Serial.begin(9600);
}

void loop() 
{
  
    analogo=analogRead(A0); 
    angulo=map(analogo,0,1023,0,180);
    
    miServo.write(angulo);  
    Serial.print("Angulo: "); 
    Serial.println(angulo);
    delayMicroseconds(10);


}
