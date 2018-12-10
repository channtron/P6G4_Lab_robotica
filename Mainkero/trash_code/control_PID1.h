#include <Arduino.h>
#include "Sensores.h"
#include "Motores.h"

int e1=0, ei=0;

void control_PID1 (int referencia){
  //Reference
  int *dis1, *dis2;
  int err1, err2, e;
  int v;
  int Kp=50;
  int Ki=5;
  int Kd=70;
  
  lectura(dis1, dis2);

  err1 = referencia - *dis1;
  err2 = referencia - *dis2;

  if (err1< err2){
    e=err1;
  }
  else e=err2;

  
  v= Kp*e+Ki*ei+Kd*(e-e1);

  if (v>255) {
    v=255;
  }
  else if (v<-255) {
    v=-255;
  }
  else ei=ei+e;
  
  if (v<10 && v>5) v=10;
  else if (v>-10 && v<-5) v=-10;
  e1=e;
  
  motor_direc(v,v);
  delay(50);
  
}

