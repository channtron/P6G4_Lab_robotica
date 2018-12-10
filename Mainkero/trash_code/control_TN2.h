#include <Arduino.h>
#include "Sensores.h"
#include "Motores.h"
  
void control_TN2 (int referencia){
  //Reference
  int *dis1, *dis2;
  int err1;
  int err2;

  lectura(dis1, dis2);

  err1 = referencia - *dis1;
  err2 = referencia - *dis2;

  if(err1 > 0)
  {
  v1=100;
  }
  else if(err1 < 0)
  {
  v1=-100;
  }
  else if(err1 == 0)
  {
  v1=0;
  }

  if(err2 > 0)
  {
  v2=100;
  }
  else if(err2 < 0)
  {
  v2=-100;
  }
  else if(err2 == 0)
  {
  v2=0;
  }
  
   motor_direc(v1,v2);
}

