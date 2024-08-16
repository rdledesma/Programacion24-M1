#include <stdio.h>

int main() {
    // Declaración de variables
    int a = 10, b = 5;
    float x = 7.5, y = 2.5;
    int result;

    // Operadores aritméticos
    result = a + b;
    printf("Suma: %d + %d = %d\n", a, b, result);
    
    result = a - b;
    printf("Resta: %d - %d = %d\n", a, b, result);

    result = a * b;
    printf("Multiplicación: %d * %d = %d\n", a, b, result);

    result = a / b;
    printf("División: %d / %d = %d\n", a, b, result);

    result = a % b;
    printf("Módulo: %d %% %d = %d\n", a, b, result);

    // Operadores de asignación
    a += b; // Equivalente a a = a + b
    printf("a después de a += b: %d\n", a);

    a -= b; // Equivalente a a = a - b
    printf("a después de a -= b: %d\n", a);

    // Operadores de incremento/decremento
    a++;
    printf("a después de a++: %d\n", a);

    a--;
    printf("a después de a--: %d\n", a);

    // Operadores relacionales
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    // Operadores lógicos
    int true = 1, false = 0;
    printf("true && false: %d\n", true && false);
    printf("true || false: %d\n", true || false);
    printf("!true: %d\n", !true);
    printf("!false: %d\n", !false);

    return 0;
}
