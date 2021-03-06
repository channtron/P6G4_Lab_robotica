/*El orden para inicializar el modo de control: 1º control, 2º referencia inicial, 3º velocidad inicial, 4º modo*/
/*A partir de haber inicializado, la velocidad y la referencia se van cambiando para corroborar su funcionamiento*/
#include <Arduino.h>

/*variable donde se va almacenando el numero leido*/
int numero;
/*indican si se está modificando la referencia o la velocidad*/
int fr=0,fs=0,fm=0,fc=0; 

void comunica(int * ref, int * vmax, int * mfun, int * contr) {
  
  int refin=*ref, vin=*vmax, modo=*mfun, control=*contr;
   
  while (Serial1.available()) {
  
    char character = Serial1.read();
    
    /*'r' final de carrera, mientras no se detecte*/
    if (character != '+') { 
      
      /*comando para cambiar la referencia*/
      if (character == 'r') { 
        numero = 0;
        fr++;
        fs=0;
        fc=0;
        fm=0;
      }

      /*comando para cambiar la velocidad maxima*/
      else if (character == 's') {
        numero = 0;
        fs++;
        fr=0;
        fc=0;
        fm=0;
      }

      else if (character == 'm'){
        numero = 0;
        fs=0;
        fr=0;
        fc=0;
        fm++;     
      }
       else if (character == 'c'){
        numero = 0;
        fs=0;
        fr=0;
        fc++;
        fm=0;     
      }

      /*se detecta un numero*/
      if (character >= 48 && character <= 57) {
        numero = int(character) - 48 + 10 * numero;
        numero = constrain(numero, 0, 255);
      }
    }

    /*se detecta el final de carrera y se escribe la velocidad o referencia nueva*/
    else {

      /*se ha modificado la referencia*/
      if (fr == 1) {
        fr = 0;
        refin = numero;
      }

      /*se ha modificado la velocidad maxima*/
      else if (fs == 1) {
        fs = 0;
        vin = numero;
      }
      /*se ha modificado modo*/ 
       else if (fm == 1) {
        fm = 0;
        if(numero < 5){
        modo = numero;
        }
        else
        {
          modo=*mfun;
        }
      }
      /*se ha modificado el control*/
       else if (fc == 1) {
        fc = 0;
         if(numero < 3){
        control = numero;
        }
        else
        {
          control=*contr;
        }
      }
      
    }
    
  }

  /*devolucion de los valores de referencia y velocidad*/
  *ref=refin;
  *vmax=vin;
  *mfun=modo;
  *contr=control;
  
}

void telemetria(unsigned long *pt,int dis1, int dis2, int ref, int mode, int v1, int v2) { //tiempo anterior, distanciaS1, distanciaS2, referencia, modoC, velocidadM1, velocidadM2
  unsigned long t=millis();
  unsigned dt = *pt - t;
  Serial1.println(dt);
  Serial1.print(dis1);
  Serial1.print(dis2);
  Serial1.print(ref);
  Serial1.print(mode);
  Serial1.print(v1);
  Serial1.print(v2);
  *pt=t;
}
