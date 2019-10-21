/**
 * Blink_1.ino Muestra declaraci�n de constantes.
 * Blink.ino   Turns an LED on for one second, then off for one times, repeatedly.
 * 
 *  Muestra como hacer uso de las directivas del pre-procesador.
 *  
 *   Turns an LED on for one second, then off for one second, repeatedly.
 *
 * Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
 * it is attached to digital pin 13, LED_BUILTIN is set to
 * the correct LED pin independent of which board is used.
 *  
 *  Fuente: S. Fitzgerald,A. Guadalupi,C. Newman. 8 Sep 2016. Disponible available:
 *       http://www.arduino.cc/en/Tutorial/Blink 
 *  
 *  
*/
#define LED_BUILTIN 13
#define TIEMPO_ENCENDIDO  1000                   //constante para variar tiempo encendido
#define BLINK_DELAY_MS_OFF (TIEMPO_ENCENDIDO/2)

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(TIEMPO_ENCENDIDO);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(BLINK_DELAY_MS_OFF);                       // wait for a second
}
