#include <stdio.h>

// Función de ordenamiento por inserción
void ordenamientoInsercion(int arr[], int tamaño) {
    for (int i = 1; i < tamaño; i++) {
        int clave = arr[i];
        int j = i - 1;
        
        // Mover los elementos de arr[0..i-1], 
        //que son mayores que clave, una posición adelante
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = clave;
    }
}

int main() {
    int arreglo[] = {12, 11, 13, 5, 6};
    int tamaño = 5;

    ordenamientoInsercion(arreglo, tamaño);

    // Imprimir el arreglo ordenado
    printf("Arreglo ordenado: ");
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    return 0;
}
