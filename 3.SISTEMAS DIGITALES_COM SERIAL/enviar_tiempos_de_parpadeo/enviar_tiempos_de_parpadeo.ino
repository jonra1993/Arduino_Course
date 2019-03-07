int tiempo=100;
int led=12;

void setup() 
{
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  Serial.begin(9600);

}

void loop()

{
  
  if (Serial.available())
  {
    tiempo=Serial.read();
    tiempo=tiempo-48;
    tiempo=tiempo*100;
  }
  
  digitalWrite(led,HIGH);
  delay(tiempo);
  digitalWrite(led,LOW);
  delay(tiempo);
  Serial.print("El tiempo es: ");
  Serial.println(tiempo);
}
