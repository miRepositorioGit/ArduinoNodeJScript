/**script.js
 * 
 */

$(document).ready(function () {
  console.log( "ready!" );
  /**
   * Basic syntaxis:
 *  $(selector).action() 
 *  |     |        |------- A jQuery action() to be performed on the elements
 *  |     |---------------- to "query (or find)" HTML elements 
 *  |---------------------- A sign to define/acces jQuery
 *                           |--- "#test" the element with id="test"
 * 
 *   selector   id at HTML         Description
 *  #on      :   "on"             query status from On button                
 *  #off     :   "off"            query status from Off button
 *  jQuery.get('/on') :           Load data type (/on) from the server using a HTTP GET request.  http://localhost:3000/on
 *  $.get('/off') :               Load data type (/off)from the server using a HTTP GET request.  http://localhost:3000/off 
 * https://api.jquery.com/jquery.get/
    */
  jQuery("#on").click(function () {
    jQuery.get('/on'), console.log("on"), writeToLabel("on"); // 
  });  // Set digital output:  on
  $("#off").click(function () {
    $.get('/off'), console.log("off"), writeToLabel("off"); // escribe sobre label en HTML
  });    // Set digital output:  off

  /**escribe dato sobre label en HTML */

  function writeToLabel(arg0) {
    document.getElementById('LabelDatoRecibido').innerHTML = arg0;
  }; // escribe en label


});
