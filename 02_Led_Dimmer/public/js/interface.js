$( document ).ready(function() 
{

    $("#reset").click(function ()
        {
          // inicializa en cero y recarga Html
          reset();
        });

    $( "#sliderPosition" ).mouseup(function() 
          {
        // recupera sliderPosition
            var payLoad   = $('#sliderPosition').val();

         // envia dato
            $.get('/set?payLoadData=' + payLoad);
          
        // muestra dato en consola 
            showRxData(payLoad); 
       
        // muestra dato en interface.html    
            showRxd(payLoad);
          });

/** muestra dato recibido 
 * @param payLoad posición del slider
*/
    function showRxd(payLoad)
          {
            $('.textClass').text(payLoad);
          };

/** muestra dato en consola html*/
    function showRxData(arg0)
          {
            console.clear();
            console.log("posición: " + arg0); 
          };

/** inicializa en cero y recarga html */
      function reset()
      {
        location.reload();
        console.log("RESET");
        $("#slider-result").html('0');
        $("#sliderPosition").val('0');
        $.get('/set?payLoadData=' + 0 );// posición inicial
      };
});
