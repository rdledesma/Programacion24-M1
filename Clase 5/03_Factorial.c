#include <stdio.h>

//Calcula el factorial de un número entero.

void calcularFactorial(int numero) {
    int factorial = 1;
    for (int i = 1; i <= numero; i++) {
        factorial *= i;
    }
    printf("El factorial de %d es: %d\n", numero, factorial);
}

int main() {
    calcularFactorial(5); // Llamada al procedimiento con un número entero
    return 0;
}
