#include <stdio.h>

// Definimos una función que recibe un string (nombre) y lo imprime
void saludar(char nombre[]) {
    printf("¡Hola, %s!\n", nombre);
}

int main() {
    // Llamamos a la función y le pasamos "Juan" como argumento
    saludar("Juan");
    return 0;
}
