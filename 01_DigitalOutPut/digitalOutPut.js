/** 01_DigitalOutPut.js    recibe, envia datos vía puerto serie, regula magnitud analógica.
  *    |
  *    |--interface.js	      interface/enlaza elemento slider con led_control.js	
  *    |--interface.html	  presenta la interface gráfica en el browser
  *
  *   Dos elementos button html, montados en una interface gráfica Html, controlan 
  * los estados binarios en un puerto de una tarjeta Arduino. 
  * 
  *   |on|   |off|
  *   HTML interface--->3000------>Web server<--------->COM10<-->Arduino----PD3,IO3---1kOhm---Led---0V.
  *     |                             |                            |                          
  *	    |-- interface.html            |--01_DigitalOutPut.js       |-- 01_DigitalOutPut.ino      
  *                                   |--interface.js  
  * 
  * 
  * Instalación de  dependencias
  * 
  * >npm init                           
  * >npm install express              instala middleware para el servidor
  * >npm install serialport --save    instala middleware para el puerto serial
  * 
  * Ejecución de servidor. En en la carpeta del proyecto y en línea de comandos
  * 
  * >node led_control.js
  * 
  * Modos de operación:
  * 
  * -Move cursor at graphical interface:
  *      localhost:3000/ <---Solicitud del cliente
  *       
  *       interface.html        01_DigitalOutPut.ino
  *             
  *       |on| |off| 											
  *         |    |--- LOW  +=> PD3,IO3---1kOhm---Led---0V.
  *         |---------HIGH +=> PD3,IO3---1kOhm---Led---0V.
  * 
  * = COM10     : tarjeta arduino 
  * + port:3000 : webServer
  * 
  * 
  * -Type command in your browser:
  * 
  *         
  *         http://192.168.1.73:3000/on
  *                         |        |-- HIGH --> PD3,IO3---1kOhm---Led---0V.
  *                         |----------- Dirección IPv4.
  * 
  *         http://localhost:3000/off
  *                         |        |-- LOW --> PD3,IO3---1kOhm---Led---0V.
  *                         |----------- loopback
  *   
  * 
  *   fuente:
  *   -Marco Schwartz. Building Smart Homes with Raspberry Pi Zero.  
  *     Chapter 4. Lamp_control.
  *     https://books.google.com.mx/books?id=kJbcDgAAQBAJ&pg=PP7&lpg=PP7&dq=marco+schwartz+building+smart+homes+with+raspberry+pi+zero+pdf&source=bl&ots=KF91FFd4Fy&sig=ACfU3U3Tbc3NbRmE59YmI7E3cv5o_rG7QA&hl=es-419&sa=X&ved=2ahUKEwiaiYSv487jAhVHLKwKHaOTADcQ6AEwCHoECAkQAQ#v=onepage&q=marco%20schwartz%20building%20smart%20homes%20with%20raspberry%20pi%20zero%20pdf&f=false
  *     https://github.com/openhomeautomation/smart-homes-pi-zero/tree/master/04
  * 
  *   -Ramos Oliva Rubén.  Internet of thinks programming with JavaScript
  *     ISBN 978-1-78588-856-4 Packt publishing 2017.		
  *
  */

/** express application
 *  app: is an object calling the top-level express() fuction
 */
var express = require('express');
var serialport = require('serialport');
var app = express();
var ReadLine = serialport.parsers.Readline;
var portName = "COM10";
var myPort = new serialport(portName, 9600);
var parser = myPort.pipe(new ReadLine({ delimiter: '\n' }));	


// variables
current = 0;

parser.on('open', function () {
  console.log('connection is opened');
});

/** direccionamiento 
 * objeto de solicitud (req)
 * objeto de respuesta (res)
 * req argumento de solicitud Http
 * res argumento de respuesta Http
 */

/** hace uso de directorio con archivos 
*   estáticos contenidos en 'public'
*/ 
      app.use(express.static('public'));

/** webServer recibe una petición 
 *         envia ruta de webPage
 * '/'   : root path  interface.html
 * '/doc': documentation.html
 * '/on' : payLoadData
 * 
 * */
      app.get('/', function (req, res) 
      {
        res.sendFile(__dirname + '/public/interface.html'); // root path
      });

     
/**Load data from the server using 
 * a HTTP GET request.
 * A plain object or string that 
 * is sent to the server with the 
 * request.
 */
  app.get('/on', function (req, res) 
      {
      // Set LED
        //payLoadBinary = req.query.payLoadData;
      // Answer
        answer = {status:1};
        res.json(answer);
      // envia vía serialPort payLoadData
        process.stdout.write('\033c'); // limpia pantalla 
        console.log("\n");
        console.log("\t Estado binario: " + "on" + "\n");
        sendToSerial("on" + "\n");
      });
/**Load data from the server using 
 * a HTTP GET request.
 * A plain object or string that 
 * is sent to the server with the 
 * request.
 */
app.get('/off', function (req, res) 
{
// Set LED
  //payLoadBinary = req.query.payLoadData;
// Answer
  answer = {status: 0};
  res.json(answer);
// envia vía serialPort payLoadData
  process.stdout.write('\033c'); // limpia pantalla 
  console.log("\n");
  console.log("\t Estado binario: " + "off" + "\n");
  sendToSerial("off" + "\n");
  });

app.get('/', async(req,res) => {
  const promise = new Promise((resolve,reject)=>{
    myPort.on('data', (data,err) => {
      if (err) {
        reject(err);
        return;
      }
      resolve(data[0]);
      });
     })
     const data = await promise;
     res.json(data);
     res.send(data);
     console.log("rxd:"+data)
    });

/** manejador de errores */
    app.use(function(req, res, next) 
      {
      res.status(404).send('Sorry cant find that!...');
      });

    app.use(function(err, req, res, next) 
      {
      console.error(err.stack);
      res.status(500).send('Something broke!');
      });

/** RxD recibe carga útil de serialPort
                * @param callback recibe data y convierte en entero
                */
               parser.on('data', function (data) 
               {
                 console.log("\t Receiving from serial: " + data);

                app.get('/rxd',function(req,res)
                {
                  answer={Rxd:data};
                  res.json(answer);
                  res.send(data);
                });
               }); 

/** TxD envia carga útil serialPort
  * @param {*} data payLoaData
 */
function sendToSerial(data) {
 console.log("\t Sending to serial: " + data);
 myPort.write(data);
};

// Start server
app.listen(3000, showInfo());

function showInfo()
    {
        console.log(' Control binario de salida digital'); 
        console.log('open browser at  http://localhost:3000/ ');
        console.log('open browser at  http://localhost:3000/on');
        console.log('open browser at  http://localhost:3000/off');
    };
