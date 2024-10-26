#include <stdio.h>


int contieneDigito(int N, int D) {
    // Caso base: si N es 0, ya no hay más dígitos que revisar
    if (N == 0) return 0;
    
    // Comprobar si el último dígito de N es igual a D
    if (N % 10 == D) return 1;

    // Llamada recursiva con el número sin el último dígito
    return contieneDigito(N / 10, D);
}

int main() {
    int N, D;

    // Solicitar al usuario que ingrese los valores
    printf("Ingrese un número entero positivo N: ");
    scanf("%d", &N);
    printf("Ingrese un dígito D: ");
    scanf("%d", &D);

    // Verificar si el dígito D está presente en N
    if (contieneDigito(N, D))
        printf("El dígito %d está presente en el número %d.\n", D, N);
    else
        printf("El dígito %d NO está presente en el número %d.\n", D, N);

    return 0;
}
