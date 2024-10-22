#include <stdio.h>
#include <string.h>

#define TM 50  // Tamaño máximo de las cadenas

// Definimos el tipo tCadena
typedef char tCadena[TM];

// Definimos la estructura de un domicilio
typedef struct {
    tCadena calle;
    int numero;
    int codigoPostal;
    tCadena ciudad;
} Domicilio;

// Definimos la estructura de un estudiante
typedef struct {
    tCadena nombre;
    int edad;
    int matricula;
    Domicilio domicilio;  // Usamos el typedef para simplificar
} Estudiante;

// Definimos un array de 10 estudiantes
typedef Estudiante Estudiantes[10];

void modificaEstudiante(Estudiantes, int);


int main() {
    Estudiantes estudiantes;  // Creamos un array de 10 estudiantes

    // Ejemplo de inicialización de un estudiante
    strcpy(estudiantes[0].nombre, "Juan Pérez");
    estudiantes[0].edad = 20;
    estudiantes[0].matricula = 12345;

    strcpy(estudiantes[0].domicilio.calle, "Calle Falsa");
    estudiantes[0].domicilio.numero = 123;
    estudiantes[0].domicilio.codigoPostal = 45678;
    strcpy(estudiantes[0].domicilio.ciudad, "Ciudad X");

    // Imprimimos los datos del primer estudiante
    printf("Nombre: %s\n", estudiantes[0].nombre);
    printf("Edad: %d\n", estudiantes[0].edad);
    printf("Matrícula: %d\n", estudiantes[0].matricula);
    printf("Domicilio: %s, %d, %s (%d)\n",
           estudiantes[0].domicilio.calle,
           estudiantes[0].domicilio.numero,
           estudiantes[0].domicilio.ciudad,
           estudiantes[0].domicilio.codigoPostal);

    modificaEstudiante(estudiantes, 0);

    // Imprimimos los datos del primer estudiante
    printf("Nombre: %s\n", estudiantes[0].nombre);
    printf("Edad: %d\n", estudiantes[0].edad);
    printf("Matrícula: %d\n", estudiantes[0].matricula);
    printf("Domicilio: %s, %d, %s (%d)\n",
           estudiantes[0].domicilio.calle,
           estudiantes[0].domicilio.numero,
           estudiantes[0].domicilio.ciudad,
           estudiantes[0].domicilio.codigoPostal);


    return 0;
}


void modificaEstudiante(Estudiantes listEst, int idx){
    printf("\n Inicio Modificación");

    strcpy(listEst[idx].nombre, "Raul");
    listEst[idx].domicilio.codigoPostal = 123;

    printf("\n Modificación realizada");
}
