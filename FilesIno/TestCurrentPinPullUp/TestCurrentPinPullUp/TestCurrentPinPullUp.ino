/**
 * TestCurrentPinPullUp.ino 
 *    Registra la magnitud de corriente del arreglo pull-up en PD2,IO2
 *    Muestra la implementación de blinkLed in pure C. Enciende-apaga led empotrado.
 *    Muestra configuración de entrada digital con pull_up.
 *    
 * Descripción:
 *    Lee el interruptor en PD2*. 
 *    Si, PIND2==4.  blinkLed(), Imprime estado leido
 *    Entonces       Imprime estado leido 
 *    *Pull-up
 *    
 * Hardware:   
 *    PIND2*[PD2,IO2]---pushButton----0V
 *    PORTB5[PB5,IO13]--embededLed----0V
 *    
 *    DC current per I/O pin 40.0 mA [3]
 *    I/O pin pull-up resistor RPU 20-50 kOhm [3]
 *    
 *    3. Although each I/O port can sink more than the test conditions (20mA at VCC = 5V, 10mA at VCC = 3V) under steady
 *    state conditions (non-transient), the following must be observed:
 *    ATmega328P:
 *        1] The sum of all IOL, for ports C0 - C5, should not exceed 100mA.
 *        2] The sum of all IOL, for ports B0 - B5, D5 - D7, XTAL1, XTAL2 should not exceed 100mA.
 *        3] The sum of all IOL, for ports D0 - D4, should not exceed 100mA.
 *        If IOL exceeds the test condition, VOL may exceed the related specification. Pins are not guaranteed to sink current
 *        greater than the listed test condition.
 *    4. Although each I/O port can source more than the test conditions (20mA at VCC = 5V, 10mA at VCC = 3V) under steady
 *        state conditions (non-transient), the following must be observed:
 *    ATmega328P:
 *        1] The sum of all IOH, for ports C0 - C5, D0- D4, should not exceed 150mA.
 *        2] The sum of all IOH, for ports B0 - B5, D5 - D7, XTAL1, XTAL2 should not exceed 150mA.
 *        If IIOH exceeds the test condition, VOH may exceed the related specification. Pins are not guaranteed to source current
 *        greater than the listed test condition.
 *    
 * Software:   
 *    Arduino Nano, Atmega328P(OldBootloader) en COM6.
 *    Programmer Type : Arduino
 *    Description     : Arduino
 *        
 * fuente: 
 *    [1] gmoon. How do you read a digital input on an avr in c? Available: https://www.instructables.com/community/How-do-you-read-a-digital-input-on-an-avr-in-c/
 *    [2] Balau. Programming Arduino Uno in pure C Available: https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/
 *    [3] Atmega328P[Datasheet], 7810D–AVR–01/15, 28.2 DC Characteristics (Continued) pp. 259
*/

#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS_ON  100
#define BLINK_DELAY_MS_OFF 100
#define VECES_TEST         2
#define INPORTD2 (PIND & _BV(PD2))

#define INPUT(n) (PIND & _BV(n))

void blinkLed();
void testEmbeddedLed();

void setup() {
    testEmbeddedLed();
    Serial.begin(9600);
    Serial.print(" Done ");
    
    /* set IO2 input Pullup  [1]*/
          PORTD = (1<<PD2);
          DDRD  &= ~_BV(DDD2);

    /* set pin 5 of PORTB for output [1]*/
          DDRB |= _BV(DDB5);
}

void loop() {
    /* lee PIND2 */             
          if(PIND & _BV(PD2)){ blinkLed();}
          Serial.println(PIND & _BV(PD2));    
}


/* turn on-turn off embedded led [2]  */
void blinkLed()
{ 
   /* set pin 5 high to turn led on */
        PORTB |= _BV(PORTB5);
        _delay_ms(BLINK_DELAY_MS_ON);
 
  /* set pin 5 low to turn led off */
        PORTB &= ~_BV(PORTB5);
        _delay_ms(BLINK_DELAY_MS_OFF);
}

/* test embedded led */
void testEmbeddedLed(){
  uint8_t aux = 0;
    for(aux=0;aux < VECES_TEST ;aux++){blinkLed();}
 }
