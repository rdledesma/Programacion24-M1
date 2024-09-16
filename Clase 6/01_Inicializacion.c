#include <stdio.h>


//Descripción: Inicializa un array con 3 enteros 
//y los imprime uno por uno.
int main() {
    int numeros[3] = {1, 2, 3}; // Array con 3 enteros
    
    for (int i = 0; i < 3; i++) {
        printf("%d\n", numeros[i]); // Imprimir los elementos del array
    }

    return 0;
}
