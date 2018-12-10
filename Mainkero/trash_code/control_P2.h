#include <Arduino.h>
#include "Sensores.h"
#include "Motores.h"
  
void control_P2 (int referencia){
  //Reference
  
  int *dis1, *dis2;
  int err1, err2;
  int v1,v2;
  int Kp=100;
  
  lectura(dis1, dis2);

  err1 = referencia - *dis1;
  err2 = referencia - *dis2;
  
  v1= Kp*err1;
  v2= Kp*err2;
  
  if (v1<10 && v1>5) v=10;
  else if (v1>-10 && v1<-5) v=-10;
  
  if (v2<10 && v2>5) v=10;
  else if (v2>-10 && v2<-5) v=-10;
  
  motor_direc(v1,v2);
 
  delay(50);
  
}

