
char *referencia_1[4];
size_t referencia_1Index = 0;

void comunica(int *referencia_num)
{
  
 while (Serial.available())
   {
      char character = Serial.read();
      if (character != '\n')
      {   
         referencia_1[referencia_1index] = character;
         referencia_1index ++;
      }
      else
        { 
          *referencia_num = 100*(int)referencia_1[1] + 10*(int)referencia_1[2] + (int)referencia_1[3]; 
          *referencia_num = *referencia_num - (111*48);
          if(referencia_1[0]== 'r'){
           Serial.println("referencia:");
           referencia_1index = 0;
           Serial.println(referencia_num);

           }
          else 
          Serial.println(referencia_1);
        
      }
   }
 
}
