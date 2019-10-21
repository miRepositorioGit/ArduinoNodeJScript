/**coleccion de funciones
 * 
 * fuente:
 * 
 * Bootstrap Toggle.  Bootstrap Toggle is a highly flexible Bootstrap plugin that converts checkboxes into toggles
 * consultado: 20oct2019. disponible: https://www.bootstraptoggle.com/
 * 
 * Métodos Js.consultado: 20oct2019. disponible:
 * https://www.w3schools.com/js/js_date_methods.asp
 * 
 * How to get multiple checkbox toggle switches values when on change event via jquery
 * https://stackoverflow.com/questions/39011279/how-to-get-multiple-checkbox-toggle-switches-values-when-on-change-event-via-jqu
 */


/** toggle button */

/** event manager for toggle buttons 
 * 
*/
function toggleEventIo3() {
    $(function () {
        /** event for IO3 */
        $('#toggleEventIo3').change(function () {
            $('#console-event').html(myFunForIO3($(this).prop('checked')))
        })
    })

}
/** manager for toggle button IO3 */
function myFunForIO3(arg0) {
    if (arg0) {
        console.log("  IO3:T R U E "); //
        $.get('/set?payLoadData=' + 255);
    }
    else {
        console.log(" IO3:F A L S E ");
        $.get('/set?payLoadData=' + 0);
    }
}


/**
 * manejador de eventos generados por el arreglo de toggle butons
 */

function generalManager() {
    $(document).on("change", ".switch", function () {
        switch ($(this).find('input').data('value')) {
            case 2:
                console.log("IO 2");
                break;
            case 3:
                console.log("IO 3");
                break;
            case 4:
                console.log("IO 4");
                break;
        }
    })
};