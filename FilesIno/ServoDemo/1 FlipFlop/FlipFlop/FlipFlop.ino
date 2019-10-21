/*
Archivo: FlipFlop.ino
  Muestra como opera un servomotor controlado por 
  posición codificada en ancho de pulso.

  Genera la secuencia de rotación angular.
  0[°] < angulo < 180[°]  
*/


#include <Servo.h>
        Servo myservoPin_9; 
        int angle = 0; 
        int tiempo = 50
        ;
void setup(){
            myservoPin_9.attach(9); 
            }
void loop(){
          for(angle = 0; angle < 180; angle++){ 
                myservoPin_9.write(angle); 
                delay(tiempo);           
                }
          for(angle = 180; angle >= 1; angle--){
                myservoPin_9.write(angle); 
                delay(tiempo); 
          }
}
