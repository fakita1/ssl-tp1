#include "realizarOperacion.h"

typedef struct Node {
    struct Node* next;
    int digit;
} Node;

int realizarOperacion(char* cadena) {
    if (!esOperacionValida(cadena)) return 0;

    Node* lista = malloc(sizeof(Node));
    Node* puntero = lista;

    for (int i = 0; cadena[i] != '\0'; i++) {

        if (cadena[i + 1] == '*') {
            int resultadoMultiplicacion = charToInt(cadena[i]);
            i++;
            while (cadena[i] != '+' && cadena[i] != '-'){
                if (cadena[i] != '*') {
                    resultadoMultiplicacion *= charToInt(cadena[i]);
                }
                i++;
            }
            i--;
            puntero->digit = intToChar(resultadoMultiplicacion);
            puntero->next = malloc(sizeof(Node));
            puntero = puntero->next;
            puntero->digit = '\0';
        } else {
            puntero->digit = cadena[i];
            puntero->next = malloc(sizeof(Node));
            puntero = puntero->next;
            puntero->digit = '\0';
        }
    }

    int resultado = charToInt(lista->digit);
    Node* temp = lista->next;
    printf("primero %d\n", resultado);
    while (temp->digit != '\0') {
        char operacion = temp->digit;
        temp = temp->next;
        if (operacion == '+') {
            printf("mas %d\n", charToInt(temp->digit));
            resultado += charToInt(temp->digit);
        } else {
            printf("menos %d\n", charToInt(temp->digit));
            resultado -= charToInt(temp->digit);
        }
        temp = temp->next;
    }

    printf("%d", resultado);
}
