#include <stdio.h>

int main() {
    int option;

    printf("Menú:\n");
    printf("1. Opción 1\n");
    printf("2. Opción 2\n");
    printf("3. Opción 3\n");
    printf("Seleccione una opción (1-3): ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Has seleccionado la Opción 1.\n");
            break;
        case 2:
            printf("Has seleccionado la Opción 2.\n");
            break;
        case 3:
            printf("Has seleccionado la Opción 3.\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}
