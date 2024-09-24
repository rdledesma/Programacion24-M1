#include <stdio.h>

// Función que elimina un elemento 
//de un arreglo dado su índice
void eliminarElemento(int arr[], int *tamaño, int índice) {
    if (índice < 0 || índice >= *tamaño) {
        printf("Índice fuera de rango\n");
        return;
    }
    for (int i = índice; i < *tamaño - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*tamaño)--; // Reducir el tamaño del arreglo
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamaño = 5;
    int índice = 2;

    eliminarElemento(arreglo, &tamaño, índice); // Paso por referencia

    // Imprimir el arreglo después de eliminar el elemento
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    return 0;
}
