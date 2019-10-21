/*
 * myLibrary.cpp - Define funciones
 * Created by Martín Cordero mi.cuenta.correo.en@gmail.com on 18/06/19
 * Revision #2 - See readMe.txt 
 */
 
 #include "Arduino.h"
 #include "asm.h"
 #define myLibrary.h
 
 #define BLINK_DELAY_MS_ON  500
 #define BLINK_DELAY_MS_OFF 500

/* enciende-apaga pin5 en el puerto B */ 
 void blinkLed(){
	       //  PORTB |= (1<<5);
         //  PORTC |= (1<<0);
         //  PORTC = PORTC | 0B00000001;
      ASM_SBI(PORTB, PB5);
      ASM_SBI(PORTC, PC0);
      //digitalWrite(13,OUTPUT);
      _delay_ms(BLINK_DELAY_MS_ON);
      
              PORTB &= ~(1<<5);
              PORTB = PORTB & 0B11101111;
            // PORTC &= ~(1<<0);
            // PORTC = PORTC & 0B11111110;
      ASM_CBI(PORTB, 5);
      _delay_ms(BLINK_DELAY_MS_OFF);
 }

/* configura recursos periféricos */
 void configRecursos(){
         DDRB |= (1<<DDB5);  // output PB5,IO13 
      // DDRC = DDRC | 0x01; // output PC0,ADC0

}
