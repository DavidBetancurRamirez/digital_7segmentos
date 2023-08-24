integrantes: Nicolas Gutierrez Arias, Nicolas Echeverri, David Beta.

se cre un objeto para establecer la comunicación serial con el Pc.
UnbufferedSerial serial(USBTX, USBRX, 9600);

Creación de los LEDS para la tarjeta FRDM-KL25Z.
BusOut leds(D2, D3, D4, D5, D6, D7, D8);
empezamos en D2 poruqe los prmieros dos puertos son los que se conectan directamente al computador
como se ve reflejado en la creacion del objeto para establecer la comunicacion con el pc.

se crea el arreglo:  int valorNumeros[] = {
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
con los decimales que representan los leds que se deben encender para mostrar su respectivo numero.
Este arreglo aprovecha que la posicion de cada numero es igual al numero que se busca representar. resulta
muy practico para poder acceder a la representacion solamente mediante el indice en vez de tener que hacer
varios condicionales.

while (true) {
        cout << "Ingrese un numero entre 0-9: ";
        cin >> numero;

        if (numero >= 0 && numero <= 9){
            leds.write(valorNumeros[numero]);
        }
    }
};

En el loop anterior se le  pide al usuario el numero que desea representar por consola y escribe sobre los LEDs
el respectivo decimal del numero. El "if" garantiza que solo se ingresen numeros del 0 al 9
y con el leds.write le pasamos la informacion a la tarjeta
