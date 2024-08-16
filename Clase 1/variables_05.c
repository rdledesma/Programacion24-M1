#include <stdio.h>

int main() {
    // Tipos enteros
    int numeroEntero = 100;        // Tipo entero estándar
    short numeroCorto = 10;        // Tipo entero corto
    long numeroLargo = 100000L;    // Tipo entero largo

    // Tipos de punto flotante
    float numeroFlotante = 3.14f;  // Tipo punto flotante de precisión simple
    double numeroDoble = 3.141592653589793; // Tipo punto flotante de doble precisión

    // Tipo de carácter
    char caracter = 'A';          // Tipo carácter

    // Imprimir los valores
    printf("Tipo int:\n");
    printf("numeroEntero: %d\n", numeroEntero);

    printf("\nTipo short:\n");
    printf("numeroCorto: %d\n", numeroCorto);

    printf("\nTipo long:\n");
    printf("numeroLargo: %ld\n", numeroLargo);

    printf("\nTipo float:\n");
    printf("numeroFlotante: %.2f\n", numeroFlotante);

    printf("\nTipo double:\n");
    printf("numeroDoble: %.15f\n", numeroDoble);

    printf("\nTipo char:\n");
    printf("caracter: %c\n", caracter);

    return 0;
}
