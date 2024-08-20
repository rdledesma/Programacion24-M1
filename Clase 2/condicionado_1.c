#include <stdio.h>

//Un ciclo condicionado 
//es aquel que se repite mientras
//se cumpla una condición específica, 
//ciclo while.


int main() {
    int contador = 1;
    while (contador <= 5) {
        printf("Contador: %d\n", contador);
        contador++;
    }
    return 0;
}


//El ciclo while sigue repitiéndose mientras la variable 
//contador sea menor o igual a 5. 
//Cada vez que se repite el ciclo, contador aumenta en 1.