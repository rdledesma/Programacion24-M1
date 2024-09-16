#include <stdio.h>

void modificarValor(int n) {
    n = 10;  // Cambia solo la copia de 'n'
    
    printf("Después de modificar en la función: %d\n", n);  // 'numero' es 10
}

int main() {
    int numero = 5;
    printf("Antes de modificar: %d\n", numero);

    modificarValor(numero);  // Pasa una copia de 'numero'

    printf("Después de modificar Fuera de la función: %d\n", numero);  // 'numero' sigue siendo 5
    return 0;
}