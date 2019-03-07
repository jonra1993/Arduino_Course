#include <Keypad.h>

const byte FILAS = 4; //cuatro filas
const byte COLUMNAS = 4; //cuatro columnas
//simbolos del teclado matricial
char TECLAS[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte PINES_FILAS[FILAS] = {13,12,11,10}; //coneccion de los pines de las filas
byte PINES_COLUMNAS[COLUMNAS] = {9,8,7,6}; //coneccion de los pines de las columnas

//se inicia una clase de teclado matricial
Keypad TECLADO1= Keypad(makeKeymap(TECLAS), PINES_FILAS, PINES_COLUMNAS, FILAS, COLUMNAS);

void setup(){
  Serial.begin(9600);
  //se activa el pull up en las columnas
  pinMode(9,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
}
  
void loop()
{
  char  PULSACION= TECLADO1.getKey();
  
  if (PULSACION!=0)
  {
    Serial.print("tecla ");
    Serial.println(PULSACION);
  }
}
