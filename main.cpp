/* display_numeros
 * El usuario pueda ingresar un número, entre 0 y 9
 * Se muestra en un display 7 segmentos
 */

#include "mbed.h"
#include <iostream>
#include <string>

// Objeto para establecer la comunicación serial con el Pc
UnbufferedSerial serial(USBTX, USBRX, 9600);

// Creación de los LEDS para la tarjeta FRDM-KL25Z
BusOut leds(D2, D3, D4, D5, D6, D7, D8);

using namespace std;

int main(){
    // Arreglo con los numero DECIMALES en binario según los pines (A, B, C, D, E, F, G)
    int valorNumeros[] = {
        126, // 0
        48, // 1
        109, // 2
        121, // 3
        51, // 4
        91, // 5
        95, // 6
        112, // 7
        127, // 8
        123  // 9
    };

    int numero;

    while (true) {
        cout << "Ingrese un numero entre 0-9: ";
        cin >> numero;

        if (numero >= 0 && numero <= 9){
            leds.write(valorNumeros[numero]);
        }
    }
};