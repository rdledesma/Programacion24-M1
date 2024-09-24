#include <stdio.h>

#define TAMANO 5   // Definimos el tamaño del array
typedef int Vector[TAMANO];  // Creamos un tipo llamado 'Vector' que es un array de enteros

int main() {
    Vector v = {1, 2, 3, 4, 5};  // Declaramos un array con valores predefinidos

    // Imprimimos los valores del array
    printf("Valores del array:\n");
    for (int i = 0; i < TAMANO; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
