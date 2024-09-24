#include <stdio.h>

// La función recibe un arreglo de punteros a enteros
void imprimirMatriz(int *arr[], int filas) {
    for (int i = 0; i < filas; i++) {
        printf("%d ", *arr[i]);  // Dereferenciar cada puntero
    }
    printf("\n");
}

int main() {
    int a = 1, b = 2, c = 3;
    int *matriz[] = {&a, &b, &c};  // Arreglo de punteros a enteros
    int filas = 3;
    imprimirMatriz(matriz, filas);  // Pasar arreglo de punteros
    return 0;
}
