#include <stdio.h>

// Función que implementa la búsqueda binaria
int busqueda_binaria(int arr[], int n, int x) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;  // Calcula el índice medio

        // Si el valor del medio es el que buscamos
        if (arr[medio] == x) {
            return medio;  // Se encontró el valor, retorna el índice
        }

        // Si el valor en la posición media es menor que x, busca en la mitad derecha
        if (arr[medio] < x) {
            inicio = medio + 1;
        }
        // Si el valor en la posición media es mayor que x, busca en la mitad izquierda
        else {
            fin = medio - 1;
        }
    }

    // Si no se encuentra el valor, retorna -1
    return -1;
}

int main() {
    // Arreglo de enteros ordenados
    int arr[] = {2, 3, 4, 10, 40};
    int n = 5;
    
    // Valor que se desea buscar
    int x = 10;

    // Llamada a la función de búsqueda binaria
    int resultado = busqueda_binaria(arr, n, x);

    if (resultado != -1) {
        printf("Elemento %d encontrado en el índice %d\n", x, resultado);
    } else {
        printf("Elemento %d no encontrado\n", x);
    }

    return 0;
}
