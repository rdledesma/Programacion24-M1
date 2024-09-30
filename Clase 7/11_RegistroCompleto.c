#include <stdio.h>

#define TM 20

// Definimos tCadena como un array de caracteres de tamaño TM
typedef char tCadena[TM];

// Definición de la estructura para fechas
typedef struct {
    int Dia, Mes, Anio;
} tregFecha;

// Definición de la estructura para una persona
typedef struct {
    tCadena Apellido;
    tCadena Nombre;
    tregFecha FechaNacimiento;
} tregPersona;

// Prototipos de funciones
void leeCad(tCadena cad, int tam);
void leerFecha(tregFecha *fecha);
void mostrarPersona(tregPersona persona);

int main() {
    tregPersona persona;  // Variable para almacenar los datos de una persona

    // Cargar los datos de la persona
    printf("Ingrese el apellido de la persona: ");
    leeCad(persona.Apellido, TM);
    
    printf("Ingrese el nombre de la persona: ");
    leeCad(persona.Nombre, TM);

    printf("Ingrese la fecha de nacimiento (DD MM AAAA): ");
    leerFecha(&persona.FechaNacimiento);

    // Mostrar los datos de la persona
    mostrarPersona(persona);

    return 0;
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

// Función para leer una fecha desde el teclado
void leerFecha(tregFecha *fecha) {
    scanf("%d %d %d", &fecha->Dia, &fecha->Mes, &fecha->Anio);
}

// Función para mostrar los datos de una persona
void mostrarPersona(tregPersona persona) {
    printf("\nDatos de la persona:\n");
    printf("Apellido: %s\n", persona.Apellido);
    printf("Nombre: %s\n", persona.Nombre);
    printf("Fecha de Nacimiento: %02d/%02d/%04d\n", persona.FechaNacimiento.Dia, 
                                                   persona.FechaNacimiento.Mes, 
                                                   persona.FechaNacimiento.Anio);
}
