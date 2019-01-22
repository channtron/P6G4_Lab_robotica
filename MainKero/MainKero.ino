int e1=0, ei=0;
/*variables globales para los distintos modos de control*/
int e11=0, ei1=0;
int e21=0, ei2=0;
int alpha=4;
/*Pines en los que se encuentran conectados los perifericos utilizados en el proyecto*/
#include "Pines.h"
/*Codigo para el control de los motores, direccion y velocidad*/
#include "Motores.h"
/*Gestión de los distintos modos de funcionamiento y control de movimiento*/
#include "modos.h"
/*Lectura de los sensores*/
#include "Sensores.h"

#include "Movimientos_basicos.h"



#include <SoftwareSerial.h>
/*Librería para la gestion de los sensores de distancia*/
#include <NewPing.h>

int ref,  vel_max;
int dis1, dis2;
int v1,   v2;
int modo, control;
unsigned long pt;

void setup () {

  /*Inicializacion de los motores*/
  setup_motor();
  /*Inicializacion de la comunicacion serie*/
  Serial.begin(38400);
  Serial1.begin(38400);

  /*Inicializacion de las características generales*/
  vel_max = 255;
  pt = millis();
  modo = 0;
  control = 0;
  ref = 30;
  
  
}

void loop () {
  
//Prueba(); //Prueba de los movimientos basicos de los motores


  comunica();
  lectura ();
  telemetria(dis1, dis2, ref, modo, v1, v2);
 
  modo_select();

  motor_direc( v1, v2);
  
  delay (50);
}


void Prueba(){
  // // Modo prueba de movimientos

Adelante();
motor_direc( v1, v2);
delay (1000);
Retroceder();
motor_direc( v1, v2);
delay (1000);
Rotar_horario (); 
motor_direc( v1, v2);
delay (1000);
Rotar_antihorario ();
motor_direc( v1, v2);
delay (1000);
Girar_izq ();
motor_direc( v1, v2);
delay (1000);
Girar_der ();
motor_direc( v1, v2);
delay (1000);
}

