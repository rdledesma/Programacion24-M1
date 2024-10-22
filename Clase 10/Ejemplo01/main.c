#include <stdio.h>
#include "punto.h"

int main() {
    Punto p1 = crearPunto(2.0, 3.0);
    Punto p2 = crearPunto(5.0, 7.0);
    printf("Distancia: %.2f\n", distancia(p1, p2));
    return 0;
}
