/*
 * Archivo: BarraGrafica.ino
 * Enciende un arreglo de leds en proporción a la relación:
 * 
 *   magnitud = map(val, in_min, in_max, out_min, out_max);
 *   
 *   magnitud = (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 *   
 *   
 * Fuente: Bargraph sketch 
 * Orelly.ArduinoCook2ndEd 7.5  Sequencing Multiple LEDs:
 * Creating a Bar Graph.
 * https://www.arduino.cc/en/Reference/Map
*/

const int NbrLEDs = 8;
const int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9};
const int analogInPin = 0; // Analog input pin connected to variable resistor
const int wait = 30;
// Swap values of the following two constants if cathodes are connected to Gnd
const boolean LED_ON = LOW;
const boolean LED_OFF = HIGH;
int sensorValue = 0; // value read from the sensor
int ledLevel = 0; // sensor value converted into LED 'bars'

void setup() {
                Serial.begin(9600);
                for (int led = 0; led < NbrLEDs; led++){
                pinMode(ledPins[led], OUTPUT); // make all the LED pins outputs
                }
              }
              
void loop() {
            sensorValue = analogRead(analogInPin); // read the analog in value
            ledLevel = map(sensorValue, 0, 1023, 0, NbrLEDs); // map to the number of LEDs

            //Serial.println(sensorValue);
            Serial.println(ledLevel);
            delay(100);
            
              for (int led = 0; led < NbrLEDs; led++){
                if (led < ledLevel ) {
                    digitalWrite(ledPins[led], LED_ON); // turn on pins less than the level
                    }
            else {
                    digitalWrite(ledPins[led], LED_OFF); // turn off pins higher than the level
                }
            }
}
