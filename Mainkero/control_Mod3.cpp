#include <Arduino.h>

extern int e1;
extern int ei1, ei2;

void control_TN3 (int dis1, int dis2, int *v1, int *v2){
  if (dis1<dis2){
    *v1=100*0.3;
    *v2=100;
  }
  else if(dis1>dis2){
    *v1=100;
    *v2=100*0.3;
  }
  else {
    *v1=100;
    *v2=100;
  }
}

void control_P3 (int dis1, int dis2, int *v1, int *v2){
  //Reference
  
  int err;
  int Kp=100;
  

  err = dis1-dis2;
  
  *v1= -Kp*err+100;
  *v2= Kp*err+100;
  
  if (*v1<10 && *v1>5) *v1=10;
  else if (*v1>-10 && *v1<-5) *v1=-10;
  
  if (*v2<10 && *v2>5) *v2=10;
  else if (*v2>-10 && *v2<-5) *v2=-10;
  
}

void control_PID3 (int dis1, int dis2, int *v1, int *v2){
  //Reference
  int err;
  int Kp=50;
  int Ki=3;
  int Kd=50;

  err = dis1 - dis2;

  *v1= -(Kp*err+Ki*(ei1)+Kd*(err-e1))+100;
  *v2= Kp*err+Ki*(ei2)+Kd*(err-e1)+100;

  if (*v1>255) {
    *v1=255;
  }
  else if (*v1<-255) {
    *v1=-255;
  }
  else ei1=ei1+err;

  if (*v2>255) {
    *v2=255;
  }
  else if (*v2<-255) {
    *v2=-255;
  }
  else ei2=ei2+err;
  
  
  if (*v1<10 && *v1>5) *v1=10;
  else if (*v1>-10 && *v1<-5) *v1=-10;

  if (*v2<10 && *v2>5) *v2=10;
  else if (*v2>-10 && *v2<-5) *v2=-10;
  
  e1=err;
  
}
