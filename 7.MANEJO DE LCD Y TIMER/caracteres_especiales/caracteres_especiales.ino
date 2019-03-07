#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1,2,3,4,5);

byte corazon[8] =
 {
 0b00001010,
 0b00010101,
 0b00001010,
 0b00000100,
 0b00000000,
 0b00000000,
 0b00000000,
 0b00000000
 };
 
 byte feliz[8] =
 {
 0b00000000,
 0b00000000,
 0b00011011,
 0b00000000,
 0b00010001,
 0b00001110,
 0b00000000,
 0b00000000
 };

void setup() 
  {
      lcd.begin(16, 2); // Hay que inicializar el LCD
      lcd.createChar(1, corazon);
      lcd.createChar(2, feliz);
       
       
  }
void loop() 
 {
   lcd.setCursor(0, 0);
   lcd.write(1);
   
   lcd.setCursor(7, 1);
   lcd.write(2);
 }
