/**01_DigitalOutPut.ino 
 * 
 *    Enciende-apaga salida digital en un puerto, dependiendo dato recibido.    
 *    turn on - turn off digital output depending  token + "\n" on serial port buffer reception. 
 *    
 *  Descripción:
 *  
 *    El control de encendido-apagado está en función del dato recibido 
 *    por el puerto serial más nueva línea.
 *    
 *    Dato recibido               Acción
 *      token
 *     "on\n"               pone en alto salida digital   // PD3 <- 1
 *     "off\n"              pone en bajo salida digital   // PD3 <- 0
 *     "on"|"off"           loop back
 *     "ON\n"|"OFF\n"       loop back
 *     "abc" |"cualquiera"  loop back
 *     
 *  Hardware:   
 *  
 *         "on\n" :  HIGH -->  PWM,PD3,IO3---1kOhm---Led---0V.
 *         "off\n" : LOW  -->  PWM,PD3,IO3---1kOhm---Led---0V.
 *    
 * fuente:
 * USANDO EL PUERTO SERIE DEL ARDUINO
 *  http://diymakers.es/usando-el-puerto-serie-del-arduino/
 * Arduino - How can i get a string command and match it with if statements?
 *  https://stackoverflow.com/questions/19245318/arduino-how-can-i-get-a-string-command-and-match-it-with-if-statements
*/

#define MAX_SIZE  10

char bufferIn[MAX_SIZE]; 
uint8_t index = 0;  

void setup()
{
  index = 0;                 //   
  Serial.begin(9600);        // begin communicaton
  DDRD |= (1<<PD3);          // PWM,PD3,IO3---1kOhm---Led---0V.
  PORTD &= ~(1<<PD3);        // PD3 <- 0 
}

void loop()
{
  if(Serial.available()) 
  {
     memset(bufferIn, 0,sizeof(bufferIn));    // initialize reception buffer 
     while(Serial.available()>0) 
      {
          delay(5); 
          bufferIn[index] = Serial.read();
          index++;
      }

      Serial.print(bufferIn);             //  loopback data input

 /** compare reception buffer with token  */
      
     if (strcmp(bufferIn, "on\n") == 0)
        { 
          PORTD |= 1<<PD3;                  // PD3 <- 1
        }
     else if (strcmp(bufferIn, "off\n") == 0)
        { 
          PORTD &= ~(1<<PD3);               // PD3 <- 0
        }
      else
        {
          memset(bufferIn, 0,sizeof(bufferIn));
        }
  }
  index = 0;
}
