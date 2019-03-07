
int lectura;
int led=11;
int canal=3;
int  signal;
float voltaje;

void setup()
{
  Serial.begin(9600);
 
}

void loop() 
{
 
  lectura=analogRead(canal);   //se pudo colocar A0
  signal=map(lectura,0,1023,0,255);
  voltaje=float(signal)*5/255;
  analogWrite(led,signal);
  Serial.print("Valor Analogo: ");
  Serial.print(lectura);  //HEX,DEC,OCT,BIN,BYTE
  Serial.print("  pwm: ");
  Serial.print(signal);  
  Serial.print("  ancho: ");
  Serial.print((signal*100)/255);  
  Serial.print("%");
  Serial.print("  Voltaje: ");
  Serial.print(voltaje);  
  Serial.println("V");


}
