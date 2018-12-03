#include "Pines.h"
#include <Arduino.h>
#include <NewPing.h>

NewPing sensor1 (TRIG_PIN1, ECHO_PIN1, MAX);
NewPing sensor2 (TRIG_PIN2, ECHO_PIN2, MAX);



void sensor_test(){
  delay(500);
  Serial.print("Sensor 1 :");
  Serial.println(sensor1.ping_cm());
  Serial.print("Sensor 2 :");
  Serial.println(sensor2.ping_cm());
  
}

void lectura(int *distance1, int *distance2){
  *distance1 = sensor1.ping_cm();
  *distance2 = sensor2.ping_cm();
}
