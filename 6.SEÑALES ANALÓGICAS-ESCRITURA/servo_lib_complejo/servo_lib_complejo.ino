//VARIANTE USANDO UN POTENCIOMETRO PARA DETERMINAR EL ANGULO

#include <Servo.h>

Servo miServo;
int angulo=90;

void setup() 
{
  miServo.attach(7);
  Serial.begin(9600);
  miServo.write(angulo);

}

void loop() 
{
  unsigned char comando=0;
  
  if(Serial.available()) // solo lee si hay un byte en el buffer
  {
    comando=Serial.read(); //se lee byte 
    
    if(comando=='a')
    {
      miServo.attach(7);
      angulo=angulo+10;
      
    }
    else if (comando=='z')
    {
      miServo.attach(7);
      angulo-=10;
    }
    
    angulo=constrain(angulo,0,180); //se restringe el valor de 0 a 180 
    miServo.write(angulo);
    delay(50);
    miServo.detach();
  }
  
    
  Serial.print("Angulo: "); 
  Serial.println(angulo);
  delay(100);

}
