#include <stdio.h>

// Función que convierte grados Celsius a Fahrenheit
double celsius_a_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    double celsius = 25;
    double fahrenheit = celsius_a_fahrenheit(celsius);
    printf("%f grados Celsius son %f grados Fahrenheit\n", celsius, fahrenheit);
    return 0;
}
