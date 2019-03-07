#include <LiquidCrystal.h>

LiquidCrystal lcd(0,1,2,3,4,5); //va del rs, E,D4,D5,D6,D7      RW A GND

void setup() 
{
   lcd.begin(16, 2); // Fijar el numero de caracteres y de filas
   lcd.print("Hello, Jonathan!"); // Enviar el mensaje

}

void loop() 
{
  lcd.setCursor(7, 1);  // set the cursor to column 0, line 1
  lcd.print(millis() / 1000);  // muestra los segunso transcurridos

}
