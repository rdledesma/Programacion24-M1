#include <stdio.h>
#include <math.h>  // Biblioteca necesaria para usar M_PI (valor de pi)

// Definimos una función que calcula el área de un círculo dado el radio
double area_circulo(double radio) {
    return M_PI * radio * radio;
}

int main() {
    double radio = 4;
    double area = area_circulo(radio);
    printf("El área del círculo es: %f\n", area);
    return 0;
}
