/*
--------------------------------------
Escritura serial
--------------------------------------
Consiste en escribir por la pantalla del computador (consola serial)
una letra predeterminada, la primera vez que se escriba está
un LED se enciende, si se vuelve a escribir por segunda vez
el LED se apaga.

*/

int led=6;
char recibido;
boolean activo;


void setup() 
{
  Serial.begin(9600);  //ESTABLECE VELOCIDAD DE TRANSMISION
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() 
{

  if (Serial.available())
  {
     recibido=Serial.read();
  
    if ((recibido=='a')&&(activo==false))
    {   
      digitalWrite(led,HIGH);
      Serial.println("encendido");
      activo=true;
      
    }
    else if ((recibido=='a')&&(activo==1))
    {
      Serial.println("apagado");
      digitalWrite(led,LOW);
      activo=false;
     
    }
  }
}
