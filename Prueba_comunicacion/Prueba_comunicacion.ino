#include <Arduino.h>

char referencia_1[4];
int i,k=0,j=0,ind = 0;
int referencia, velocidad;

/*variable donde se va almacenando el numero leido*/
int numero;
/*indican si se está modificando la referencia o la velocidad*/
int fr=0,fs=0,fm=0,fc=0; 

  int refin=0, vin=0, modo=0, control=0;
void setup()
{
  Serial.begin(9600);
  Serial1.begin(38400);
  Serial.println("on");  
  Serial1.println("on");  
  
}
void loop(){
  
  
    char character = Serial1.read();
    
    /*'r' final de carrera, mientras no se detecte*/
    if (character != '+') { 
      Serial1.println();
      Serial1.println("Introduce referencia(r,nº): ");
      /*comando para cambiar la referencia*/
      if (character == 'r') { 
        numero = 0;
        fr++;
        fs=0;
        fc=0;
        fm=0;
        Serial1.println();
        Serial1.println("Introduce velocidad(s,nº): ");
      }

      /*comando para cambiar la velocidad maxima*/
      else if (character == 's') {
        numero = 0;
        fs++;
        fr=0;
        fc=0;
        fm=0;
        Serial1.println();
        Serial1.println("Introduce modo(m,nº): ");
      }

      else if (character == 'm'){
        numero = 0;
        fs=0;
        fr=0;
        fc=0;
        fm++;
        Serial1.println();
        Serial1.println("Introduce controlador(c,nº): ");     
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
        Serial1.println();
        Serial1.println("La referencia es: ");
        Serial1.print(refin);
      }

      /*se ha modificado la velocidad maxima*/
      else if (fs == 1) {
        fs = 0;
        vin = numero;
        Serial1.println();
        Serial1.println("La velocidad es: ");
        Serial1.print(vin);
      }
      /*se ha modificado modo*/ 
       else if (fm == 1) {
        fm = 0;
        if(numero < 5){
          modo = numero;
          Serial1.println();
          Serial1.println("El modo es: ");
          Serial1.print(modo);
          }
        else
        {
          Serial1.println();
          Serial1.println("numero > 5: ");
          Serial1.print(numero);
        }
      }
      /*se ha modificado el control*/
       else if (fc == 1) {
        fc = 0;
         if(numero < 3){
         control = numero;
         Serial1.println();
         Serial1.println("El control es: ");
         Serial1.print(control);
        }
        else
        {   
          

           control= 3333;
           Serial1.println();
           Serial1.println("introducir caracteres correctamente");
           Serial1.print(control);
        }
      }
      
    }

    
}

void loop2(){

 while (Serial1.available())
   {  
      char character = Serial1.read();
      if (character != '+')
      {        
          if(character == 'r'){
              numero=0;
              k++;
              
           }
           else if(character == 's'){
              numero=0;
              j++;
            
           }
          if (character >= 48 && character <= 57) {
              numero = int(character)-48 + 10*numero;
           }
          
        
      }
      
      else
        {  
          if (k==1 && j==0){
           k=0;
           j=0;
           referencia = numero;
           Serial1.println();
           Serial1.println("referencia:");
           Serial1.println(referencia);
                      
          }
          else if(j==1 && k==0){
           j=0;
           k=0; 
           velocidad = numero;
           Serial1.println();
           Serial1.println("velocidad:");
           Serial1.println(velocidad);
           }
          else {
            j=0;
            k=0;
           numero=0;
           Serial1.println();
           Serial1.println("introducir caracteres correctamente");
          }        
      }
      
   }
 
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
