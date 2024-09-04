#include <stdio.h>
#include <math.h>  // Para sqrt

// Función para contar los divisores de un número
int contar_divisores(int X) {
    int count = 1;
    for (int i = 1; i <= (int)(X/2); i++) {
        if (X % i == 0) {
            count++;
        }
    }
    return count;
}

// Función para verificar si un número es primo
int es_primo(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


// Función para convertir un número a una base e imprimirlo
void convertir_a_base(int X, int base) {
    // Si el número es 0, imprimir directamente y salir
    if (X == 0) {
        printf("0");
    }

    else{
        int temp = X;  // Variable temporal para preservar el valor original de X
        int multiplicador = 1;  // Variable para rastrear las posiciones de los dígitos en la base original

        // Primer bucle: averiguar el multiplicador más grande en la base deseada
        while (temp > 0) {
            multiplicador *= base;
            temp /= base;
        }
        multiplicador /= base;  // Reducirlo una vez para no pasarnos

        // Segundo bucle: imprimir los dígitos en la base deseada
        while (multiplicador > 0) {
            int digito = X / multiplicador;  // Obtener el dígito más significativo
            printf("%d", digito);  // Imprimir el dígito
            X %= multiplicador;  // Quitar el dígito de X
            multiplicador /= base;  // Reducir el multiplicador para la siguiente posición
        }

        printf("\n");
    }

    
}

int main() {
    int X;
    printf("Ingrese un número natural X: ");
    scanf("%d", &X);

    // 1. Contar divisores de X
    int cantidad_divisores = contar_divisores(X);
    printf("Cantidad de divisores: %d\n", cantidad_divisores);

    // 2. Verificar si la cantidad de divisores es primo
    if (es_primo(cantidad_divisores)) {
        printf("La cantidad de divisores es un número primo.\n");
        printf("El número %d en base 2 es: ", X);
        convertir_a_base(X, 2);
    } else {
        printf("La cantidad de divisores NO es un número primo.\n");
        printf("El número %d en base 9 es: ", X);
        convertir_a_base(X, 9);
    }

    return 0;
}
