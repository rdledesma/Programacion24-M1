#include <stdio.h>

/*

El comercio HuevosK necesita un sistema para gestionar su inventario de huevos. 
Cada vez que se realiza una venta, el sistema debe disminuir la cantidad en stock. 
Si la cantidad en stock llega a cero, el sistema debe alertar al administrador. 
También debe permitir añadir huevos al inventario cuando se repongan.
*/


// Procedimiento para registrar una venta (resta del inventario)
void registrarVenta(int *stock, int cantidad) {
    if (*stock >= cantidad) {
        *stock -= cantidad;
        printf("Venta de %d unidades registrada.\n", cantidad);
    } else {
        printf("Stock insuficiente para la venta.\n");
    }
}

// Procedimiento para reponer el inventario
void reponerStock(int *stock, int cantidad) {
    *stock += cantidad;
    printf("Se han añadido %d unidades al stock.\n", cantidad);
}

int main() {
    int stock = 50;
    printf("Stock inicial: %d\n", stock);

    registrarVenta(&stock, 20);  // Vender 20 unidades
    printf("Stock después de la venta: %d\n", stock);

    reponerStock(&stock, 30);  // Añadir 30 unidades
    printf("Stock después de la reposición: %d\n", stock);

    registrarVenta(&stock, 70);  // Intentar vender más del stock disponible
    printf("Stock final: %d\n", stock);

    return 0;
}
