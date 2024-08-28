#include <stdio.h>

// Función que verifica si un número es par
int es_par(int numero) {
    return numero % 2 == 0;
}

int main() {
    int numero = 6;

    // Llamamos a la función es_par y evaluamos el resultado
    if (es_par(numero)) {
        printf("%d es par\n", numero);
    } else {
        printf("%d es impar\n", numero);
    }
    return 0;
}
