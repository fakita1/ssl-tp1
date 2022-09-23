#include "main.h"

int main() {
    int decimales = 0, octales = 0, hexadecimales = 0;

    // Podemos testear pasando el string 3&-456&7&8&A4&5fF&5Ee&AaE4C&Fg
    char string[500];
    printf("Escribir numeros para ser analizados como decimal, octal y hexa, separados por el caracter & (max 500 caracteres): ");
    gets(string);


    char* token = strtok(string, "&");

    while( token != NULL ) {
        printf( "\nAnalizando %s\n", token);
        decimales += esDecimal(token);
        octales += esOctal(token);
        hexadecimales += esHexa(token);

        token = strtok(NULL, "&");
    }

    // Podemos testear pasando el string 3+4*7+3-5
    printf("\n\nEscribir operacion matemática para ser analizada y ejecutada (max 500 caracteres): ");
    gets(string);
    realizarOperacion(string);

    return 0;
}
