#include <stdio.h>

int multiplicacionRusa(int a, int b) {
    if (a == 0)  // Caso base: si uno de los números es 0
        return 0;
    if (a % 2 == 0)  // Si 'a' es par
        return multiplicacionRusa(a / 2, b * 2);
    else  // Si 'a' es impar
        return b + multiplicacionRusa(a / 2, b * 2);
}

int main() {
    int a = 13, b = 17;
    printf("%d * %d = %d\n", a, b, multiplicacionRusa(a, b));
    return 0;
}
