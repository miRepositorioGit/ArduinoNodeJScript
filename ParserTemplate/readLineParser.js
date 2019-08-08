/**readLineParser.js   recibe por el puerto serie un byte, lo muestra en consola.
 *      |--txdCnt.ino  contabiliza visualiza y envia dato por el puerto serie.
  
 *      Descripción:
 *      Script codifocado en javaScript.  Recine por el puerto serie un byte
 * y lo muestra en la consola de la terminal.
 *
 *      Muestra el uso y la operación de parser, en la transformación de 
 * streams en el proceso de incomming data.  
 * 
 *  Readline Parser.    A transform stream that emits data after a 
 *                      newline delimiter is received. 
 *                      Use a delimiter: '\r\n'
 *                      https://serialport.io/docs/api-parser-readline
 * 
 *  Ready Parser.       A transform stream that waits for a sequence 
 *                      of "ready" bytes before emitting a ready event 
 *                      and emitting data events.
 *                      https://serialport.io/docs/api-parser-ready
 * 
 * Ejecución:
 * 
 *        \ParseTemplate>node readLineParser.js  
 *     |            |              |             
 *     |            |              |---script 
 *     |            |------------------capteta contenedora
 *     |-------------------------------línea de comandos  
 * 
 * versión  serialport": "7.1.5"  agosto 2019.
 */

/**stream interface by requiring the serialport 
 * package which comes with a default set of 
 * Bindings and Parsers.
 */
var SerialPort = require('serialport');  // To get a default set of Bindings and Parsers
const Ready    = require('@serialport/parser-ready');
const Readline = require('@serialport/parser-readline');

var   comName = 'COM10';                    // path of serial port you want open
/** crea un objeto para el path definido
 * @param path of serial port you want open
 * @param openOptions serial port configurations 
 * @param callback called after a commection is opened
 *   */
const port = new SerialPort(comName,
            { 
                    baudRate: 9600,
                    dataBits: 8,
                    stopBits: 1,
                    parity:'none'
            },
            function(err) 
            {
                if (err) 
                {
                      return console.log('Error on write: ', err.message);
                }
            });

/**A transform stream that emits data each time a byte 
* sequence is received. To use the Delimiter parser, 
* provide a delimiter as a string, buffer, 
* or array of bytes. Runs in O(n) time.
* Creating the parser and piping
*/
const parser = port.pipe(new Readline({ delimiter: '\r\n' }));


/** */


/**retrives a list of available serial ports */
   //   listAvailableSerialPorts();

/** Wait to receive "READY" from Arduino */            
        readyParser();

/**Listening for the data event puts the port in flowing mode. */
        parser.on('data',  function (data) 
        {
            console.log('\t Data:', data)
        });

/** */

    


/**
 * Some devices, like the Arduino, reset when you open 
 * a connection to them. In such cases, immediately 
 * writing to the device will cause lost data as they 
 * wont be ready to receive the data. 
 * This is often worked around by having the Arduino 
 * send a "ready" byte that your Node program waits 
 * for before writing.
 * https://serialport.io/docs/api-parser-ready
 */ 
function readyParser(){
const parser = port.pipe(new Ready({ delimiter: 'READY' }))
      parser.on('ready', () => 
      {
          return console.log('\t the ready byte sequence has been received');
      });
}

/** retrives a list of available serial 
 * ports with metadata 
 */
function listAvailableSerialPorts()
    {
        SerialPort.list().then
        (
        ports => ports.forEach(console.log),
        err => console.error(err)
        );
    };

/**Open errors will be emitted as an error event */
        port.on('error', function(err) 
    {
        console.log('Error: ', err.message)
    });    
