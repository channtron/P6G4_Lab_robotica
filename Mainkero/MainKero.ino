int e1=0, ei=0;
int e11=0, ei1=0;
int e21=0, ei2=0;
/*Pines en los que se encuentran definidos los pines utilizados en el proyecto*/
#include "Pines.h"
#include "Motores.h"
#include "Sensores.h"
#include "control_Mod1.h"
#include "control_Mod2.h"
#include "control_Mod3.h"
#include "control_Mod4.h"
#include "comunicacion.h"
#include "Movimientos_basicos.h"



#include <SoftwareSerial.h>
/*Librería para la gestion de los sensores de distancia*/
#include <NewPing.h>

int *ref, *vel_max;
int *dis1, *dis2;
int *v1, *v2;

void setup () {

  /*Inicializacion de los motores*/
  // setup motor pin
  setup_motor();
  /*Inicializacion de la comunicacion serie*/
  Serial.begin(38400);
  Serial1.begin(38400);

  *vel_max=255;
  //*ref=30;
  
  
}

void loop () {

// // Modo prueba de movimientos

void Adelante(int *v1, int *v2);
motor_direc( *v1, *v2);
delay (1000);
void Retroceder(int *v1, int *v2);
motor_direc( *v1, *v2);
delay (1000);
void Rotar_horario (int *v1, int *v2); 
motor_direc( *v1, *v2);
delay (1000);
void Rotar_antihorario (int *v1, int *v2);
motor_direc( *v1, *v2);
delay (1000);
void Girar_izq (int *v1, int *v2);
motor_direc( *v1, *v2);
delay (1000);
void Girar_der (int *v1, int *v2);
motor_direc( *v1, *v2);
delay (1000);


// // // Modo Controladores

//comunica();
//lectura (dis1, dis2);

// lee_serie(vel_max, ref);
// Serial.println(*ref);

 //control_TN1(*ref, *dis1, *dis2, v1, v2);
 //control_P1(*ref, *dis1, *dis2, v1, v2);
 //control_PID1(*ref, *dis1, *dis2, v1, v2);
 //control_TN2(*ref, *dis1, *dis2, v1, v2);
 //control_P2(*ref, *dis1, *dis2, v1, v2);
 //control_PID2(*ref, *dis1, *dis2, v1, v2);
 //control_TN3(*dis1, *dis2, v1, v2);
 //control_P3(*dis1, *dis2, v1, v2);
 //control_PID3(*dis1, *dis2, v1, v2);
 //control_TN4(*ref, *dis1, *dis2, v1, v2);
 //control_P4(*ref, *dis1, *dis2, v1, v2);
 //control_PID4(*ref, *dis1, *dis2, v1, v2);

// motor_direc( *v1, *v2);
// delay (50);

}


