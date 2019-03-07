
float val0;
float val1;
float val2;
float v[10];
float voltage;

void setup()
{
  Serial.begin(9600); 
}

  float dato(int u)
  {

    for (int i=0; i<10; i++)
    {
      float voltage=analogRead(u);
      v[i]=voltage  ;

    }
    voltage=0;
    for (int i=0; i<10; i++)
    {
      voltage=voltage+v[i];

    }
    voltage=voltage/10;

  }

void loop() 
{ 
  dato(0);
  float sen0=voltage;
  float voltage0=(sen0/1024.0)*5.0;
  dato(1);
  float sen1=voltage;
  float voltage1=(sen1/1024.0)*5.0;
  dato(2);
  float sen2=voltage;
  float voltage2=(sen2/1024.0)*5.0;
  
  Serial.print("Sen0: ");
  Serial.print(sen0);
  Serial.print(", Voltios: ");
  Serial.println(voltage0);

  Serial.print("Sen1: ");
  Serial.print(sen1);
  Serial.print(", Voltios: ");
  Serial.println(voltage1);
  
  Serial.print("Sen2: ");
  Serial.print(sen2);
  Serial.print(", Voltios: ");
  Serial.println(voltage2);  
   Serial.println(" ");  
  
  delay(1000);
  
  }
  

