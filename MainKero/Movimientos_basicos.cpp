#include <Arduino.h>
extern int v1, v2;

void Adelante(){
  v1=150;
  v2=150;
}

void Retroceder(){
  v1=-150;
  v2=-150;
}

void Rotar_horario (){
  v1=150;
  v2=0;
}

void Rotar_antihorario (){
  v1=0;
  v2=150;
}

void Girar_izq (){
  v1=150;
  v2=150*0.3;
}

void Girar_der (){
  v1=150*0.3;
  v2=150;
}

