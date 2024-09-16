#include <stdio.h>

//El programa solicita al usuario que ingrese
// valores y los almacena en un array de enteros.

int main() {
    int numeros[5];

    // Pedir al usuario que ingrese valores
    for (int i = 0; i < 5; i++) {
        printf("Ingrese un número para la posición %d: ", i);
        scanf("%d", &numeros[i]); // Cargar valores en el array
    }

    // Mostrar los valores cargados
    printf("Valores cargados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}