#include <stdio.h>


//& (dirección de): Se usa para obtener la dirección de una variable.
// Es necesario cuando queremos pasar una variable por referencia a una función.

//* (desreferenciar): Se usa para acceder 
//o modificar el valor almacenado en la dirección 
//a la que apunta un puntero.

void incrementar(int *n) {
    (*n)++;  // Desreferenciamos el puntero 'n' y aumentamos el valor al que apunta
}

int main() {
    int numero = 7;
    printf("Antes de incrementar: %d\n", numero);

    incrementar(&numero);  // Pasamos la dirección de 'numero'

    printf("Después de incrementar: %d\n", numero);  // 'numero' ahora es 8
    return 0;
}
