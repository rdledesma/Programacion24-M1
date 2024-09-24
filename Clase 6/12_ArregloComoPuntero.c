#include <stdio.h>

// La función recibe un arreglo (o un puntero) como parámetro
void imprimirArreglo(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamaño = 5;
    imprimirArreglo(arreglo, tamaño);  // El arreglo se pasa por referencia implícita
    return 0;
}
