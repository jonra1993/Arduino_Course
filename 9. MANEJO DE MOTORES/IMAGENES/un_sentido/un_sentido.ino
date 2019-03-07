
int potenciometro=0;
int motor=10;
int valor;
int signal;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  valor=analogRead(potenciometro);
  signal=map(valor,0,1023,0,255);
  Serial.print("Porcentaje de la PWM: ");
  Serial.println(signal*100/255);
  
  if (Serial.available())
  {
    char dato=Serial.read();
    
    switch (dato)
    {
    case 'a':
    analogWrite(motor,signal);
    break;
    
    case 32:
    analogWrite(motor,0);
    break;
    }
    
    
  }

}
