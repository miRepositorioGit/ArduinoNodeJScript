/**
 * txdCnt.ino           contabiliza visualiza y envia dato por el puerto serie.
 * 
 * Descripción: 
 *              Incrementa unitariamente y transimte un byte.
 *              
 *              es necesario emplear el delimitador "\n" en la transmisión del dato.
 *      
 *      
 *      avrdude: Version 6.3-20171130
 *        
 *        Using Port                    : COM10
 *        Using Programmer              : arduino
 *        Overriding Baud Rate          : 57600
 *        AVR Part                      : ATmega328P
 *        
 *        Programmer Type               : Arduino
 *        Description                   : Arduino
 *        Hardware Version              : 2
 *        Firmware Version              : 1.16
 *        Vtarget                       : 0.0 V
 *        Varef                         : 0.0 V
 *        Oscillator                    : Off
 *        SCK period                    : 0.1 us
 *        
 *    
 *        Some devices, like the Arduino, reset when you open 
 *        a connection to them. In such cases, immediately 
 *        writing to the device will cause lost data as they 
 *        wont be ready to receive the data. 
 *        This is often worked around by having the Arduino 
 *        send a "ready" byte that your Node program waits 
 *        for before writing.
 */   
 

#include <util/delay.h>
#define timeTxd  75

uint8_t txdCnt = 0;

void  blinkLed(uint8_t );

void setup() {
                DDRB |= (1<<PB5);
                Serial.begin(9600);
                Serial.println("READY"); 
                //Serial.setTimeout(400);
    }

void loop() {
                Serial.println(txdCnt++);  // incluir dato + \n
                delay(timeTxd);
                blinkLed(timeTxd);
                Serial.flush();
}

/** enciende-apaga led
 *  @param arg0 tiempo entre eventos
*/
void blinkLed(uint8_t arg0)
    {
      PORTB |=(1<<PB5);
      _delay_ms(arg0);
      PORTB &= ~(1<<PB5);
      _delay_ms(arg0);
     };
