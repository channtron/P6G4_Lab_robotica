#include <Arduino.h>
#include "Sensores.h"
#include "Motores.h"
  
void control_P1 (){
  //Reference
  int referencia=30;
  int *dis1, *dis2;
  int err1, err2, e;
  int v;
  int Kp=50;
  
  lectura(dis1, dis2);

  err1 = referencia - *dis1;
  err2 = referencia - *dis2;

  if (err1< err2){
    e=err1;
  }
  else e=err2;
  
  v= Kp*e;
  if (v<10 && e!=0) v=10;
  
  motor_direc(v,v);
  
  delay(50);
  
}
