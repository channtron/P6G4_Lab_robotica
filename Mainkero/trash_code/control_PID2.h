#include <Arduino.h>
#include "Sensores.h"
#include "Motores.h"

int e11=0, ei1=0;
int e21=0, ei2=0;

void control_PID2 (int referencia){
  //Reference
  int *dis1, *dis2;
  int err1, err2;
  int v1,v2;
  int Kp=50;
  int Ki=3;
  int Kd=50;
  
  lectura(dis1, dis2);

  err1 = referencia - *dis1;
  err2 = referencia - *dis2;

  v1= Kp*err1+Ki*ei1+Kd*(err1-e11);
  v2= Kp*err2+Ki*ei2+Kd*(err2-e21);

  if (v1>255) {
    v1=255;
  }
  else if (v1<-255) {
    v1=-255;
  }
  else ei1=ei1+err1;

  if (v2>255) {
    v2=255;
  }
  else if (v2<-255) {
    v2=-255;
  }
  else ei2=ei2+err2;
  
  
  if (v1<10 && v1>5) v1=10;
  else if (v1>-10 && v1<-5) v1=-10;

  if (v2<10 && v2>5) v2=10;
  else if (v2>-10 && v2<-5) v2=-10;
  
  e11=err1;
  e21=err2;

  motor_direc(v1,v2);
  delay(50);
  
}

