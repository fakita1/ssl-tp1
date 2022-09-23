#include "esOperacionValida.h"

int columnaOperacion(char c){
    if (c == '+')
        return 0;
    else if(c == '-')
        return 1;
    else if(c == '*')
        return 2;
    else {
        // Si al codigo ascii de '0' le restamos 48  llegamos a 0.
        int decimal = c - '0';

        // Si el decimal cumple esta condicion significa que no esta en el rango 0-9.
        if (decimal < 0 || decimal > 9) return 13;

        // Devolvemos la columna del decimal (le sumamos 2 para saltar el +, - y * de la tabla).
        return decimal + 3;
    }
}

int esOperacionValida(char* cadena) {
    // +, -, *, 0-9 / otro
    int tt[5][14] = {
            {4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
            {2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
            {4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4},
            {2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
            {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    };

    int resultado = esPalabra(14, tt, columnaOperacion, cadena, 3, 4);

    if (resultado) {
        printf("La cadena %s fue aceptada como operacion\n", cadena);
    } else {
        printf("La cadena %s no fue aceptada como operacion\n", cadena);
    }

    return resultado;
}
