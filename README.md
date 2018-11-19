# P6G4_Lab_robotica
Esta practica consiste en el desarrollo de un robot móvil diferencial controlado con arduino, que debe pasar una serie de pruebas.

Materiales disponibles:
-Arduino Mega
-Puente H (L298N)
-Modulo Bluetooth (HC-05) Con divisor de tensión Velocidad: 38400
-Sensor distancia ultrasonido (HC-SR04) x2

División de tareas a la hora de los tests:
-Videos:            Ana
-Telemetría:        Oscar
-Código:            Pelayo
-Monitorear robot:  

Codigo de colores cables:

-Puente H
  Alimentación:
    -Rojo:   Vin
    -Negro:  GND
  Control:
    -Amarillo:  Enable Motor1: Out 07, Motor2: Out 08
    -Verde:     Entrada impares Motor1: Out 09-10 
    -Azul:      Entrada pares   Motor2: Out 11-12
    /por ahora se está controlando exclusivamente el sentido de giro, por ello los ENA y ENB están corticircuitados

-Motores:
  Rojo:  Motor1: Out1, Motor2: Out 4
  Negro: Motor1: Out2, Motor2: Out 3  
  
-Sensor HC-SR04
  -Verde:     Alimentación
  -Amarillo:  Trigger imprares Sensor1: 22-23 
  -Azul:      Echo    pares    Sensor2: 52-53
  
-Bluetooth HC-05
  -Azul:      Tx (Pin 19 Rx)
  -Amarillo:  Rx (Pin 18 Tx)
  -Morado:    +5V
  -Negro:     GND
