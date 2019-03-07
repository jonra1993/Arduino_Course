int inc=3;
//int dec=2;
int contador;
int n;
int ESTADO;
int analogo;

void setup() 
{
  pinMode(inc,INPUT_PULLUP);
  //pinMode(dec,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

  
  //attachInterrupt(0, baja, FALLING);
  attachInterrupt(1, sube, FALLING);
}

void loop() 
{
  analogo=analogRead(3);
  Serial.println(analogo);
  delay(100);
  //if (n!=contador)
  //{
    //if(ESTADO==0)
    //{
     // digitalWrite(13,HIGH);
      //ESTADO=1;
    //}
    //else{
     // digitalWrite(13,LOW);
      //ESTADO=0;
    //}
    //Serial.println(contador);
    //n=contador;
    
  //}
}

//void baja()
//{
 // delay(200);   //antirebotes
 // contador--;

//}

void sube()
{
  delay(1000);  //antirebotes
  contador++;
  
}


