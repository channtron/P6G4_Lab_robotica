/*Pines en los que se encuentran definidos los pines utilizados en el proyecto*/
#include "Pines.h"
/*Funciones para el control de los motores*/
#include "Motores.h"
/*Librería para la gestion de los sensores de distancia*/

#include <SoftwareSerial.h>
#include <NewPing.h>


NewPing sensor1(TRIG_PIN1, ECHO_PIN1, MAX);
NewPing sensor2(TRIG_PIN2, ECHO_PIN2, MAX);

int distance;

void setup () {
  
  /*Inicializacion de los motores*/
  setup_motor(); 
  /*Inicializacion de la comunicacion serie*/
  Serial.begin(38400);
  Serial1.begin(38400);

  
}

void loop () {

  delay(500);
  Serial.print("Sensor 1 :");
  Serial.println(sensor1.ping_cm());
  Serial.print("Sensor 2 :");
  Serial.println(sensor2.ping_cm());
  
}

