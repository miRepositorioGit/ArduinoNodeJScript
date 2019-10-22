/** interface.js   controlador
 * Propone una sintaxis para seleccionar elementos html y ejecutar para ejecutar acciones en ellos.
 * Basic syntaxis:
 *  $(selector).action() 
 *  |     |        |------- A jQuery action() to be performed on the elements
 *  |     |---------------- to "query (or find)" HTML elements 
 *  |---------------------- A sign to define/acces jQuery
 *                           |--- "#test" the element with id="test"
 * 
 *   selector             id at HTML         Description
 *  #reset_btn      :   "reset_btn"         query status from reset button
 *  #sliderPosition :   "sliderPosition"    get status slider position
 * 
 * [1] jQuery Syntax.  w3schools.com THE WORLD'S LARGEST WEB DEVELOPER SITE. 
 * https://www.w3schools.com/jquery/jquery_syntax.asp
 * 
 */

/** Prevent any jQuery code from runing BEFORE the document is finished loading
 */

$(document).ready(function () {
  /** inicializa en cero y recarga Html    **/
  $("#reset_btn").click(function () { reset(), console.log("reset button"); });

  /** recupera, envía y muestra la posicion del sliderPosition */
  $("#sliderPosition").mouseup(function () {
    var payLoad = $('#sliderPosition').val(); // get the vlaue slider position 
    sendPayLoad(payLoad);                     // get and send slider position to 
    showRxData(payLoad);                      // show at Html console
    showPosicion(payLoad);                    // show at Html muestra dato en interface.html    
  });

  /**recupera y envia dato
   * 
   */
  function sendPayLoad(payLoad) {
    $.get('/set?payLoadData=' + payLoad)
  };

  /** muestra dato recibido en barra de texto HTML
   * @param payLoad posición del slider
  */
  function showPosicion(payLoad) { $('.textClassPosicion').text(payLoad); };

  /** muestra dato en consola html*/
  function showRxData(arg0) { console.clear(), console.log("slider position: " + arg0); };

  /** inicializa en cero y recarga html */
  function reset() {
    location.reload();
    console.log("RESET");
    showPosicion(0);
    $("#slider-result").html('0');
    $("#sliderPosition").val('0');
    $.get('/set?payLoadData=' + 0);// posición inicial
  };
});
