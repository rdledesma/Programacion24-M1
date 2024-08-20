#include <stdio.h>

int main() {
    int numero;
    printf("Ingresa un número positivo: ");
    scanf("%d", &numero);

    while (numero < 0) {
        printf("El número es negativo, ingresa uno positivo: ");
        scanf("%d", &numero);
    }

    printf("Ingresaste el número positivo: %d\n", numero);
    return 0;

    // El ciclo se repite mientras el número ingresado sea negativo.
}


