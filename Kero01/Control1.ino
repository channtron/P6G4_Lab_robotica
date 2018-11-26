#include <hcsr04.h>

#define TRIG_PIN1    23
#define ECHO_PIN1    22
#define TRIG_PIN2    53
#define ECHO_PIN2    52

HCSR04 mySensor1;
HCSR04 mySensor2;
unsigned short distance1;
unsigned short distance2;
unsigned short referencia;
int err1=0;
int err2=0;

// Motor 1, o1 high, o2 low forward, vel pwm value
int M1O1 = 9;
int M1O2 = 10; 
int V1   = 7;

// Motor 2, o1 high, o2 low forward, vel pwm value
int M2O1 = 11;
int M2O2 = 12;
int V2   = 8;


void setup() {         

  mySensor1.init(TRIG_PIN1, ECHO_PIN1);
  mySensor2.init(TRIG_PIN2, ECHO_PIN2);
  Serial1.begin(9600);
  // setup motor pin
  // Motor 1
  pinMode (M1O1, OUTPUT);
  pinMode (M1O2, OUTPUT);
  pinMode (V1,   OUTPUT);
  // Motor 2
  pinMode (M2O1, OUTPUT);
  pinMode (M2O2, OUTPUT);
  pinMode (V2,   OUTPUT);

}

void loop(){
  //Reference
  referencia=Serial1.read();
  distance1 = mySensor1.readDisctanceInMm();
  distance2 = mySensor2.readDisctanceInMm();

  err1 = referencia - distance1;
  err2 = referencia - distance2;

  if(err1 > 0 && err2 > 0)
  {
  Avance(100);
  delay(50);
  }
  else if(err1 < 0 && err2 < 0)
  {
  Retroceso(100);
  delay(50);
  }
  else if(err1 == 0 || err2 == 0)
  {
    delay(50);
    Serial1.print('Ha llegado a su destino');
  }
 
}
void Avance (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, HIGH);
 digitalWrite (M1O2, LOW);
 analogWrite  (V1,   v);
 //Direccion motor B
 digitalWrite (M2O1, HIGH);
 digitalWrite (M2O2, LOW);
 analogWrite  (V2,   v*1.05);
}

void Retroceso (int v)
{
 //Direccion motor A
 digitalWrite (M1O1, LOW);
 digitalWrite (M1O2, HIGH);
 analogWrite  (V1,   v);
 //Direccion motor B
 digitalWrite (M2O1, LOW);
 digitalWrite (M2O2, HIGH);
 analogWrite  (V2,   v*1.05);
}
