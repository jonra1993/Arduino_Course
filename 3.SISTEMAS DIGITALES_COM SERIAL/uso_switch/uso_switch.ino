int uno=9;
int dos=10;
int tres=11;
char recibido;

//es lo mismo
boolean prendido1=false;
boolean prendido2=LOW;
boolean prendido3=0;

void setup()
{
  
  pinMode(uno,OUTPUT);
  digitalWrite(uno,LOW);
  pinMode(dos,OUTPUT);
  digitalWrite(uno,LOW);
  pinMode(tres,OUTPUT);
  digitalWrite(uno,false);  //poner 0 es lo mismo que poner false o LOW
  
  Serial.begin(9600);  //ESTABLECE VELOCIDAD DE TRANSMISION
}

void loop()
{
  if (Serial.available())
  {
    recibido=Serial.read();
    
    switch (recibido)
    {
      case '1':
        if(prendido1==LOW)
        {
          digitalWrite(uno,HIGH);
          prendido1=HIGH;
        }
        else
        {
          digitalWrite(uno,LOW);
          prendido1=LOW;
        }
        break;
        
      case '2':
        if(prendido2==LOW)
        {
          digitalWrite(dos,HIGH);
          prendido2=HIGH;
        }
        else
        {
          digitalWrite(dos,LOW);
          prendido2=LOW;
        }
        break;
        
      case '3':
        if(prendido3==LOW)
        {
          digitalWrite(tres,HIGH);
          prendido3=HIGH;
        }
        else
        {
          digitalWrite(tres,LOW);
          prendido3=LOW;
        }
        break;
        
        
    }
  }
}
