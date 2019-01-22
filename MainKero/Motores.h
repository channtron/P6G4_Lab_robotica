extern int vel_max;

#include <Arduino.h>
#include "Pines.h"

void setup_motor() {
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

void motor_direc(int v1, int v2) {
  
  if (v1 > 0)
  {
    digitalWrite (M1O1, LOW);
    digitalWrite (M1O2, HIGH);
  }
  else
  {
    digitalWrite (M1O1, HIGH);
    digitalWrite (M1O2, LOW);
  }
  
  if (v2 > 0)
  {
    digitalWrite (M2O1, LOW);
    digitalWrite (M2O2, HIGH);
  }
  else
  {
    digitalWrite (M2O1, HIGH);
    digitalWrite (M2O2, LOW);
  }
  v2=v2*1.05;
  if (v1>vel_max) v1=vel_max;
  else if(v1<-(vel_max)) v1=-(vel_max);
  if (v2>vel_max) v2=vel_max;
  else if(v2<-(vel_max)) v2=-(vel_max);
   analogWrite  (V1,   abs(v1));
   analogWrite  (V2,   abs(v2));  
}


