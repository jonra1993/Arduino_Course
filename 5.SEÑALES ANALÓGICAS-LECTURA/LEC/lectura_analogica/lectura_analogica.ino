
int lectura;
int canal=3;

void setup()
{
  
  Serial.begin(9600);

}

void loop() 
{
 
  lectura=analogRead(canal);   //se pudo colocar A0
  Serial.print("Valor Analogo: ");
  Serial.println(lectura,HEX);  //HEX,DEC,OCT,BIN,BYTE
  delay(10);

}
