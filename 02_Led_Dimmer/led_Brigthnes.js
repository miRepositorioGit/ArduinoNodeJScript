/** led_Brigthness.js    recibe, envia un dato vía puerto serie, regula un magnitud analógica.
  *    |
  *    |--interface.js	    interface/enlaza elemento slider con led_control.js	
  *    |--interface.html	  presenta la interface gráfica en el browser
  *
  *   Un elemento bar-slider montado en una interface gráfica html, es controlado manualmente
  *   controla la intensidad de brillo en una salida analógica de un microcontrolador.
  *
  *       |=#========|											
  *      min		    max	  
  *   HTML interface--->3000--->Web server<--->COM10<----->Arduino-----PWM,PD3,IO3---1kOhm---Led---0V.
  *	    |                           |                         |
  *     |--interface.html           |-- Led_control.js        |--serialReadDemo.ino     
  *                                 |-- interface.js  
  * 
  * Instalación de dependencias
  * 
  * >npm init
  * >npm install express                    instala middleware para el servidor
  * >npm install serialport --save          instala middleware para el puerto serial
  * 
  * Ejecución de servidor    En en la carpeta del proyecto y en línea de comandos
  * 
  * >node led_Brigthnes.js
  * 
  * Modos de operación:
  * 
  * -Move cursor at graphical interface:
  *      localhost:3000/
  *               
  *       |=#========|			<---Slider bar
  *      min		    max	  
  * 
  * -Command in your browser:
  * 
  *         Your IPv4:
  *         http://192.168.1.73:3000/set?payLoadData=200
  * 
  *        Hostname: 
  *         http://localhost:3000/set?payLoadData=100
  *
  *   fuente:
  *   Marco Schwartz. Building Smart Homes with Raspberry Pi Zero.  
  *   Chapter 4. Controlling LEDs.
  *   https://books.google.com.mx/books?id=kJbcDgAAQBAJ&pg=PP7&lpg=PP7&dq=marco+schwartz+building+smart+homes+with+raspberry+pi+zero+pdf&source=bl&ots=KF91FFd4Fy&sig=ACfU3U3Tbc3NbRmE59YmI7E3cv5o_rG7QA&hl=es-419&sa=X&ved=2ahUKEwiaiYSv487jAhVHLKwKHaOTADcQ6AEwCHoECAkQAQ#v=onepage&q=marco%20schwartz%20building%20smart%20homes%20with%20raspberry%20pi%20zero%20pdf&f=false
  * 
  *   Ramos Oliva Rubén.  Internet of thinks programming with JavaScript
  *   Cápitulo 6. Controlling the LED from an interface.
  *   ISBN 978-1-78588-856-4 Packt publishing 2017.		
  *
  */

/** express application
 *  app: is an object calling the top-level express() fuction.
 *  serialport: is an object to generate instances.
 */
var express = require('express');
var serialport = require('serialport');

var app = express();
var ReadLine = serialport.parsers.Readline;
var portName = "COM10";                           // tarjeta de desarrollo Arduino
var myPort = new serialport(portName, 9600);
var parser = myPort.pipe(new ReadLine({ delimiter: '\n' }));	

/** manejador de error en la apertura del puerto */

myPort.write('main screen turn on', function(err) 
    {
        if (err) {
                  return console.log('Error on write: ', err.message)
                }
        console.log("\t\t" + portName + ' is open');
    });

// Open errors will be emitted as an error event
myPort.on('error', function(err) 
      {
        console.log('Error: ', err.message)
      });


/** hace uso de directorio con archivos 
*   estáticos contenidos en 'public'
*/ 
      app.use(express.static('public'));

/**routing
 * @param '/' root path
 * @param function envia path de interface.htm 
 */
      app.get('/', function (req, res) 
      {
        res.sendFile(__dirname + '/public/interface.html');
      });

/** recupera y envia posición del slicer */
      app.get('/set', function (req, res) 
      {
      // recupera posición del slider 
        duty = req.query.payLoadData;
        
      // convierte a formato JSON y envía
        answer = {Duty:duty};
        res.json(answer);
      // muestra y envia dato por el puerto serie
        showAtConsole(req.query.payLoadData);
        sendToSerial(req.query.payLoadData);
      });

/** manejador de errores */
        // págian no encontrada
      app.use(function(req, res, next) 
      {
          res.status(404).send('Sorry cant find that!...');
      });
        // Internal Server Error
      app.use(function(err, req, res, next) 
      {
        console.error(err.stack);
        res.status(500).send('Something broke!');
      });

/**muestra dato en consola 
 * @param arg0 dato
*/
function showAtConsole(arg0)
    {
        process.stdout.write('\033c'); // limpia pantalla 
        console.log("\n");
        console.log("\t posición: " + arg0);
    };

/**  transmite dato por el puerto serial */
function sendToSerial(arg0) 
    {
      console.log("\t sending to serial: " + arg0);
      myPort.write(arg0); 
    }; 

/** recibe dado del puerto serial */
    parser.on('data', function (data) 
        {
          console.log("\t receiving from serial: " + parseInt(data, 10));
        });

/** inicia servidor, escucha solicitudes 
 * @param puerto de conexión
 * @param callback
*/
      app.listen(3000, showInfo(3000));

/** informa puerto de conexión 
 * @param puerto
*/
  function showInfo(arg0)
        {
            console.log('\t open browser at  http://localhost:'+arg0);
            console.log(' \t Muestra la posición de un SLIDER. ');
            console.log(' \t CTRL + c retornar a consola de comandos. ');
        };  
