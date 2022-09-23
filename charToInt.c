#include "charToInt.h"

int charToInt(char c) {
    // Le restamos el valor ascii de 0 (65) al caracter.
    return c - '0';
}

char intToChar(int n) {
    return n + '0';
}
