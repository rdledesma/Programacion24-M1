#include <stdio.h>
#define MAX 30   // Tamaño máximo de la cadena para nombres
#define MAX_PRODUCTS 5   // Número máximo de productos

typedef char tcadena[MAX];  // Definimos tcadena como una cadena de tamaño MAX

typedef struct {
    tcadena nombre;
    int id;
    float precio;
    int stock;
} Producto;

int main() {
    Producto inventario[MAX_PRODUCTS] = {
        {"Producto1", 101, 10.5, 50},
        {"Producto2", 102, 20.0, 40},
        {"Producto3", 103, 15.0, 30},
        {"Producto4", 104, 25.0, 20},
        {"Producto5", 105, 30.0, 10}
    };

    // Mostrar información
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("ID: %d, Nombre: %s, Precio: %.2f, Stock: %d\n", inventario[i].id, inventario[i].nombre, inventario[i].precio, inventario[i].stock);
    }

    return 0;
}
