char referencia_1[4];
int i,k=0,j=0,ind = 0;
int referencia, velocidad, numero;
void setup()
{
  Serial.begin(9600);
  Serial1.begin(38400);
  Serial.println("on");  
  Serial1.println("on");  
  
}
void loopold(){
  if (Serial1.available()){
    char character = Serial1.read();
      if (character != '+')
      {   
         referencia_1[ind] = character;
         ind ++;
      }
      if(character == '+'){
        Serial1.println();
        Serial1.print("se escribe: ");
        Serial1.println(referencia_1);
        ind=0;
        for(i=0; i<4; i++)
        {   
         referencia_1[ind] = 0;
         ind ++;
        }
        Serial1.println();
        Serial1.println("se limpió: ");
        Serial1.print(referencia_1);
        ind=0;
      }
  }
}

void loop2(){
 while (Serial1.available())
   {  
      char character = Serial1.read();
      if (character != '+')
      {   
         referencia_1[ind] = character;
         ind ++;
      }
      if(referencia_1[0] == 'r'){
              numero=0;
              k=1;
              
           }
           else if(referencia_1[0] == 's'){
              numero=0;
              k=2;
            
           }
          if (referencia_1[ind] >= 48 && referencia_1[ind] <= 57) {
              numero = int(referencia_1[ind])-48 + 10*numero;
          }
      
      else
        {  
          if (k==1){
           k=0;
           referencia = numero;
           Serial1.println();
           Serial1.println("referencia:");
           Serial1.println(referencia);
                      
          }
          else if(k==2){
           k=0; 
           velocidad = numero;
           Serial1.println();
           Serial1.println("velocidad:");
           Serial1.println(velocidad);
           }
          else {
           numero=0;
           Serial1.println();
           Serial1.println("introducir caracteres correctamente");
          }        
      }
      
   }
 
}

void loop(){

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
