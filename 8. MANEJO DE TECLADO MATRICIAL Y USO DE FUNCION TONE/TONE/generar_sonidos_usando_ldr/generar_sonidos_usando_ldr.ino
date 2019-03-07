int min=757;
int max=1023;

void setup() 
{
  Serial.begin(9600);
    
 }
 
 void loop() {
   // get a sensor reading:
   int sensorReading = analogRead(A5);
   // map the results from the sensor reading's range
   // to the desired pitch range:
   
   float frequency = map(sensorReading, min, max, 500, 4000);
   // change the pitch, play for 10 ms:
   Serial.println(sensorReading);
   tone(2, frequency, 10);
 }
