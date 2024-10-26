#include <stdio.h>

int factorial(int n) {
    if (n == 0)  // Caso base
        return 1;
    else
        return n * factorial(n - 1);  // Llamada recursiva
}

int main() {
    int num = 5;
    printf("El factorial de %d es %d\n", num, factorial(num));
    return 0;
}