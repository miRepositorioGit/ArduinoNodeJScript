/*
 * funcionesAux.cpp - Creación de repertorio de funciones
 * Created by Martín Cordero mi.cuenta.correo.en@gmail.com
 * Revision #1 - See readMe.txt 
 */

 #include "Arduino.h"
 #include "funcionesAux.h"

#define LED_BUILTIN 13
#define BLINK_DELAY_MS_ON  100
#define BLINK_DELAY_MS_OFF 100

/* turn on-turn off embedded led [2]  */
void blinkLed(){
                digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
                delay(BLINK_DELAY_MS_ON);                       // wait for a second
                digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
                delay(BLINK_DELAY_MS_OFF);                       // wait for a second
}

/* configura recursos periféricos */
 void configRecursos(){
         pinMode(LED_BUILTIN,OUTPUT);
}


                
