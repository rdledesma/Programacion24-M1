#include <stdio.h>

int main() {
    char operator;
    double num1, num2;

    printf("Introduce un operador (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Introduce dos números: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            else
                printf("Error: División por cero no permitida.\n");
            break;
        default:
            printf("Operador no válido.\n");
            break;
    }

    return 0;
}
