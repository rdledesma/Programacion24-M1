#include <stdio.h>

// Función que busca un elemento 
//en el arreglo y devuelve su índice
int buscarElemento(int arr[], int tamaño, int elemento) {
    for (int i = 0; i < tamaño; i++) {
        if (arr[i] == elemento) {
            return i; // Devuelve el índice si 
                    //se encuentra el elemento
        }
    }
    return -1; // Devuelve -1 si no se encuentra el elemento
}

int main() {
    int arreglo[] = {5, 3, 8, 6, 1};
    int tamaño = 5;
    int buscar = 8;

    int resultado = buscarElemento(arreglo, tamaño, buscar); // Paso por valor
    if (resultado != -1) {
        printf("Elemento encontrado en el índice: %d\n", resultado);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}
