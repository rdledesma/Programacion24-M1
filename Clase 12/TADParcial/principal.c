#include <stdio.h>
#include "libreria.h"

#include <stdio.h>

void mostrarMenu(libreria l) {
    int opcion;

    printf("\n--- Menú Principal ---\n");
    printf("1. Agregar al final de la lista un nuevo registro\n");
    printf("2. Dado una Editorial, mostrar todos los registros ordenados por Titulo de la obra\n");
    printf("3. Dado un ISBN, eliminar de la lista\n");
    printf("4. Mostrar Libreria\n");
    printf("5. Salir\n");
    printf("Selecciona una opción: ");
    scanf("%d", &opcion);
    scanf("%*c");



    switch(opcion) {
        case 1:
            printf("\nHas seleccionado la Opción 1\n");
            // Aquí iría el código para la Opción 1

            agregaFin(&l);
            mostrarMenu(l);
            break;
        case 2:
            printf("Has seleccionado la Opción 2\n");
            // Aquí iría el código para la Opción 2
            mostrarMenu(l);
            break;
        case 3:
            printf("Has seleccionado la Opción 3\n");
            // Aquí iría el código para la Opción 3
            mostrarMenu(l);
            break;
        case 4:
            printf("Has seleccionado la Opción 4\n");
            muestra(l);
            mostrarMenu(l);
        break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción inválida, intenta de nuevo.\n");
            mostrarMenu(l);
            break;
    }
}




int main(){
    libreria l;
    l = crear();
    mostrarMenu(l);
    return 0;
}