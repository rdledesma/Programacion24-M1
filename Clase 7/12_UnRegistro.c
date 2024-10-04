#include <stdio.h>
#include <string.h>

// Definimos la estructura de un estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    int matricula;
};

// Prototipos de funciones
struct Estudiante crearEstudiante();  // Ahora retorna un Estudiante
void leerEstudiante(struct Estudiante est);
void actualizarEstudiante(struct Estudiante *est);
void eliminarEstudiante(struct Estudiante *est);

int main() {
    struct Estudiante estudiante;  // Un solo estudiante
    int opcion;
    int estudianteCreado = 0;  // Variable para verificar si el estudiante ha sido creado

    do {
        // Menú de opciones
        printf("\n--- CRUD de Estudiante ---\n");
        printf("1. Crear estudiante\n");
        printf("2. Leer estudiante\n");
        printf("3. Actualizar estudiante\n");
        printf("4. Eliminar estudiante\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                estudiante = crearEstudiante();
                estudianteCreado = 1;  // Marcamos que el estudiante ha sido creado
                break;
            case 2:
                if (estudianteCreado) {
                    leerEstudiante(estudiante);
                } else {
                    printf("No hay estudiante registrado.\n");
                }
                break;
            case 3:
                if (estudianteCreado) {
                    actualizarEstudiante(&estudiante);
                } else {
                    printf("No hay estudiante registrado para actualizar.\n");
                }
                break;
            case 4:
                if (estudianteCreado) {
                    eliminarEstudiante(&estudiante);
                    estudianteCreado = 0;  // Indicamos que el estudiante ha sido eliminado
                } else {
                    printf("No hay estudiante registrado para eliminar.\n");
                }
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}

// Función para crear un estudiante y retornarlo
struct Estudiante crearEstudiante() {
    struct Estudiante est;

    printf("\n--- Crear Estudiante ---\n");
    printf("Nombre: ");
    scanf(" %[^\n]s", est.nombre);
    printf("Edad: ");
    scanf("%d", &est.edad);
    printf("Matrícula: ");
    scanf("%d", &est.matricula);
    printf("Estudiante creado con éxito!\n");

    return est;  // Retornamos el estudiante creado
}

// Función para leer (mostrar) los datos de un estudiante
void leerEstudiante(struct Estudiante est) {
    printf("\n--- Datos del Estudiante ---\n");
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d\n", est.edad);
    printf("Matrícula: %d\n", est.matricula);
}

// Función para actualizar los datos de un estudiante
void actualizarEstudiante(struct Estudiante *est) {
    printf("\n--- Actualizar Estudiante ---\n");
    printf("Nombre actual: %s\n", est->nombre);
    printf("Nuevo nombre: ");
    scanf(" %[^\n]s", est->nombre);
    printf("Edad actual: %d\n", est->edad);
    printf("Nueva edad: ");
    scanf("%d", &est->edad);
    printf("Estudiante actualizado con éxito!\n");
}

// Función para eliminar un estudiante (borrar los datos)
void eliminarEstudiante(struct Estudiante *est) {
    printf("\n--- Eliminar Estudiante ---\n");
    strcpy(est->nombre, "");  // Limpiamos el nombre
    est->edad = 0;            // Reiniciamos la edad
    est->matricula = 0;       // Reiniciamos la matrícula
    printf("Estudiante eliminado con éxito!\n");
}
