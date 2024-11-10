#include <stdio.h>
#include "TAD_Cadena.h"

void leeCadRecursivo(TCadena cad, int tam, int j) {
    if (j >= tam - 1) {
        cad[j] = '\0';
    } else {
        char c = getchar();
        if (c == EOF || c == '\n') {
            cad[j] = '\0';
        } else {
            cad[j] = c;
            leeCadRecursivo(cad, tam, j + 1);
        }
    }
}

void leeCad(TCadena cad) {
    leeCadRecursivo(cad, MAX, 0);
}
