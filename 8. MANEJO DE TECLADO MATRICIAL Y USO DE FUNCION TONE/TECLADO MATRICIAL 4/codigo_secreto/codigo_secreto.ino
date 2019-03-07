//CLAVE DE UNA CAJA FUERTE
#include <Keypad.h>
const byte filas=4;
const byte columnas=4;

byte pines_filas[filas]={13,12,11,10};
byte pines_columnas[columnas]={9,8,7,6};

int posicion=0;
int rojo=5;
int verde=4;

char* secretcode="3567";
char teclas[filas][columnas]=
      {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
      };

Keypad teclado1=Keypad(makeKeymap(teclas),pines_filas,pines_columnas,filas,columnas);

void setup() 
{
  pinMode(9,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
  setLocked(true);
  Serial.begin(9600);
}

void loop() 
{
  char key=teclado1.getKey();
  
  if(key=='B')
  {
    posicion=0;
    setLocked(true);
  }
  
  else if(key==(secretcode[posicion]))
  {
    posicion++;
  }
  
  else if(key==0)
  {

  }
  
  else
  {
    posicion=0;
  }
  
  Serial.print(key);
  Serial.print("    ");
  Serial.println(posicion);
  
  
  if(posicion==4)
  {
    setLocked(false);
    key=0;
    posicion=0;
  }
  delay(100);


}

void setLocked(int locked)
{
  if(locked==true)
  {
    digitalWrite(rojo,HIGH);
    digitalWrite(verde,LOW);
  }
  else
  {
    digitalWrite(rojo,LOW);
    digitalWrite(verde,HIGH);
  }
}
