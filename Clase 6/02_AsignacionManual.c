#include <stdio.h>


// Un array sin valores iniciales, 
//pero los asigna manualmente y luego los imprime.

int main() {
    int numeros[4]; // Array sin inicializar

    numeros[0] = 5; // Asignar valores manualmente
    numeros[1] = 10;
    numeros[2] = 15;
    numeros[3] = 20;

    for (int i = 0; i < 4; i++) {
        printf("%d\n", numeros[i]); // Imprimir cada número
    }

    return 0;
}
