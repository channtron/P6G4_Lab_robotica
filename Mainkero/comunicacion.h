#include <Arduino.h>



int comunica()
{
  char referencia_1[4];
  int referencia_num;
  int i = 0;

 while (Serial.available())
   {
      char character = Serial.read();
      if (character != '\n')
      {   
         referencia_1[i] = character;
         i ++;
      }
         else if(i>=4){
         referencia_num = 100*(int)referencia_1[1] + 10*(int)referencia_1[2] + (int)referencia_1[3]; 
         referencia_num = referencia_num - (111*48);
         if(referencia_1[0]== 'r'){
         Serial.println("referencia:");
         Serial.println(referencia_num);
         i=0;
         }
          else 
          Serial.println(referencia_1);
          i=0;
         }
      }
 return referencia_num;
}


int lee_serie(int * vel_max, int * ref) {
  while (Serial1.available()) {
    char comand = Serial1.read();
    switch (comand) {
      case 'r':
        *ref = constrain (Serial1.parseInt(), 0, 200);
        break;
      case 's':
        *vel_max = constrain (Serial1.parseInt(), 0, 255);
        break;
      default:
        // Serial.println("Comando no reconocido ");
        break;
      
    }
  }
}


