/*File: TestServo.ino
Muestra el movimiento escalonado de un servomotor conectado a un pin de salida digital PWM
el dato es recibido por el Arduino Uno Vía puerto serie.  
Este dato es filtrado por intervalos.

Si la computadora envía un 0 la posición del servomotor es  0 [°].
Si la computadora envía un 1 la posición del servomotor es 10 [°].
Si la computadora envía un 2 la posición del servomotor es 20 [°].
Si la computadora envía un 3 la posición del servomotor es 30 [°].
Si la computadora envía un 4 la posición del servomotor es 40 [°].
Si la computadora envía un 5 la posición del servomotor es 50 [°].
Si la computadora envía un 6 la posición del servomotor es 60 [°].
Si la computadora envía un 7 la posición del servomotor es 70 [°].
Si la computadora envía un 8 la posición del servomotor es 80 [°].
Si la computadora envía un 9 la posición del servomotor es 90 [°].

*/

#include <Servo.h> 
   Servo myservo;  // crea un objeto servo 
 
int pos = 0;     // variable to store the servo position 
int  val =  0;   
void setup(){ 
  myservo.attach(3);      // attaches el servo en el pin 3
  Serial.begin(9600);     // inicializa la comunicación serial
  Serial.println("dONE"); // imprime un mensaje 
  myservo.write(pos);       // inicializa servo en posición inicial
  } 
 
void loop() { 
   if(Serial.available() > 0) { // espera una recepción desde la computadora
        val = Serial.read();    // realiza una lectura del dato recibido 
        Serial.print(val);      // imprime en pantalla el dato recibido
        // compara el dato entre los intervalos definidos
        // intervalo           imprime un tabulador: imprime un numero: escribe una posición              
    if (val > 47 && val < 49) { Serial.print("\t"); Serial.println("0"); myservo.write(0);  }
    if (val > 48 && val < 50) { Serial.print("\t"); Serial.println("1"); myservo.write(10); }
    if (val > 49 && val < 51) { Serial.print("\t"); Serial.println("2"); myservo.write(20); }
    if (val > 50 && val < 52) { Serial.print("\t"); Serial.println("3"); myservo.write(30); }
    if (val > 51 && val < 53) { Serial.print("\t"); Serial.println("4"); myservo.write(40); }
    if (val > 52 && val < 54) { Serial.print("\t"); Serial.println("5"); myservo.write(50); }
    if (val > 53 && val < 55) { Serial.print("\t"); Serial.println("6"); myservo.write(60); } 
    if (val > 54 && val < 56) { Serial.print("\t"); Serial.println("7"); myservo.write(70); }
    if (val > 55 && val < 57) { Serial.print("\t"); Serial.println("8"); myservo.write(80); }
    if (val > 56 && val < 58) { Serial.print("\t"); Serial.println("9"); myservo.write(90); }
   }
 } 
