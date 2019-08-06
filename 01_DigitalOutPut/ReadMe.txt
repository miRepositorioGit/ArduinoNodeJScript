ReadMe.txt

Controla la modulación de ancho de pulso de una salida analógica

    - Muestra la comunicación de bytes entre un equipo de cómputo
     y una tarjeta Arduino. 

    - Vincula una tarjeta de desarrollo Arduino con el puerto 
    serie de tu equipo de cómputo e interactua con una interface HTML.

    - Escribe sliderPosition en el recurso PWM.
    
    |--#------| 
       |<---id="sliderPosition" 
                    |--{escribe en el puerto serial.}

    - Controla la modulación de dos formas:

1/2 Modo gráfico.  Emplea un slider-barra
2/2 Modo comando.  Emplea comandos  

express@4.17.1
serialport@7.1.5

            Árbol del proyecto
    01_Proyecto LedDimmer.js
            |       |--node_modes           <-- contiene lotes de paquetes de Node.js
            |       |--public
            |           |--interface.htlm   <-- interface gráfica con elementos htlm 
            |           |--js
            |           |   |--interface.js <-- interface/vinculador entre html-jScript
            |           |--css
            |               |--style.css    <-- estilos de los elementos htlm
            |--ArduinoFile
                    |--loopBackPwm.ino      <-- programación estructurada en lenguaje C. 
                                                Administra los recursos de hardware de una tarjeta Arduino.
                    
Secuencia de pasos para ejecutar este proyecto.

    Desde la carpeta del proyecto y en línea de commandos

        >\\ArduinoNodeJS\01_Proyecto>node led_control.js 

            open browser at  http://localhost:3000/
            Muestra la posición de un SLIDER

    Abrir un navegador. 

        * Modo intrface con elementos htlm

            teclear en la barra de direcciones
                localhost:3000/    

        * Modo comandos           

            teclear en la barra de direcciones
                localhost:3000/set?payLoadData=120

            En la ventana de comandos
                posición :10
                sending to serial: 10
                receiving from serial: 10

    Salir de la ejecución

            Ctrl + c    
