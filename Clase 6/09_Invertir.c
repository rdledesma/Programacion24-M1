#include <stdio.h>

// Función que invierte el orden 
//de los elementos de un arreglo
void invertirArreglo(int arr[], int tamaño) {
    int inicio = 0;
    int fin = tamaño - 1;
    while (inicio < fin) {
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;
        inicio++;
        fin--;
    }
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamaño = 5;

    invertirArreglo(arreglo, tamaño); // Paso por referencia

    // Imprimir el arreglo invertido
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    return 0;
}
