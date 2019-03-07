//PROGRAMA QUE LEE UNA CADENA DE CARACTERES POR COMUNICACION SERIAL
//Y PRENDE O APAGA EL LED DEL PIN 13

//SE CREA DOS CONSTANTES  EJ. ENCENDER=1
#define ENCENDER 1
#define APAGAR 0

char caracter;
byte i=0;
char cadena[100];   //LONGITUD MAXIMA DE LA CADENA DE CARACTERES ES 100
int led=13;

void setup() 
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() 
{
  if(Serial.available())   //SI LLEGA ALGUN DATO
  {
    caracter=Serial.read();  //SE GUARDA EL DATO EN UNA VARIABLE
    
    if (caracter==10)   //SI EL DATO DE ENTRADA ES ENTER
    {
      cadena[i++]='\0';  //indica fin de cadena
      i=0;                 //se resetea el contador
      
      if(strcmp(cadena, "Encender")==0)  //strcmp ES UNA FUNCION DEL LENGUAJE C 
        {                                //QUE COMPARA DOS STRING O CADENAS DE CARACTERES
         AC_Action(ENCENDER);            //SI SON IGUALES EL VALOR OBTENIDO ES 0
        }
        
      if(strcmp(cadena, "Apagar")==0)
        {
        AC_Action(APAGAR);
        }
    }
    else
    {
      cadena[i++]=caracter;   //SE GUARDA EL DATO EN UNA POSICION DEL VECTOR
    }
  }
}

void AC_Action(int accion)  //FUNCION QUE PRENDE O APAGA EL LED
{
  if(accion==ENCENDER)
  {
    
    Serial.println("Encendiendo luces interiores...");
    delay(500);
    digitalWrite(led,HIGH);
    Serial.println("luces interiores Encendidas :) ...");
  }
  
    if(accion==APAGAR)
  {
    
    Serial.println("Apagando luces interiores...");
    delay(500);
    digitalWrite(led,LOW);
    Serial.println("luces interiores Apagadas :( ...");
  }
}

