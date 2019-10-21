/*
Archivo: PotenciometroPosicion.ino
    Muestra la codificación de posición angular
    dependiente de una señal analógica.
*/
byte tiempo = 100;

#include <Servo.h>
        Servo myservo; 
        int potenciometropin = 0; 
        int val;
         
void setup(){
            myservo.attach(9);
            Serial.begin(9600); 
}


void loop(){
        val = analogRead(potenciometropin);
        
        Serial.print("Valor leido: ");
        
        Serial.println(val);
         
        val = map(val, 0, 1023, 0, 179);
        
        Serial.print("Posicion: ");
        
        Serial.println(val);
         
        myservo.write(val); 
        delay(tiempo); 
        }

