#include <stdio.h>
#include <string.h>

#define TM 50  // Tamaño máximo de las cadenas

// Definimos el tipo tCadena
typedef char tCadena[TM];

// Definimos la estructura de un domicilio
struct Domicilio {
    tCadena calle;
    int numero;
    int codigoPostal;
    tCadena ciudad;
};

// Definimos la estructura de un estudiante
struct Estudiante {
    tCadena nombre;
    int edad;
    int matricula;
    struct Domicilio domicilio;  // Agregamos la estructura Domicilio como un campo
};

// Prototipos de funciones
struct Estudiante crearEstudiante();  // Ahora retorna un Estudiante
void leerEstudiante(struct Estudiante est);
void actualizarEstudiante(struct Estudiante *est);
void eliminarEstudiante(struct Estudiante *est);

// Función para leer una cadena desde el teclado
void leeCad(tCadena cad, int tam) {
    int j = 0;
    char c;
    c = getchar();  // Leemos el primer carácter
    while (c != EOF && c != '\n' && j < tam - 1) {
        cad[j] = c;
        j++;
        c = getchar();  // Continuamos leyendo caracteres
    }
    cad[j] = '\0';  // Terminar la cadena con '\0'
    while (c != EOF && c != '\n')  // Vaciar el buffer si hay más caracteres
        c = getchar();
}

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
        getchar();  // Limpiar el salto de línea del buffer de entrada

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
    leeCad(est.nombre, TM);
    printf("Edad: ");
    scanf("%d", &est.edad);
    printf("Matrícula: ");
    scanf("%d", &est.matricula);
    getchar();  // Limpiar el salto de línea del buffer de entrada

    // Datos del domicilio
    printf("\n--- Ingresar Domicilio ---\n");
    printf("Calle: ");
    leeCad(est.domicilio.calle, TM);
    printf("Número: ");
    scanf("%d", &est.domicilio.numero);
    printf("Código Postal: ");
    scanf("%d", &est.domicilio.codigoPostal);
    getchar();  // Limpiar el salto de línea del buffer de entrada
    printf("Ciudad: ");
    leeCad(est.domicilio.ciudad, TM);

    printf("Estudiante creado con éxito!\n");

    return est;  // Retornamos el estudiante creado
}

// Función para leer (mostrar) los datos de un estudiante
void leerEstudiante(struct Estudiante est) {
    printf("\n--- Datos del Estudiante ---\n");
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d\n", est.edad);
    printf("Matrícula: %d\n", est.matricula);
    printf("\n--- Domicilio ---\n");
    printf("Calle: %s\n", est.domicilio.calle);
    printf("Número: %d\n", est.domicilio.numero);
    printf("Código Postal: %d\n", est.domicilio.codigoPostal);
    printf("Ciudad: %s\n", est.domicilio.ciudad);
}

// Función para actualizar los datos de un estudiante
void actualizarEstudiante(struct Estudiante *est) {
    printf("\n--- Actualizar Estudiante ---\n");
    printf("Nombre actual: %s\n", est->nombre);
    printf("Nuevo nombre: ");
    leeCad(est->nombre, TM);
    printf("Edad actual: %d\n", est->edad);
    printf("Nueva edad: ");
    scanf("%d", &est->edad);
    getchar();  // Limpiar el salto de línea del buffer de entrada

    // Actualizar domicilio
    printf("\n--- Actualizar Domicilio ---\n");
    printf("Calle actual: %s\n", est->domicilio.calle);
    printf("Nueva calle: ");
    leeCad(est->domicilio.calle, TM);
    printf("Número actual: %d\n", est->domicilio.numero);
    printf("Nuevo número: ");
    scanf("%d", &est->domicilio.numero);
    printf("Código Postal actual: %d\n", est->domicilio.codigoPostal);
    printf("Nuevo Código Postal: ");
    scanf("%d", &est->domicilio.codigoPostal);
    getchar();  // Limpiar el salto de línea del buffer de entrada
    printf("Ciudad actual: %s\n", est->domicilio.ciudad);
    printf("Nueva ciudad: ");
    leeCad(est->domicilio.ciudad, TM);

    printf("Estudiante actualizado con éxito!\n");
}

// Función para eliminar un estudiante (borrar los datos)
void eliminarEstudiante(struct Estudiante *est) {
    printf("\n--- Eliminar Estudiante ---\n");
    strcpy(est->nombre, "");  // Limpiamos el nombre
    est->edad = 0;            // Reiniciamos la edad
    est->matricula = 0;       // Reiniciamos la matrícula

    // Limpiar datos del domicilio
    strcpy(est->domicilio.calle, "");
    est->domicilio.numero = 0;
    est->domicilio.codigoPostal = 0;
    strcpy(est->domicilio.ciudad, "");

    printf("Estudiante eliminado con éxito!\n");
}
