int led=6;

void setup() 
{
  pinMode(led,OUTPUT);
  digitalWrite(led, LOW);

}

void loop() 
{
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
 
}
