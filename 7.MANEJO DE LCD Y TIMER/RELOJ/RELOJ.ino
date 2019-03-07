
//poner condicion cuando llegue a 24 h
//adicionar pulsadores para regular la hora

#include <TimerOne.h>
#include <LiquidCrystal.h>

int minutos=8;
int segundos=0;
int horas=22;

LiquidCrystal lcd(0,1,2,3,4,5);//rs,E,D4,D5,D6,D7   RW A GND

void setup() 
{
  lcd.begin(16,2);
  lcd.print("Reloj (HH:MM:SS)");
  Timer1.initialize(100000);  //esta en microsegundos   da 1 segundo
  Timer1.attachInterrupt(ya_paso_1s); // activa interrupcion del timer1
}

void loop()
{
  lcd.setCursor(3,1);
  
  //se suma un minuto cada 60 segundos
  if(segundos>59)
  {
    minutos++;
    segundos=0;
  }
  //se suma una hora cada 60 minutos
  if(minutos>59)
  {
    horas++;
    minutos=0;
  }
  //Se anade un 0 si la hora es menor a 10
  if(horas<10)
  {
    lcd.print("0");
  }
  lcd.print(horas);
  lcd.print(":");
  //Se anade un 0 si minuto es menor a 10
  if(minutos<10)
  {
    lcd.print("0");
  }
  lcd.print(minutos);
  lcd.print(":");
    //Se anade un 0 si segundos es menor a 10
  if(segundos<10)
  {
    lcd.print("0");
  }
  lcd.print(segundos);
  
}

void ya_paso_1s()
{
  segundos=segundos+1;
}
