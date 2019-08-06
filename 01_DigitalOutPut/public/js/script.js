/**script.js
 * 
 */

$( document ).ready(function()  {

      $( "#on" ).click(function() 
        {
          // Set digital output:  ON
          $.get('/on');
        });

      $( "#off" ).click(function() 
        {
          // Set digital output:  OFF
          $.get('/off');
          
        });
    
/** indicators */

              // $("#getText").click(function () 
              //   {
              //       alert($('.textClass').text());
              //       console.log($('.textClass').text());
              //   });
          
                        
              // $("#reset").click(function () 
              //   {
              //       location.reload();
              //   });

              //   $("#setText").click(function () 
              //   {
  	          //       $('.textClass').text();
              //   });
          
/** */
    $.get('/rxd',function(data){
      $("#current").text(data.data);
      });

  });
