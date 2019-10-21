/**
 * BlinkInC_1.ino
 *        Muestra como configurar recursos para encender-apagar un bit en un puerto.
 *        Resguarda funciones en bibliotecas
 *        Muestra como usar macro-instrucciones orientadas a la administración de estados binarios en 
 *        registros de 8 bits.
 * Descripción:       
 *        Configura: DDRB5<-1.
 *        Escribe: 1 PORTB5<-1, 
 *                 2 _delay_ms(),
 *                 3 PORTB5<-0 
 *                 4 _delay_ms()
 *  Software:               
 *        Programmer Type : Arduino
 *        Description     : Arduino
 *        Hardware Version: 2
 *        Firmware Version: 1.16
 *  
 *  Hardware:
 *        PORTB5[PB5,IO13]--embededLed----0V
 *  
 *        Arduino Nano, ATmega328P(oldbootloader en com 6)
 *        Using Port                    : COM6
 *        Using Programmer              : arduino
 *        Overriding Baud Rate          : 57600
 *        AVR Part                      : ATmega328P
 *        
 *    fuente:
 *    TestCurrentPinPullUp.ino
*/

#include <avr/io.h>
#include <util/delay.h>

#include "myLibrary.h"

void configRecursos();

void setup() {
           configRecursos();  
}

void loop() {
          blinkLed();
}
