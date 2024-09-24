#include <stdio.h>

// Función que modifica cada elemento del arreglo, multiplicándolo por 2
void modificarArreglo(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        arr[i] *= 2;  // Modifica el arreglo directamente
    }
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamaño = 5;

    modificarArreglo(arreglo, tamaño); // Paso por referencia

    // Imprimir el arreglo modificado
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    return 0;
}
