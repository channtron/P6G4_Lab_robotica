#include <Arduino.h>

void Adelante(int *v1, int *v2){
  *v1=100;
  *v2=100;
}

void Retroceder(int *v1, int *v2){
  *v1=-100;
  *v2=-100;
}

void Rotar_horario (int *v1, int *v2){
  *v1=100;
  *v2=0;
}

void Rotar_antihorario (int *v1, int *v2){
  *v1=0;
  *v2=100;
}

void Girar_izq (int *v1, int *v2){
  *v1=100;
  *v2=100*0.3;
}

void Girar_der (int *v1, int *v2){
  *v1=100*0.3;
  *v2=100;
}

