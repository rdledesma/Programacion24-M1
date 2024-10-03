#include <stdio.h>
#define MAX 100   // Tamaño máximo de la cadena para títulos y autores
#define NUM_LIBROS 3   // Número máximo de libros

typedef char tcadena[MAX];  // Definimos tcadena como una cadena de tamaño MAX

// Definir el tipo de estructura para Libro
typedef struct {
    tcadena titulo;
    tcadena autor;
    int anioPublicacion;
} Libro;

// Definir el tipo de array de libros
typedef Libro Biblioteca[NUM_LIBROS];  // Un "Biblioteca" será un array de NUM_LIBROS de tipo Libro

int main() {
    // Crear una "biblioteca" (array de libros)
    Biblioteca biblioteca = {
        {"Cien años de soledad", "Gabriel Garcia Marquez", 1967},
        {"Don Quijote", "Miguel de Cervantes", 1605},
        {"La Odisea", "Homero", -800}
    };

    // Mostrar información
    for (int i = 0; i < NUM_LIBROS; i++) {
        printf("Libro %d: Título: %s, Autor: %s, Año de publicación: %d\n", i + 1, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anioPublicacion);
    }

    return 0;
}
