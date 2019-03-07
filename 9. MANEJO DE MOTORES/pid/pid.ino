#include <TimerOne.h>

int ek, ek_1, ek_2;
float uk_1;
int pwm;

  float kp=0.5;
  float ki=0.4;
  float kd=1;
  float T=0.002;
  int medida=1;
  int setpoint=0;
  
void setup() {

  Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds  


}

void loop() { 
  medida=map(analogRead(7),0,1023,-10,10);
  PID(medida, setpoint, kp,ki,kd, &ek_1, &ek_2, &uk_1, T );
  motores(uk_1,setpoint); 
  delay(20);
}

void blinkLED(void)
{
  Serial.print("uk_1=");
  Serial.println(uk_1);
  Serial.print("medida=");
  Serial.println(medida);
  Serial.print("pwm=");
  Serial.println(pwm);
}

float PID(int setpoint, int medida, float Kp, float Ki, float Kd,int *ek_1, int *ek_2,float *uk_1, float T){ //T en segundos
      
  float uk, t0, t1, q0, q1, q2, c;  //Señal de control
  int ek,a,b;

  ek=medida-setpoint;

 
  t0=Kd/T;
  t1=Ki*T;
    
  q0=Kp+t0;
  q1=-Kp-2*t0+t1;
  q2=Kp*t0;
  //ley de control
  a=*ek_1;
  b=*ek_2;
  c=*uk_1;
  
  uk=c+q0*ek+q1*a+q2*b;
  if(uk>255) uk=255;
  if(uk<-255) uk=-255;
  //aplica uk
  //Actualiza datos
  *uk_1=uk;
  *ek_1=ek;
  *ek_2=a;
  return 0;
  }

void motores(float leydecontrol, int set_point)
{
   
  if(leydecontrol>0)
  {
    analogWrite(3,255-set_point);
    pwm=set_point+int(leydecontrol);
    if(pwm>255) pwm=255;
    analogWrite(5,255-pwm);
    }
  else if (leydecontrol<0)
  {
    pwm=set_point-int(leydecontrol);
    if(pwm>255) pwm=255;    
    analogWrite(3,255-pwm);
    analogWrite(5,255-set_point);
    }
  else 
  {
    analogWrite(3,0);
    analogWrite(5,0);
    }
}
  


  
