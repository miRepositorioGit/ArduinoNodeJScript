#  Muestra como vincular los recursos de hardware de una tarjeta de desarrollo Arduino con una interface codificada en JavaScript y con elementos de HTML.
Vincula una tarjeta de desarrollo Arduino con el puerto serie de tu equipo de cómputo e interactua con una interface HTML.

## Comenzando 

Descarga en tu equipo de cómputo una clonación de éste proyecto. Esta copia te permitirá apoyarte en desarrollar tus propias versiones. 

### Pre-requisitos

Paso 1.  Es necesario instalar en tu equipo de cómputo la versión v10.16.0 o posterior del entorno de ejecución para JavaScrip 'Node.js', dependiendo del sistema operativo de tu computadora. Aqui la liga de descarga: https://nodejs.org/es/download/package-manager/#debian-and-ubuntu-based-linux-distributions

Para la instalación del entorno se recomienda consultar las siguientes fuentes de información: 
```
-How to Install Latest Node.js and NPM on Ubuntu with PPA. https://tecadmin.net/install-latest-nodejs-npm-on-ubuntu/
-Node.js Tutorial - 2 Instalación. https://www.youtube.com/watch?v=PLD8sZPevEU
```

Paso 2. En la carpeta del Proyecto y en línea de comandos comienza con:
```
> npm init      rellena los campos y valida la documetación

> npm install serialport --save     versión: serialport@7.1.5

> npm install express --save        versión: express@4.17.1

```
El segundo y tercer ítem descargan e instalan lotes de paquetes de Node.js, que permiten acceder a los recursos de hardware del puerto serie y a hacer uso de la infraestructura de aplicaciones web mínima y flexible, para los sistemas operativos: Linux, OSX y Windows.

Paso 3. Cada carpeta de proyecto tiene:
        
* Un archivo con nombreDelProyecto.js, archivo de secuencia de comandos de JScript, administra los recursos de hardware y aplicaciones web.
* Un archivo package-lock.json, contiene las dependencias y versiones de los paquetes de Node.js
* Una carpeta node_modules, contiene lotes de paquetes de Node.js
* Una carpeta public contiene: un archivo 'html document', dos carpetas:  1/2 'js' con un archivo con interface.js 2/2 css                              con un archivo style.css.
* Una carpeta con un archivo .ino, contiene la programación estructurada en lenguage C que admistra los recursos de hardware del sistema de desarrollo Arduino.

Paso 4.  Nombre del recurso de puerto COM asignado al sistema de desarrollo Arduino.
Abrir el Administrador de dispositivos, en el árbol de hardware-recursos, home>Puertos(COM y LPT)>USB Serial Port(COM'n')
donde el recurso para comName en nombreDelProyecto.js.

### Ejecución
En la carpeta del proyecto y en línea de comandos:
```
>node nombreDelProyecto.js
```



[Node.js son marcas registradas]
