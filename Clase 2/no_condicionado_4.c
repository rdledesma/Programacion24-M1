#include <stdio.h>

int main() {
    int num, factorial = 1;
    printf("Ingresa un número: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    printf("El factorial de %d es %d\n", num, factorial);
    return 0;

    // calcula el factorial de un número 
    //ingresado por el usuario, multiplicando sucesivamente.
    //
}
