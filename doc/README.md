

![Austral Ingenieria](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQooGo7vQn4t9-6Bt46qZF-UY4_QFpYOeh7kVWzwpr_lbLr5wka)


# Proyecto 61-bridge-serial

## Secciones

- [Objetivo](#objetivo)
- [Programa](#programa)
- [Constantes](#constantes)
- [Documentacion](#documentacion)


## Objetivo

>   El objetivo primordial de este proyecto es probar el funcionamiento de vincular UART0 (Serial0) con UART2 (Serial2) en el caso del ESP32  
>   La forma de probarlo es que, lo que se ingrese por la interfase serie principal se envía a la transmisión de la interfase serie auxiliar Serial2  
>   A su vez, como a la salida de Serial2 hay una conexión directa a la entrada de Serial2, a su vez lo que ingrese por RX de Serial2, se envía a la salida de Serial.  
>   Si se obtiene el eco de lo ingresado, entonces todo está funcionando ok  


>   Usar con cualquier placa que use los procesadores con ESP32

## Programa

El programa inicializa, en _setup_, ambas interfases serie a la misma velocidad (_baud rate_) de acuerdo a lo definido en _platformio.ini_  
Es obvio que la interfase UART0, en la plaqueta de desarrollo, es la que está vinculada al conector USB de entrada.  
En cuanto a la interfase UART2 (que es la que se implementa como Serial2) por _default_ está conectada a GPIO16 (RX2) y a GPIO17 (TX2)  
Las UART se pueden conectar a cualquier GPIO válido pero, en ese caso, hay que hacerlo específicamente en la inicialización de la  línea 22 de _main.cpp_  

En cuanto al programa que corre en _loop_ (líneas 27-31) llama continuamente a _updateSerial()_, función que se desarrolla en las líneas 9-16  

En las lineas 12-13, lo que ingresa desde Serial, se lo envía a la transmisión de Serial2  
En las lineas 14-15, lo que ingresa desde Serial2 se lo envia a la transmisión de Serial

## Constantes

En _platformio.ini_ se definen las siguientes constantes:  

_SERIAL_BAUD_: la velocidad de comunicación de ambas interfases serie
_RX2_: GPIO que es el pin de recepción de la interfase Serial2
_TX2_: GPIO que es el pin de transmisión de la interfase Serial2


##    documentacion

En el directorio _./files_, se almacena lo siguiente:  

[Hoja de datos SIM800](files/SIM800L-SIMCom.pdf)  
[Manual Comandos AT SIM800](files/SIM800_Series_AT_Command_Manual_V1.05.pdf)  
[Circuito interface ESP32-SIM800](files/ESP32-SIM800L.pdf)  



###     Links

[Interfacing SIM800L GSM/GPRS Module with ESP32](https://circuitdigest.com/microcontroller-projects/interfacing-sim800l-module-with-esp32)



