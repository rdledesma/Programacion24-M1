#include <stdio.h>

int main() {
    // Declaración de variables
    int numero;

    // Solicitar al usuario que ingrese un número
    printf("Ingresa un número entero: ");
    scanf("%d", &numero);

    // Uso de la sentencia if
    if (numero > 0) {
        printf("El número %d es positivo.\n", numero);
    }
    
    if (numero < 0) {
        printf("El número %d es negativo.\n", numero);
    }

    if (numero == 0) {
        printf("El número es cero.\n");
    }

    // Uso de la sentencia if-else
    if (numero % 2 == 0) {
        printf("El número %d es par.\n", numero);
    } else {
        printf("El número %d es impar.\n", numero);
    }

    // Uso de la sentencia if-else-if
    if (numero > 0) {
        printf("El número %d es positivo.\n", numero);
    } else if (numero < 0) {
        printf("El número %d es negativo.\n", numero);
    } else {
        printf("El número es cero.\n");
    }

    return 0;
}
