#include <stdio.h>

int main() {
    int numero, suma = 0;
    printf("Ingresa un número (0 para terminar): ");
    scanf("%d", &numero);

    while (numero != 0) {
        suma += numero;
        printf("Ingresa otro número (0 para terminar): ");
        scanf("%d", &numero);
    }

    printf("La suma total es: %d\n", suma);
    return 0;

    //Se sigue sumando números hasta que 
    //el usuario ingresa 0.
    //
}
