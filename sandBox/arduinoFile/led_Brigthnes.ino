/**serialReadDemo.ino recibe y transmite datos via stdin-stdout.
 * 
 *    Modula el ancho de pulso en una salida digital, en función del dato recibido. via stdin-out 
 *    
 * fuente:
 * USANDO EL PUERTO SERIE DEL ARDUINO
 * http://diymakers.es/usando-el-puerto-serie-del-arduino/
*/

#define pin3Pwm  3
#define MAX_SIZE  10

char bufferIn[MAX_SIZE]; 
uint8_t index = 0;  
uint8_t temporal = 0;  

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(50);
  pinMode(3, OUTPUT);    // PWM,PD3,IO3---1kOhm---Led---0V.
  PORTD &= ~(1<<PD3); 
}
 

void loop()
{
  if(Serial.available()) 
  {
     memset(bufferIn, 0,sizeof(bufferIn));
     while(Serial.available()>0) 
      {
          delay(5); 
          bufferIn[index] = Serial.read();
          index++;
      }
    temporal = atoi(bufferIn);
    Serial.println(temporal);
    analogWrite(pin3Pwm, temporal);  
    index = 0;
  }
 }
