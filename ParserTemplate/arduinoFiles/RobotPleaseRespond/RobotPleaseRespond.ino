/**
 * RobotPleaseRespond.ino responde a una cadena de caracteres
 * 
 *  Muestra como comparar una cadena de caracteres (mensaje)con la función strcmp().
 *  
 *  Al recibir un mensaje "ROBOT PLEASE RESPOND \n" via puerto serie, se registran en un arreglo
 *  es comparado el contenido con el token de autenticación y cunado es 
 *  verdadero envia una reapuesta afirmativa "ok".
 *  
 *  muestra el uso strcmp(cmd, "LEDON").
 *    
 *  int strcmp (const char* str1, const char* str2); 
 *  
 *   The strcmp( ) function compares two strings and returns 
 *   
 *  0          if both strings are identical. 
 *  negative   if the ASCII value of first unmatched character is less than second.
 *  positive integer   if the ASCII value of first unmatched character is greater than second.
 *  
 *  https://www.programiz.com/c-programming/library-function/string.h/strcmp
 *  
 *  Recepción     Local constant
 *  
 *    <"ROBOT PLEASE RESPOND" =="ROBOT PLEASE RESPOND" ?> --si-- {PB5 <- (1,0), TxD <- "ok"
 *    
 *    Configurar la hyperteminal con NUEVA LINEA LF
 * 
 * fuente:
 * http://helloraspberrypi.blogspot.com/2014/03/nodejssocketioserialport-web-app-to.html
 * http://arduino-er.blogspot.com/2014/03/web-app-of-nodejs-to-control-raspberry.html
*/

#define   LED_EMPOTRADO   13
#define   MAX_CMD_LENGTH  3
#define   RXD_MENSAJE_UNO     "ok \n"
#define   LED_OFF     "Command received: LEDOFF"
#define   DESCONOCIDO "Command received: unknown!"
#define   NEW_LINE       '\n'
#define   LAST_CHARACTER '\0'

//void readArray(char* ,uint8_t);

uint8_t cmdIndex = 0;          // indice arreglo de recepción
char cmd[MAX_CMD_LENGTH];     // buffer de recpeción

void printArray(void);        // imprime contenido del arreglo de recepción

void setup() {
          Serial.begin(9600);
          //Serial.println("HAJIME");
          DDRB |= (1<<PB5);           // PB5,IO13 as digital output
          cmdIndex = 0;
          memset(cmd,0,sizeof(cmd));  // inicializa arreglo de recepción
}

void loop() {
          if ( Serial.available() )
            {
              char byteIn = Serial.read(); // lee un caracter ascii
              cmd[cmdIndex] = byteIn;      // resguarda caracter 

               /* */
              if(byteIn == NEW_LINE)      
                {
                  cmd[cmdIndex] = LAST_CHARACTER;
                  //Serial.println(cmd);            //print buffer incoming 
                  Serial.flush();                 //removed any buffered incoming serial data.
                  cmdIndex = 0;

                  if (strcmp(cmd, "ok") == 0)  
                        {
                        Serial.println(1);
                        PORTB |= (1<<PB5);
                        }
                  else if (strcmp(cmd, "LEDOFF") == 0)  
                        {
                        Serial.println(LED_OFF);
                        PORTB &= ~(1<<PB5);
                        }
                  else {
                        memset(cmd,0,sizeof(cmd));    // inicializa arreglo de recepción
            //printArray();
                        Serial.println(DESCONOCIDO);
                       }  
              }
              else
              {
                if(cmdIndex++ >= MAX_CMD_LENGTH)
                  {
                    memset(cmd,0,sizeof(cmd));
                    cmdIndex = 0;
                  }
              }
            }
}

//void readArray(char* arrayChar[],uint8_t tamano){
//  uint8_t indx = 0; 
//        for(indx = 0;indx <= tamano;indx++) 
//          { 
//          Serial.println(arrayChar[indx]);
//          }
//  } 


void printArray(){
    Serial.println("\nElements in array are: ");  
        for(uint8_t i=0; i<10; i++)  
        {  
        //Serial.print(cmd[i]);    
        Serial.print(cmd[i],HEX);  
        }
        Serial.println(""); 
}
