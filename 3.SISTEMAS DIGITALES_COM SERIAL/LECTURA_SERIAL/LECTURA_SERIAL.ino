/*
--------------------------------------
Lectura serial de una entrada digital
--------------------------------------
Leer una entrada digital y mostrar por la pantalla del
computador (consola serial) el estado del pulsador
cuando es oprimido
Serial.print(data, DEC);   // decimal en ASCII
Serial.print(data, HEX);   // hexadecimal en ASCII 
Serial.print(data, OCT);    // octal en ASCII 
Serial.print(data, BIN);    // binario en ASCII 
Serial.print(data, BYTE);   // un Byte

dato   Modificador         Envío (pulsos)
 65     ---DEC----    (“6″ y “5″ ASCIIs 54–55) 000110110–000110111 
 65     ---HEX----    (“4″ Y “1″ ASCIIs 52–49) 000110100–000110001  
 65     ---OCT----    (“1″, “0″ y “1″ ASCIIs 49–48–49) 000110001–000110000–000110001 
 65     ---BIN----    (“0″,”1″,”0″,”0″,”0″,”0″,”0″y”1″   ASCIIs 49–48–49–49–49–49–49–48) 000110000-…
 65     ---BYTE---    01000001

*/

int boton=2;

void setup()
{
  pinMode(boton,INPUT_PULLUP);
  Serial.begin(9600);     //inicia la com serial
}

void loop()
{
  int estado=digitalRead(boton);   //leo el valor en boton 0 o 1
  
  if(estado==false)  //false,  0,  LOW
  {
    Serial.println("Pulsado"); //lo mismo de print pero con un salto de renglon
  }
  else
  {
    Serial.println("NO Pulsado");
  }
  
  delay(100);  //retardo para visualizacion del mensaje
  
  
}
