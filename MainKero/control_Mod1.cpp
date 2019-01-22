#include <Arduino.h>
extern int e1, ei;
extern int v1, v2;
extern int dis1, dis2;
extern int ref;

void control_TN1 (){
  //Reference
  int err1;
  int err2;


  err1 = ref - dis1;
  err2 = ref - dis2;

  if(err1 > 0 && err2 > 0)
  {
    v1=100;
    v2=100;
  }
  else if(err1 < 0 && err2 < 0)
  {
    v1=-100;
    v2=-100;
  }
  else if(err1 == 0 || err2 == 0)
  {
    v1=0;
    v2=0;
  }
}

  
void control_P1 (){
  //Reference
  
  int err1, err2, e;
  int v;
  int Kp=100;
  

  err1 = ref - dis1;
  err2 = ref - dis2;

  if (err1< err2){
    e=err1;
  }
  else e=err2;
  
  v= Kp*e;
  if (v<10 && v>5) v=10;
  else if (v>-10 && v<-5) v=-10;
  
  v1=v;
  v2=v;
}


void control_PID1 (){
  //Reference
  int err1, err2, e;
  int v;
  int Kp=50;
  int Ki=5;
  int Kd=70;
  

  err1 = ref - dis1;
  err2 = ref - dis2;

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
  
  v1=v;
  v2=v;
}
