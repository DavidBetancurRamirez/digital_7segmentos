/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
using namespace std;

// Creación de los LEDS para la tarjeta FRDM-KL25Z
BusOut leds(D0, D1, D2, D3, D4, D5, D6);

void waitForEnter() {
    printf("Presiona Enter para ingresar nuevo numero...");
    while (getchar() != '\n');
}

int main(){
    // Arreglo con los numero DECIMALES en binario según los pines (A, B, C, D, E, F, G)
    int valorNumeros[] = {
        0b1111110, // 0
        0b0110000, // 1
        0b1101101, // 2
        0b1111001, // 3
        0b0110011, // 4
        0b1011011, // 5
        0b1011111, // 6
        0b1110000, // 7
        0b1111111, // 8
        0b1111011  // 9
    };

    int numero;
    printf("Hola");

    while (true) {
        cout << "Ingrese un número entre 0-9: ";
        cin >> numero;

        if (numero >= 0 && numero <= 9){
            leds.write(valorNumeros[numero]);
        }
    }
};