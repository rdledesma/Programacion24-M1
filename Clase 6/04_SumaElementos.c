#include <stdio.h>
//Se suman los valores de todos los elementos 
//del array y se muestra el total.
int main() {
    int numeros[5] = {1, 2, 3, 4, 5};
    int suma = 0;

    for (int i = 0; i < 5; i++) {
        suma += numeros[i]; // Sumar los elementos
    }

    printf("La suma es: %d\n", suma);

    return 0;
}