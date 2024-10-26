#include <stdio.h>

int potencia(int a, int b) {
    if (b == 0)  // Caso base: cualquier número elevado a 0 es 1
        return 1;
    if (b % 2 == 0)  // Si b es par
        return potencia(a * a, b / 2);
    else  // Si b es impar
        return a * potencia(a, b - 1);
}

int main() {
    int base = 2, exponente = 10;
    printf("%d^%d = %d\n", base, exponente, potencia(base, exponente));
    return 0;
}
