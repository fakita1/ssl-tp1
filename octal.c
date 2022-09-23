#include "octal.h"

int columnaOctal(char c){
    int decimal = c - '0';

    // Si el decimal cumple esta condicion significa que no esta en el rango 0-7.
    if (decimal < 0 || decimal > 7) return 8;

    // Devolvemos la columna del octal (aqui representado como decimal).
    return decimal;
}

int esOctal(const char* cadena) {
    // 0-7 / otro
    int tt[3][9] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 2},
            {1, 1, 1, 1, 1, 1, 1, 1, 2},
            {2, 2, 2, 2, 2, 2, 2, 2, 2},
    };

    int resultado = esPalabra(9, tt, columnaOctal, cadena, 1, 2);

    if (resultado) {
        printf("La cadena %s fue aceptada como octal\n", cadena);
    } else {
        printf("La cadena %s no fue aceptada como octal\n", cadena);
    }

    return resultado;
}