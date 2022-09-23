#include "esPalabra.h"
int esPalabra(int ttColumnas, int tt[][ttColumnas], int (*obtenerColumna)(char), const char* cadena, int estadoFinal, int estadoRechazo) {
    // Damos por hecho para el punto 1 que el estado 1 es final y el 2 de rechazo por la manera en la que diseñamos los automatas.

    char caracter = cadena[0];
    int estado = 0;
    int i = 0;
    while (caracter != '\0') {
        // Buscamos columna correspondiente a el caracter dado y cambiamos al estado que corresponda.
        int columna = obtenerColumna(caracter);
        estado = tt[estado][columna];

        if (estado == estadoRechazo) return 0; // Estado de rechazo

        // Incrementamos el contador y seteamos el caracter al
        // siguiente disponible para su uso en siguiente iteracion del loop.
        i++;
        caracter = cadena[i];
    }

    // Si el estado es final significa que se acepta la palabra.
    if (estado == estadoFinal) return 1;
    return 0;
}
