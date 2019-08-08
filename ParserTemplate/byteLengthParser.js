/**byteLengthParser.js   recibe por el puerto serie un lote de bytes, lo muestra en consola.
 *      |--txdCnt.ino  contabiliza visualiza y envia dato por el puerto serie.
 * 
 * 
 * 
 *      Descripción:
 *      Script codifocado en javaScript.  Recibe por el puerto serie un 
 *      lote de bytes y lo muestra en la consola de la terminal.
 * 
 
 *      Muestra el uso y la operación de parser, en la transformación de 
 * streams en el proceso de incomming data.  
 * 
 *  ByteLength Parser   Emit data every number of bytes.
 *                      Atransform stream that emits data 
 *                      as a buffer after a specific number 
 *                      of bytes are received. Runs in O(n) time.
 *                      https://serialport.io/docs/api-parser-byte-length
 * 
 *  Ready Parser.       A transform stream that waits for a sequence 
 *                      of "ready" bytes before emitting a ready event 
 *                      and emitting data events.
 *                      https://serialport.io/docs/api-parser-ready
 * 
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

/**A transform stream that emits data as a buffer 
* after a specific number of bytes are received. 
* Runs in O(n) time.
* Emit data every number of bytes.
*/
const ByteLength = require('@serialport/parser-byte-length')


/** */


/**retrives a list of available serial ports */
   //   listAvailableSerialPorts();

/** Wait to receive "READY" from Arduino */            
        readyParser();

/** Listening for the data event puts the port in flowing mode. 
 *      will have 8 bytes per data event
*/
var bufferlength = 8 //the number of bytes to be emitted on each data event
const parser = port.pipe(new ByteLength({length: bufferlength}));
        parser.on('data',  function (data) 
        {
            console.log('\t BufferRxD:', data);
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
