extern int e1, ei;
extern int e11, ei1;
extern int e21, ei2;

extern int ref;
extern int dis1,  dis2;
extern int v1,    v2;
extern int modo, control;

#include "control_Mod1.h"
#include "control_Mod2.h"
#include "control_Mod3.h"
#include "control_Mod4.h"
#include "comunicacion.h"

void modo_select(){
  switch (modo){
    case 0:
      v1 = 0;
      v2 = 0;
      break;
    case 1:
      switch (control){
        case 0:
        control_TN1();
        break;
        case 1:
        control_P1();
        break;
        case 2:
        control_PID1();
        break;
      }
      break;
    case 2:
      switch (control){
        case 0:
        control_TN2();
        break;
        case 1:
        control_P2();
        break;
        case 2:
        control_PID2();
        break;
      }
      break;
    case 3:
      switch (control){
        case 0:
        control_TN3();
        break;
        case 1:
        control_P3();
        break;
        case 2:
        control_PID3();
        break;
      }
      break;
    case 4:
      switch (control){
        case 0:
        control_TN4();
        break;
        case 1:
        control_P4();
        break;
        case 2:
        control_PID4();
        break;
      }
      break;
  }
  
}


