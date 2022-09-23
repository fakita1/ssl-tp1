#include "decimal.h"
int columnaDecimal(char c){
    if (c =='+')
        return 0;
    else if(c =='-')
        return 1;
    else {
        // Si al codigo ascii de '0' le restamos 48  llegamos a 0.
        int decimal = c - '0';

        // Si el decimal cumple esta condicion significa que no esta en el rango 0-9.
        if (decimal < 0 || decimal > 9) return 12;

        // Devolvemos la columna del decimal (le sumamos 2 para saltar el + y - de la tabla).
        return decimal + 2;
    }
}

int esDecimal(const char* cadena) {
    // +, -, 0-9 / otro
    int tt[3][13] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
            {2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    };

    int resultado = esPalabra(13, tt, columnaDecimal, cadena, 1, 2);

    if (resultado) {
        printf("La cadena %s fue aceptada como decimal\n", cadena);
    } else {
        printf("La cadena %s no fue aceptada como decimal\n", cadena);
    }

    return resultado;
}
