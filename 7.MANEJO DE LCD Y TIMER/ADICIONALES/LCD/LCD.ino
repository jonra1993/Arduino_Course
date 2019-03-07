 /* Configuración de LCD
 RS Enable R/W D4 D5 D6 D7 VSS VDD Vo
 12 11 Gnd 5 4 3 2 Gnd Vcc Pot
 */


#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1,2,3,4,5); //va del rs, E,D4,D5,D6,D7 RW A GND

void setup() 
{
  lcd.begin(16,2);  //un lcd de 16*2
  lcd.setCursor(0,1);   //(x,y) primera posicion 0
  lcd.print("Hola Jonathan");
}

void loop()
{
  delay(1000);
   lcd.clear();
  
    // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }

  // set the cursor to (16,1):
  lcd.setCursor(16, 1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  // clear screen for the next loop:
  lcd.clear();
  

}
