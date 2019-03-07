int signal=8;
int pull_up=7;
int pull_down=6;
boolean int1;
boolean int2;

void setup() 
{
  pinMode(signal,OUTPUT);
  digitalWrite(signal,LOW);
  
  pinMode(pull_up,INPUT);
  digitalWrite(pull_up,HIGH);   //ACTIVA EL PULL-UP INTERNO
  
  pinMode(pull_down,INPUT_PULLUP);
 
}

void loop() 
{
  int1=digitalRead(pull_up);
  int2=digitalRead(pull_down);
  
    if((int1^int2)==HIGH)
    {
      digitalWrite(signal,HIGH);
    }
    
    else
    {
      digitalWrite(signal,LOW);
    }
 
}
