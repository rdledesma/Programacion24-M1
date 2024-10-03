#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_CAD 50  // Definir el tamaño máximo para las cadenas

typedef char tCadena[MAX_CAD];  // Definir un tipo de cadena de caracteres

// Definir el registro de un Estudiante
typedef struct {
    int id;
    tCadena nombre;  // Cambiar el nombre para usar tCadena
    int edad;
} Estudiante;

// Prototipos de funciones
void crearEstudiante(Estudiante estudiantes[], int *contador);
void mostrarEstudiantes(Estudiante estudiantes[], int contador);
int buscarEstudiante(Estudiante estudiantes[], int contador, int id);
void actualizarEstudiante(Estudiante estudiantes[], int contador);
void eliminarEstudiante(Estudiante estudiantes[], int *contador);
void leeCad(tCadena cad, int tam);

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int contadorEstudiantes = 0;
    int opcion;
    
    do {
        printf("\n--- Menú CRUD de Estudiantes ---\n");
        printf("1. Crear Estudiante\n");
        printf("2. Mostrar Estudiantes\n");
        printf("3. Actualizar Estudiante\n");
        printf("4. Eliminar Estudiante\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();  // Para limpiar el buffer de entrada
        
        switch(opcion) {
            case 1:
                crearEstudiante(estudiantes, &contadorEstudiantes);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, contadorEstudiantes);
                break;
            case 3:
                actualizarEstudiante(estudiantes, contadorEstudiantes);
                break;
            case 4:
                eliminarEstudiante(estudiantes, &contadorEstudiantes);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while(opcion != 5);
    
    return 0;
}

// Función para crear un nuevo estudiante
void crearEstudiante(Estudiante estudiantes[], int *contador) {
    if (*contador >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar más estudiantes\n");
        return;
    }
    
    Estudiante nuevoEstudiante;
    nuevoEstudiante.id = *contador + 1; // ID autogenerado
    printf("Ingrese el nombre del estudiante: ");
    leeCad(nuevoEstudiante.nombre, MAX_CAD);  // Leer el nombre con la nueva función
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &nuevoEstudiante.edad);
    getchar();  // Limpiar el buffer de entrada
    
    estudiantes[*contador] = nuevoEstudiante;
    (*contador)++;
    
    printf("Estudiante agregado con éxito\n");
}

// Función para mostrar todos los estudiantes
void mostrarEstudiantes(Estudiante estudiantes[], int contador) {
    if (contador != 0) {

        printf("\n--- Lista de Estudiantes ---\n");
        for (int i = 0; i < contador; i++) {
            printf("ID: %d, Nombre: %s, Edad: %d\n", estudiantes[i].id, estudiantes[i].nombre, estudiantes[i].edad);
        }
        
    }
    else{
        printf("No hay estudiantes registrados\n");
    }
    
    
}

// Función para buscar un estudiante por ID
int buscarEstudiante(Estudiante estudiantes[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (estudiantes[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Función para actualizar un estudiante existente
void actualizarEstudiante(Estudiante estudiantes[], int contador) {
    int id;
    printf("Ingrese el ID del estudiante a actualizar: ");
    scanf("%d", &id);
    getchar();  // Limpiar el buffer de entrada
    
    int indice = buscarEstudiante(estudiantes, contador, id);
    if (indice != -1) {
        
        printf("Ingrese el nuevo nombre del estudiante: ");
        leeCad(estudiantes[indice].nombre, MAX_CAD);  // Leer el nuevo nombre
        printf("Ingrese la nueva edad del estudiante: ");
        scanf("%d", &estudiantes[indice].edad);
        getchar();  // Limpiar el buffer de entrada
        printf("Estudiante actualizado con éxito\n");
    }
    else{
        printf("Estudiante no encontrado\n");
    }
    
    
}

// Función para eliminar un estudiante
void eliminarEstudiante(Estudiante estudiantes[], int *contador) {
    int id;
    printf("Ingrese el ID del estudiante a eliminar: ");
    scanf("%d", &id);
    getchar();  // Limpiar el buffer de entrada
    
    int indice = buscarEstudiante(estudiantes, *contador, id);
    if (indice != -1) {

        // Mover los estudiantes hacia atrás para llenar el hueco
        for (int i = indice; i < *contador - 1; i++) {
            estudiantes[i] = estudiantes[i + 1];
        }
        
        (*contador)--;
        
        printf("Estudiante eliminado con éxito\n");

        
    }
    else{
        printf("Estudiante no encontrado\n");
    }
    
    
}

// Función para leer una cadena desde el teclado
void leeCad(tCadena cad, int tam) {
    int j = 0;
    char c;
    c = getchar();
    while (c != EOF && c != '\n' && j < tam - 1) {
        cad[j] = c;
        j++;
        c = getchar();
    }
    cad[j] = '\0';  // Terminar la cadena con '\0'
    while (c != EOF && c != '\n')  // Vaciar el buffer si hay más caracteres
        c = getchar();
}
