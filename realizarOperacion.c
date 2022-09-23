#include "realizarOperacion.h"

typedef struct Node {
    struct Node* next;
    int digit;
} Node;

int realizarOperacion(char* cadena) {
    if (!esOperacionValida(cadena)) return 0;

    Node* lista = NULL;
    Node* temp = NULL;

    // Index par = numero
    // Index impar = operacion
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (lista == NULL) {
            lista = malloc(sizeof(Node));
            temp = lista;
        } else {
            temp->next = malloc(sizeof(Node));
            temp = temp->next;
            temp->next = NULL;
        }

        // Si el siguiente caracter es un '*', agarraremos el digito y lo multiplicaremos por los siguientes hasta
        // que se encuentre una operación que no sea '*'
        if (cadena[i + 1] == '*') {
            int resultadoMultiplicacion = charToInt(cadena[i]);
            i++;
            while (cadena[i] != '+' && cadena[i] != '-' && cadena[i] != '\0'){
                if (cadena[i] != '*') {
                    resultadoMultiplicacion *= charToInt(cadena[i]);
                }
                i++;
            }
            // Volvemos el indice hacia atrás porque quedó en la operación, y como el for avanzará el indice de nuevo,
            // necesitamos atrasarlo para que se registre el operador en un nodo.
            i--;
            temp->digit = resultadoMultiplicacion;
        } else if (i % 2 == 0){
            temp->digit = charToInt(cadena[i]);
        } else {
            temp->digit = cadena[i];
        }

    }

    /*
    // Debugging para multiplicaciones
    printf("Luego de multiplicaciones: ");
    temp = lista;
    int i = 0;
    while (temp != NULL) {
        if (i % 2 == 0) {
            printf("%d", temp->digit);
        } else {
            printf("%c", temp->digit);
        }
        i++;
        temp = temp->next;
    }
     */


    int resultado = lista->digit;
    temp = lista->next;

    // Recorremos la lista y por cada operador avanzamos al siguiente nodo que contendrá un dígito y operamos con eso.
    while (temp != NULL) {
        char operacion = temp->digit;
        temp = temp->next;
        if (operacion == '+') {
            resultado += temp->digit;
        } else {
            resultado -= temp->digit;
        }

        temp = temp->next;
    }

    printf("%d", resultado);
}
