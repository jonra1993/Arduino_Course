#include "pitches.h"

#include <Keypad.h>

#define speaker 4
#define time 300

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



void setup() 
{
  pinMode(9,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
}

void loop() 

{
  char  PULSACION= TECLADO1.getKey();
  
  switch (PULSACION)
  {
    case '1':
        tone(speaker,NOTE_D8);
        delay(time);
        noTone(speaker);
      break;
    case '2':
        tone(speaker,NOTE_A4);
        delay(time);
        noTone(speaker);
      break;
    case '3':
        tone(speaker,NOTE_B4);
        delay(time);
        noTone(speaker);
      break;
    case '4':
        tone(speaker,NOTE_C4);
        delay(time);
        noTone(speaker);
      break;

    case '5':
        tone(speaker,NOTE_D4);
        delay(time);
        noTone(speaker);
      break;
      
    case '6':
        tone(speaker,NOTE_E4);
        delay(time);
        noTone(speaker);
      break;
      
    case '7':
        tone(speaker,NOTE_F4);
        delay(time);
        noTone(speaker);
      break;
      
    case '8':
        tone(speaker,NOTE_G4);
        delay(time);
        noTone(speaker);
      break;
      
    case '9':
        tone(speaker,NOTE_A5);
        delay(time);
        noTone(speaker);
      break;
      
    case '0':
        tone(speaker,NOTE_B5);
        delay(time);
        noTone(speaker);
      break;
    
    case 'A':
        tone(speaker,NOTE_C5);
        delay(time);
        noTone(speaker);
      break;
      
     case 'B':
        tone(speaker,NOTE_D5);
        delay(time);
        noTone(speaker);
      break;
      
      case 'C':
        tone(speaker,NOTE_E5);
        delay(time);
        noTone(speaker);
      break;
      
      case 'D':
        tone(speaker,NOTE_F5);
        delay(time);
        noTone(speaker);
      break;
      
      case '*':
        tone(speaker,NOTE_A3);
        delay(time);
        noTone(speaker);
      break;
      
       case '#':
        tone(speaker,NOTE_A4);
        delay(time);
        noTone(speaker);
      break;
  }

}
