
int led=9;  
int valor;  

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);
}

void loop() 
{
  valor=analogRead(A0);
  Serial.print("Valor ya Digitalizado: ");
  Serial.println(valor);
  delay(10);

}
