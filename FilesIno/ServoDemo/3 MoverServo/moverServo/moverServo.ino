/*
Archivo: moverServo.ino
  Muestra como opera un servomotor controlado por 
  posición codificada en ancho de pulso.

  Genera la secuencia de rotación angular.
  0[°] < angulo < 180[°]  
*/


#include <Servo.h>
        Servo myservoPin_9; 
        int angle = 0; 
        
void setup(){
            myservoPin_9.attach(9); 
            }

            
void loop(){
          moverServo(0,0, 10);
          pausa(800);
          moverServo(0,45, 80);
          pausa(800);
          moverServo(45,135,30);
          pausa(800);
          moverServo(135, 180, 50);
          pausa(800);
          }



/*
    inicio: posición inicial del servo [°]
    final : posicion a la que se desea ir [°]
    tiempo1: tiempo en que se desrrolla el despalazamiento angular [ms]
*/

      void moverServo(int inicio, int final, int tiempo1){
             for(angle = inicio; angle < final ; angle++){ 
                myservoPin_9.write(angle); 
                delay(tiempo1);           
                }
             }
             
        void pausa(int time){
            delay(time);
          }

