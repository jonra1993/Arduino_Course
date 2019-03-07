
const int echo = 8;
const int trigger = 9;
int distancia; 

void setup(){
  Serial.begin(9600);
  pinMode(trigger, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(echo, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){

  distancia=ping(trigger, echo); //en mmm
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" mm");
  delay(1000);
}

int ping(int TriggerPin, int EchoPin) {   
   long tiempo;
   float distanceCm;
   
  digitalWrite(trigger,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(trigger,LOW); /* Por cuestión de estabilización del sensor*/
  
  tiempo=pulseIn(echo, HIGH)/2; /*tiempo q se demora en ir */      
  distanceCm = float(tiempo * 0.0343)-1;
  distanceCm=int (distanceCm*10);
  return distanceCm;
}
