#include <stdio.h>

// Definimos una función que recibe dos números enteros y devuelve su suma
int sumar(int a, int b) {
    return a + b;
}

int main() {
    // Llamamos a la función sumar y almacenamos el resultado
    int resultado = sumar(5, 3);
    printf("La suma es: %d\n", resultado);
    return 0;
}
