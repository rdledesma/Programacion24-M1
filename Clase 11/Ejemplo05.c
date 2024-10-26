#include <stdio.h>

int mcd(int a, int b) {
    if (b == 0)  // Caso base: MCD(a, 0) = a
        return a;
    return mcd(b, a % b);  // Llamada recursiva
}

int main() {
    int a = 56, b = 98;
    printf("El MCD de %d y %d es: %d\n", a, b, mcd(a, b));
    return 0;
}
