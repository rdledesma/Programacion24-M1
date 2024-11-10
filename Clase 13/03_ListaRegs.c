#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura TEstudiante para almacenar los datos de cada estudiante
typedef struct {
    char nombre[30];
    int edad;
    float calificacion;
} TEstudiante;

// Definición de la estructura de nodo
typedef struct Nodo {
    TEstudiante estudiante;
    struct Nodo* sig;
} TNodo;

typedef TNodo* TPtr;  // Puntero a un nodo

// Prototipos de funciones
TEstudiante Cargar_Estudiante();
TPtr creaNodo();
void Cargar_Lista(TPtr*, int);
void Mostrar_Lista(TPtr);
void Buscar_Estudiante(TPtr, const char*);

int main() {
    TPtr listaEstudiantes = NULL;
    int numEstudiantes, seleccion;
    
    // Solicitar el número de estudiantes a cargar
    printf("\nIngrese la cantidad de estudiantes: ");
    fflush(stdin);
    scanf("%d", &numEstudiantes);
    Cargar_Lista(&listaEstudiantes, numEstudiantes);

    // Menú para el usuario
    do {
        printf("\nOpciones: 0 [Salir]; 1 [Buscar Estudiante]; 2 [Mostrar Lista]");
        printf("\nIngrese su eleccion: ");
        fflush(stdin);
        scanf("%d", &seleccion);
        
        switch (seleccion) {
            case 0:
                printf("\nFin del Programa\n");
                break;
            case 1: {
                char nombre[30];
                printf("Ingrese el nombre del estudiante a buscar: ");
                scanf("%s", nombre);
                Buscar_Estudiante(listaEstudiantes, nombre);
                break;
            }
            case 2:
                Mostrar_Lista(listaEstudiantes);
                break;
            default:
                printf("\nValor no valido\n");
        }
    } while (seleccion != 0);

    return 0;
}

// Función para cargar datos de un estudiante desde la entrada
TEstudiante Cargar_Estudiante() {
    TEstudiante nuevoEstudiante;
    printf("\nIngrese el nombre del estudiante: ");
    scanf("%s", nuevoEstudiante.nombre);
    printf("Ingrese la edad del estudiante: ");
    fflush(stdin);
    scanf("%d", &nuevoEstudiante.edad);
    printf("Ingrese la calificación del estudiante: ");
    fflush(stdin);
    scanf("%f", &nuevoEstudiante.calificacion);
    return nuevoEstudiante;
}

// Función para crear un nuevo nodo de estudiante
TPtr creaNodo() {
    TPtr nuevo = (TPtr) malloc(sizeof(TNodo));
    if (nuevo != NULL) {
        nuevo->estudiante = Cargar_Estudiante();
        nuevo->sig = NULL;
    }
    return nuevo;
}

// Función para cargar una lista de estudiantes
void Cargar_Lista(TPtr* cabecera, int numEstudiantes) {
    TPtr nuevo, actual;
    int i;
    for (i = 0; i < numEstudiantes; i++) {
        nuevo = creaNodo();
        if (*cabecera == NULL) {  // Si la lista está vacía
            *cabecera = nuevo;
        } else {  // Si ya existen nodos en la lista
            actual = *cabecera;
            while (actual->sig != NULL) {
                actual = actual->sig;
            }
            actual->sig = nuevo;
        }
    }
}

// Función para mostrar la lista de estudiantes
void Mostrar_Lista(TPtr lista) {
    if (lista == NULL) {
        printf("La lista de estudiantes está vacía.\n");
    } else {
        TPtr actual = lista;
        while (actual != NULL) {
            printf("Nombre: %s, Edad: %d, Calificación: %.2f\n", 
                   actual->estudiante.nombre, actual->estudiante.edad, actual->estudiante.calificacion);
            actual = actual->sig;
        }
    }
}

// Función para buscar un estudiante en la lista por nombre
void Buscar_Estudiante(TPtr lista, const char* nombre) {
    TPtr actual = lista;
    int encontrado = 0;

    while (actual != NULL) {
        if (strcmp(actual->estudiante.nombre, nombre) == 0) {
            printf("Estudiante encontrado: Nombre: %s, Edad: %d, Calificación: %.2f\n", 
                   actual->estudiante.nombre, actual->estudiante.edad, actual->estudiante.calificacion);
            encontrado = 1;
            break;
        }
        actual = actual->sig;
    }
    
    if (!encontrado) {
        printf("El estudiante '%s' no se encuentra en la lista.\n", nombre);
    }
}
