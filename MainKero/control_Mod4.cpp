#include <Arduino.h>


extern int e11, ei1;
extern int e21, ei2;
extern int v1, v2;
extern int dis1, dis2;
extern int ref;
extern int alpha;
  
void control_TN4 (){
  /*Si se encuentra muy lejos de la pared los sensores se 
  puede perder la referencia del muro y estrellarse contra este*/
  int err1, err2;

  err1 = ref - dis1;
  err2 = ref - dis2;

  if(err1 > 0 && err2 > 0) {
    v1=-150;
    v2=-150*0.5;
  }
  
  else if(err1 < 0 && err2< 0) {
    v1=-150*0.5;
    v2=-150;
  }

  else {
    if (err1<err2){
      v1=-150;
      v2=-150*0.5;
    }
    else if(err1>err2){
      v1=-150*0.5;
      v2=-150;
    }
    else {
      v1=-150;
      v2=-150;
    }
  } 
}

  
void control_P4 (){
  
  int err1, err2, err;
  int Kp1=40, Kp2=100;
  

  err1 = dis1 - ref;
  err  = dis1 - dis2;

  v1= -(-Kp1*err1 +Kp2*err)/16 -200; //recordar guardar el modo 4 original (sin sat) era entre 8 y a 150
  v2= -(+Kp1*err1 -Kp2*err)/16 -200;
  
  if (err>alpha) {
    v1=v2*1.3;
  }
  else if (err<-alpha) {
    v2=v1*1.3;
    
  }
  
  if (v1<60 && v1>5) v1=60;
  else if (v1>-60 && v1<-5) v1=-60;
  
  if (v2<60 && v2>5) v2=60;
  else if (v2>-60 && v2<-5) v2=-60;
  
}



void control_PID4 (){

  int err1, err;
  
  int Kp1=40;
  int Kd1=-10;
  
  int Kp=150;
  int Kd=-20;
  int Ki=0;
  
  err1 = dis1 - ref;
  err  = dis1 - dis2;

    Serial.print(err1);
  Serial.print(' ');
  Serial.println(err);

  v1= -(-Kp1*err1 -Kd1*(err1-e11) +Kp*err +Ki*(ei1) +Kd*(err-e21))/16 -200;
  v2= -(+Kp1*err1 +Kd1*(err1-e11) -Kp*err -Ki*(ei2) -Kd*(err-e21))/16 -200;

  if (err>alpha) {
    v1=v2*1.3;
  }
  else if (err<-alpha) {
    v2=v1*1.3;
    
  }
  
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
  
  
  if (v1<10 && v1>5) v1=10;
  else if (v1>-10 && v1<-5) v1=-10;

  if (v2<10 && v2>5) v2=10;
  else if (v2>-10 && v2<-5) v2=-10;
  
  e11=err1;
  e21=err;
  
}
