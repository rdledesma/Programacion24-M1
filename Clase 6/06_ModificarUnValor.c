#include <stdio.h>

int main() {
    int numeros[3] = {10, 20, 30};

    numeros[1] = 50; // Cambiar el segundo elemento

    for (int i = 0; i < 3; i++) {
        printf("%d\n", numeros[i]); // Imprimir los elementos modificados
    }

    return 0;
}