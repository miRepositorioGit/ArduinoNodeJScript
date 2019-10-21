/**
 * Blink_3.ino Muestra el resguardo de funciones en bibliotecas de funciones.
 * Blink_2.ino Muestra declaración de funciones prototipo
 * Blink_1.ino Muestra declaración de constantes.
 * Blink.ino   Turns an LED on for one second, then off for one times, repeatedly.
 * 
 *  Muestra como integrar una biblioteca de funciones.
 *  
 *    Se crean una biblioteca de funciones con los siguientes archivos:
 *    
 *    -funcionesAux.h     Contiene las definición de variables y funciones.
 *    -funcionesAux.cpp   Contiene el código de las funciones.
 *    -funcionesAux.txt   Contiene keywords usadas en la biblioteca de funciones.
 *    -readme.txt
 *    -Examples(.ino)    Contiene ejempos de uso. 
 *    
 *
 * Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
 * it is attached to digital pin 13, LED_BUILTIN is set to
 * the correct LED pin independent of which board is used.
 *  
 *  Fuente: S. Fitzgerald,A. Guadalupi,C. Newman. 8 Sep 2016. Disponible available:
 *       http://www.arduino.cc/en/Tutorial/Blink 
 */
#include "funcionesAux.h"

void setup() {
      configRecursos();    // configura recursos periféricos
}

void loop() {
            blinkLed();
}
