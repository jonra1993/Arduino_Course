|int input1=13;
int input2=12;
int enable=9;  //salida pwm para variar la velocidad
int analogico;
char recibido;

void setup() 
{
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW);
  
  Serial.begin(9600);
}

void loop() 
{
  
  analogico=analogRead(5);
  int signal=map(analogico,0,1023,0,255);
  analogWrite(enable,signal);
  
  if(Serial.available())
  {
    recibido=Serial.read();
    
    switch (recibido)
    {
      case 's':
        HORARIO();
      break;
      
      case 'a':
        ANTIHORARIO();
      break;
      
      case 32:  //codigo ascii del espacio
        DETENER();
      break;
    }
  }
  

}

void HORARIO()
{
  digitalWrite(input1,LOW);
  Serial.println("Giro Horario");
  digitalWrite(input2,HIGH);

}

void ANTIHORARIO() 
{
  digitalWrite(input1,HIGH);
  Serial.println("Giro Antihorario");
  digitalWrite(input2,LOW);
}

void DETENER() 
{
  digitalWrite(input1,LOW);
  Serial.println("Detener motor");
  digitalWrite(input2,LOW);
}
