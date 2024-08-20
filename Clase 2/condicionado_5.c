#include <stdio.h>

int main() {
    int opcion;

    do {
        printf("\nMenú:\n");
        printf("1. Opción 1\n");
        printf("2. Opción 2\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: printf("Elegiste la opción 1\n"); break;
            case 2: printf("Elegiste la opción 2\n"); break;
            case 3: printf("Saliendo...\n"); break;
            default: printf("Opción no válida\n");
        }
    } while (opcion != 3);

    return 0;

    //Explicación: El menú se muestra continuamente
    // hasta que el usuario elige salir con la opción 3.
}
