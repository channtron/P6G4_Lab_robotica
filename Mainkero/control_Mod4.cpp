#include <Arduino.h>

extern int e11, ei1;
extern int e21, ei2;
  
void control_TN4 (int referencia, int dis1, int dis2, int *v1, int *v2){
  //Reference
  int err1, err2;

  err1 = referencia - dis1;
  err2 = referencia - dis2;

  if(err1 > 0 && err2>0) {
    *v1=100;
    *v2=100*0.3;
  }
  
  else if(err1 < 0 && err2<0) {
    *v1=100*0.3;
    *v2=100;
  }
  
  else {
    if (err1<err2){
      *v1=100*0.3;
      *v2=100;
    }
    else if(err1>err2){
      *v1=100;
      *v2=100*0.3;
    }
    else {
      *v1=100;
      *v2=100;
    }
  } 
}

  
void control_P4 (int referencia, int dis1, int dis2, int *v1, int *v2){
  //Reference
  
  int err1, err2;
  int Kp=100;
  

  err1 = referencia - dis1;
  err2 = referencia - dis2;

  // los errores en este caso están al revés por la disposición de los sensores 
  *v1= Kp*err2;
  *v2= Kp*err1;
  
  if (*v1<10 && *v1>5) *v1=10;
  else if (*v1>-10 && *v1<-5) *v1=-10;
  
  if (*v2<10 && *v2>5) *v2=10;
  else if (*v2>-10 && *v2<-5) *v2=-10;
  
}



void control_PID4 (int referencia, int dis1, int dis2, int *v1, int *v2){
  //Reference
  int err1, err2;
  int Kp=50;
  int Ki=3;
  int Kd=50;

  // errores al revés por la disposión de los sensores
  err2 = referencia - dis1;
  err1 = referencia - dis2;

  *v1= Kp*err1+Ki*ei1+Kd*(err1-e11);
  *v2= Kp*err2+Ki*ei2+Kd*(err2-e21);

  if (*v1>255) {
    *v1=255;
  }
  else if (*v1<-255) {
    *v1=-255;
  }
  else ei1=ei1+err1;

  if (*v2>255) {
    *v2=255;
  }
  else if (*v2<-255) {
    *v2=-255;
  }
  else ei2=ei2+err2;
  
  
  if (*v1<10 && *v1>5) *v1=10;
  else if (*v1>-10 && *v1<-5) *v1=-10;

  if (*v2<10 && *v2>5) *v2=10;
  else if (*v2>-10 && *v2<-5) *v2=-10;
  
  e11=err1;
  e21=err2;
  
}
