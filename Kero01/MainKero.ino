/*Pines en los que se encuentran definidos los pines utilizados en el proyecto*/
#include <Pines.h>
/*Funciones para el control de los motores*/
#include <Motores.h>

#include <SoftwareSerial.h>


void setup () {
  
  /*Inicializacion de los motores*/
  setup_motor(); 
  /*Inicializacion de la comunicacion serie*/
  Serial.begin(9600);
  Serial1.begin(38400);
  
}

