#include <stdio.h>

// Función que ordena un arreglo usando el método de burbuja
void ordenarBurbuja(int arr[], int tamaño) {
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arreglo[] = {64, 34, 25, 12, 22, 11, 90};
    int tamaño = 7;

    ordenarBurbuja(arreglo, tamaño); // Paso por referencia

    // Imprimir el arreglo ordenado
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    return 0;
}
