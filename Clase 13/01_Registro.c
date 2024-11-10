#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int edad;
    float calificacion;
} Estudiante;

typedef Estudiante* EstudiantePtr;

EstudiantePtr CrearEstudiante();
void MostrarEstudiante(EstudiantePtr);
void OrdenarPorCalificacion(EstudiantePtr*, EstudiantePtr*, EstudiantePtr*);
void EliminarEstudiante(EstudiantePtr*);

int main(void) {
    EstudiantePtr estudianteA, estudianteB, estudianteC;
    estudianteA = estudianteB = estudianteC = NULL;

    estudianteA = CrearEstudiante();
    estudianteB = CrearEstudiante();
    estudianteC = CrearEstudiante();

    OrdenarPorCalificacion(&estudianteA, &estudianteB, &estudianteC);

    MostrarEstudiante(estudianteA);
    MostrarEstudiante(estudianteB);
    MostrarEstudiante(estudianteC);
    EliminarEstudiante(&estudianteA);

    
    return 0;
}

EstudiantePtr CrearEstudiante() {
    EstudiantePtr nuevoEstudiante;
    nuevoEstudiante = (EstudiantePtr) malloc(sizeof(Estudiante));

    printf("Ingrese nombre: ");
    scanf("%s", nuevoEstudiante->nombre);
    printf("Ingrese edad: ");
    scanf("%d", &nuevoEstudiante->edad);
    printf("Ingrese calificación: ");
    scanf("%f", &nuevoEstudiante->calificacion);

    return nuevoEstudiante;
}

void MostrarEstudiante(EstudiantePtr estudiante) {
    printf("\nNombre: %s", estudiante->nombre);
    printf("\nEdad: %d", estudiante->edad);
    printf("\nCalificación: %.2f\n", estudiante->calificacion);
}

void OrdenarPorCalificacion(EstudiantePtr* A, EstudiantePtr* B, EstudiantePtr* C) {
    EstudiantePtr aux;

    // Ordenar el primer y segundo estudiante por calificación
    if ((*B)->calificacion < (*A)->calificacion) {
        aux = *A;
        *A = *B;
        *B = aux;
    }

    // Ordenar el segundo y tercer estudiante por calificación
    if ((*C)->calificacion < (*B)->calificacion) {
        aux = *B;
        *B = *C;
        *C = aux;
    }

    // Ordenar nuevamente el primero y segundo estudiante por calificación
    if ((*B)->calificacion < (*A)->calificacion) {
        aux = *A;
        *A = *B;
        *B = aux;
    }
}

// Función EliminarEstudiante
void EliminarEstudiante(EstudiantePtr* estudiante) {
    if (*estudiante != NULL) {  // Verificamos si el puntero no es NULL
        free(*estudiante);      // Liberamos la memoria asignada al estudiante
        *estudiante = NULL;     // Asignamos NULL al puntero para evitar un dangling pointer
    }
}
