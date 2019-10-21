/*
 * Archivo: ReadAnalog.ino
 * Muestra la lectura de una magnitud analógica.
 *  0V <= volts <= 5.0
 * val : referenceVolts = Volts : 1023
 * Warning - do not connect more than 5 volts directly to an Arduino pin.
 */
const float referenceVolts = 5.0; // tensión eléctrica límite superior para la tarjeta Arduino.
const int canal_0  = 0;           // defiene canal de entrada analógica.
int valorLeidoXcanal_0;           // resguarda el valor leido
float volts;

void setup()
            {
              // configura recursos periféricos
              Serial.begin(9600);
            }

void loop()
            {
            valorLeidoXcanal_0 = analogRead(canal_0); // lectura del valor desde el sensor
            volts = (valorLeidoXcanal_0 / 1023.0) * referenceVolts; // calcula la relación-proporción
            Serial.println(volts); // imprime en pantalla
            }
  

            
