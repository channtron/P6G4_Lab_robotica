#include <Arduino.h>
#include "Sensores.h"
#include "Motores.h"
  
void control_M1 (){
  //Reference
  int referencia=30;
  int *dis1, *dis2;
  int err1;
  int err2;

  lectura(dis1, dis2);

  err1 = referencia - *dis1;
  err2 = referencia - *dis2;

  if(err1 > 0 && err2 > 0)
  {
  motor_direc(100,100);
  
  delay(50);
  }
  else if(err1 < 0 && err2 < 0)
  {
  motor_direc(-100,-100);
  delay(50);
  }
  else if(err1 == 0 || err2 == 0)
  {
    analogWrite  (V1,   0);
    analogWrite  (V2,   0);
    delay(50);

  }
}
