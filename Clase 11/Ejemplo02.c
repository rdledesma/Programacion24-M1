#include <stdio.h>
/*
Suma de los primeros N numeros naturales
*/
int suma(int n) {
    if (n == 0)  // Caso base
        return 0;
    else
        return n + suma(n - 1);  // Llamada recursiva
}

int main() {
    int num = 4;
    printf("La suma de los primeros %d números es %d\n",
             num, suma(num));
    return 0;
}
