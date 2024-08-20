#include <stdio.h>

int main() {
    int secreto = 7;
    int intento;

    do {
        printf("Adivina el número (entre 1 y 10): ");
        scanf("%d", &intento);
    } while (intento != secreto);

    printf("¡Adivinaste el número!\n");
    return 0;
}
