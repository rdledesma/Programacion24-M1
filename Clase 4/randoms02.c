#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    /*
    en C el valor de RAND_MAX es una constante definida en la biblioteca estándar <stdlib.h>, 
    y su valor depende de la implementación del compilador, pero según el estándar de C,
     el valor mínimo garantizado de RAND_MAX es 32767. Esto significa que RAND_MAX 
    debe ser al menos 32767 en cualquier implementación,
     aunque puede ser más grande en algunos sistemas.
    */
    printf("El valor de RAND_MAX es: %d\n", RAND_MAX);

    int min = 10;
    int max = 50;

    int numero = min + rand() % (max - min + 1);

    printf("Numero aleatorio entre %d y %d: %d\n", min, max, numero);

    return 0;
}