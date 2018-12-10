#include <Arduino.h>
#include "Sensores.h"
#include "Motores.h"
  
void control_P1 (int referencia){
  //Reference
  
  int *dis1, *dis2;
  int err1, err2, e;
  int v;
  int Kp=100;
  
  lectura(dis1, dis2);

  err1 = referencia - *dis1;
  err2 = referencia - *dis2;

  if (err1< err2){
    e=err1;
  }
  else e=err2;
  
  v= Kp*e;
  if (v<10 && v>5) v=10;
  else if (v>-10 && v<-5) v=-10;
  
  motor_direc(v,v);
 
  delay(50);
  
}

