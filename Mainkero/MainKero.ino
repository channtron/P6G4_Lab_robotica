/*Pines en los que se encuentran definidos los pines utilizados en el proyecto*/
#include "Pines.h"
#include "Motores.h"
#include "Sensores.h"
#include "control_Mod1.h"
//#include "control_Mod2.h"
#include "comunicacion.h"

#include <SoftwareSerial.h>
/*Librería para la gestion de los sensores de distancia*/
#include <NewPing.h>

int *ref;
int *dis1, *dis2;
int *v1, *v2;

void setup () {
  
  /*Inicializacion de los motores*/
  // setup motor pin
  setup_motor();
  /*Inicializacion de la comunicacion serie*/
  Serial.begin(38400);
  Serial1.begin(38400);

  
}

void loop () {
 comunica();
 lectura (dis1, dis2);

 control_TN1(*ref, *dis1, *dis2, v1, v2);
 //control_P1(*ref, *dis1, *dis2, v1, v2);
 //control_PID1(*ref, *dis1, *dis2, v1, v2);
 //control_TN2(*ref, *dis1, *dis2, v1, v2);
 //control_P2(*ref, *dis1, *dis2, v1, v2);
// control_PID2(*ref, *dis1, *dis2, v1, v2);

  motor_direc( *v1, *v2);


}


