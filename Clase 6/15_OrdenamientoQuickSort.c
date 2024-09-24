#include <stdio.h>

// Función para intercambiar dos elementos
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para encontrar el índice de partición
int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];  // Pivote
    int i = (bajo - 1);  // Índice del menor elemento
    
    for (int j = bajo; j <= alto - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivote) {
            i++;  // Incrementar el índice del menor elemento
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Función de ordenamiento rápido
void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        // Encontrar el índice de partición
        int pi = particion(arr, bajo, alto);
        
        // Ordenar los elementos separadamente antes y después de la partición
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int main() {
    int arreglo[] = {10, 7, 8, 9, 1, 5};
    int tamaño = 6;

    quickSort(arreglo, 0, tamaño - 1);

    // Imprimir el arreglo ordenado
    printf("Arreglo ordenado: ");
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    return 0;
}
