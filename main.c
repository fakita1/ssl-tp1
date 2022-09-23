#include "main.h"


int main() {
    int decimales = 0, octales = 0, hexadecimales = 0;

    char string[50] = "3&-456&7&8&A4&5fF&5Ee&AAaEEeBBbCC4C&Fg";

    char* token = strtok(string, "&");

    while( token != NULL ) {
        printf( "\nAnalizando %s\n", token );
        decimales += esDecimal(token);
        octales += esOctal(token);
        hexadecimales += esHexa(token);

        token = strtok(NULL, "&");
    }

    return 0;
}
