/*Pines en los que se encuentran definidos los pines utilizados en el proyecto*/
#include "Pines.h"
#include "control1.h"

#include <SoftwareSerial.h>
/*Librería para la gestion de los sensores de distancia*/
#include <NewPing.h>



void setup () {
  
  /*Inicializacion de los motores*/
  setup_motor(); 
  /*Inicializacion de la comunicacion serie*/
  Serial.begin(38400);
  Serial1.begin(38400);

  
}

void loop () {


}

