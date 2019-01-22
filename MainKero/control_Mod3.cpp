#include <Arduino.h>

extern int e1;
extern int ei1, ei2;
extern int v1, v2;
extern int dis1, dis2;

void control_TN3 (){
  if (dis1<dis2){
    v1=-150*0.3;
    v2=-150;
  }
  else if(dis1>dis2){
    v1=-150;
    v2=-150*0.3;
  }
  else {
    v1=-150;
    v2=-150;
  }
}

void control_P3 (){
  //Reference
  
  int err;
  int Kp=50;
  

  err = dis1-dis2;
  
  v1 = -(Kp*err+150);
  v2 = -(-Kp*err+150);
  
  if (v1<10 && v1>5) v1=10;
  else if (v1>-10 && v1<-5) v1=-10;
  
  if (v2<10 && v2>5) v2=10;
  else if (v2>-10 && v2<-5) v2=-10;
  
}

void control_PID3 (){
  //Reference
  int err;
  int Kp=50;
  int Ki=3;
  int Kd=-20;

  err = dis1 - dis2;

  v1= -( Kp*err +Ki*(ei1) +Kd*(err-e1) +200);
  v2= -(-Kp*err -Ki*(ei2) -Kd*(err-e1) +200);

  if (v1>255) {
    v1=255;
  }
  else if (v1<-255) {
    v1=-255;
  }
  else ei1=ei1+err;

  if (v2>255) {
    v2=255;
  }
  else if (v2<-255) {
    v2=-255;
  }
  else ei2=ei2+err;
  
  
  if (v1<60 && v1>5) v1=60;
  else if (v1>-60 && v1<-25) v1=-60;

  if (v2<60 && v2>5) v2=60;
  else if (v2>-60 && v2<-25) v2=-60;
  
  e1=err;
  
}
