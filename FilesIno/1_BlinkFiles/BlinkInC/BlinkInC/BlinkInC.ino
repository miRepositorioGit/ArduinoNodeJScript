/** 
 * BlinkInC.ino  Turns an LED on for one second, then off for one times, repeatedly. 
 * 
 *  -Muestra como hacer uso de la estructura int main(void), while(1), en lugar de la estructura 
 *          void setup(), void loop(). de Arduino.
 *  -Muestra como declarar bibliotecas nativas de la arquitectur AVR. 
 * 
 * Test.c
 * fuente:
 *        Created: 15-09-2018 07:24:45 PM
 *        Author : Arnab Kumar Das
 *        Website : www.ArnabKumarDas.com
 *   while (1) Vs. for (;;) Is there a speed difference?    
 *   https://stackoverflow.com/questions/885908/while-1-vs-for-is-there-a-speed-difference     
 */ 

#define F_CPU 16000000UL // Defining the CPU Frequency for Delay Calculation in delay.h 
// Arduino UNO used a 16Mhz Crystal as Clock Source
#include <avr/io.h> // Contains all the I/O Register Macros
//#include <avr/util.h> // Generates a Blocking Delay
#include <util/delay.h>


//void setup() {
// 
//}
//void loop() {
//}

 int main(void)
 {
     DDRB |= 1<<5; // Configuring PB5 as Output
	 DDRB = DDRB | 0X11;
     //while (1)
     for(;;)
     {
		 //PORTB = PORTB | 0X10;
         PORTB |= 1<<PORTB5;    // Writing HIGH to PB5
         _delay_ms(1000);       // Delay of 1 Second
         PORTB &= ~(1<<5);      // Writing LOW to PB5
         _delay_ms(1000);       // Delay of 1 Second
     } 
}
// 
