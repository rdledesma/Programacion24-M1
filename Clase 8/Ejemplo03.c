#include <stdio.h>
#define MAX 30  // Tamaño máximo de la cadena para nombres
#define MAX_PRODUCTS 5  // Número máximo de productos

typedef char tcadena[MAX];

// Definir la estructura Producto
typedef struct {
    tcadena nombre;
    int id;
    float precio;
    int stock;
} Producto;

typedef Producto Inventario[MAX_PRODUCTS];


// Función para modificar un producto por ID usando un ciclo while
void modificarProducto(Inventario inventario, int numProductos, int idModificar) {
    int index = -1;
    int i = 0;

    // Búsqueda del producto por su ID usando un ciclo while
    while (i < numProductos) {
        if (inventario[i].id == idModificar) {
            index = i;  // Guardar el índice si se encuentra el producto
        }
        i++;  // Incrementar el contador para avanzar al siguiente producto
    }

    // Si se encontró el producto, modificarlo
    if (index != -1) {
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", &inventario[index].precio);
        printf("Ingrese el nuevo stock del producto: ");
        scanf("%d", &inventario[index].stock);
        printf("Producto con ID %d modificado.\n", idModificar);
    } else {
        // Si no se encontró, mostrar un mensaje
        printf("Producto con ID %d no encontrado.\n", idModificar);
    }
}




// Función para mostrar los productos
void mostrarInventario(Inventario inventario, int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d: Nombre: %s, ID: %d, Precio: %.2f, Stock: %d\n", 
               i + 1, inventario[i].nombre, inventario[i].id, inventario[i].precio, inventario[i].stock);
    }
}

int main() {
    Inventario inventario = {
        {"Producto1", 101, 10.5, 50},
        {"Producto2", 102, 20.0, 40},
        {"Producto3", 103, 15.0, 30},
        {"Producto4", 104, 25.0, 20},
        {"Producto5", 105, 30.0, 10}
    };

    int idModificar;

    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &idModificar);

    modificarProducto(inventario, MAX_PRODUCTS, idModificar);
    mostrarInventario(inventario, MAX_PRODUCTS);

    return 0;
}
