int competidor1=2;
int competidor2=3;
int conta1=0;
int conta2=0;
int led=5;


void setup()
{
  pinMode(competidor1,INPUT_PULLUP);
  pinMode(competidor2,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
  attachInterrupt(0, uno, FALLING);
  attachInterrupt(1, dos, FALLING);


}

void loop()
{
  Serial.print("Participante1= ");
  Serial.print(conta1);
  Serial.print("    Participante2= ");
  Serial.println(conta2);
  
  if((conta1==10)||(conta2==10))
  {
    detachInterrupt(0);    //detienen interrupciones
    detachInterrupt(1);
    digitalWrite(led,HIGH);
    
    if(conta1==10)
    {
      Serial.println("Ganador Participante1 ");
      
    }
    else
    {
      Serial.println("Ganador Participante2 ");
    }
    
    while(1)
    {
    }
    
  }

}

void uno()
{
  delay(200);   //antirebotes
  conta1++;

}

void dos()
{
  delay(200);  //antirebotes
  conta2++;
  
}
