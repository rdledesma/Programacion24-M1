#include <stdio.h>

//Un procedimiento que recibe un número 
//entero como argumento y lo imprime.

void imprimirNumero(int numero) {
    printf("El número es: %d\n", numero);
}

int main() {
    imprimirNumero(10); // Llamada al procedimiento con un número entero
    return 0;
}
