#include "hexa.h"

int columnaHexa(char c){
    // Si al codigo ascii de '0' le restamos 48  llegamos a 0.
    int decimal = c - '0';

    if (decimal >= 0 && decimal <= 9) {
        return decimal;
    }

    // El caracter en mayusculas - 55 debería dar 10 para A y 15 para F, valores menores o mayores a eso no estan permitidos.
    decimal = toupper(c) - 55;
    if (decimal >= 10 && decimal <= 15) {
        return decimal;
    }

    // Estado de rechazo
    return 16;
}

int esHexa(const char* cadena) {
    // 0-9 / A-F
    int tt[3][17] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    };

    int resultado = esPalabra(17, tt, columnaHexa, cadena, 1, 2);

    if (resultado) {
        printf("La cadena %s fue aceptada como hexadecimal\n", cadena);
    } else {
        printf("La cadena %s no fue aceptada como hexadecimal\n", cadena);
    }

    return resultado;
}
