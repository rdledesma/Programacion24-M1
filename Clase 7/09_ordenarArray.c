#include <stdio.h>
#include <string.h>

#define TM 30  // Tamaño máximo de cada nombre
#define NUM_PERSONAS 5  // Número de personas

typedef char tCadena[TM];  // Definir tipo tCadena

void leeCad(tCadena cad, int tam) {
    int j;
    char c;
    j = 0;
    c = getchar();
    while (c != EOF && c != '\n' && j < tam - 1) {
        cad[j] = c;
        j++;
        c = getchar();
    }
    cad[j] = '\0';  // Finaliza la cadena
    while (c != EOF && c != '\n')
        c = getchar();  // Limpia el buffer
}

int main() {
    tCadena personas[NUM_PERSONAS];
    tCadena temp;  // Cadena temporal para ordenar
    int i, j;

    // Leer los nombres de las personas
    for (i = 0; i < NUM_PERSONAS; i++) {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        leeCad(personas[i], TM);
    }

    // Ordenar los nombres alfabéticamente usando el método burbuja
    for (i = 0; i < NUM_PERSONAS - 1; i++) {
        for (j = i + 1; j < NUM_PERSONAS; j++) {
            if (strcmp(personas[i], personas[j]) > 0) {
                // Intercambiar personas[i] y personas[j] si no están en orden
                strcpy(temp, personas[i]);
                strcpy(personas[i], personas[j]);
                strcpy(personas[j], temp);
            }
        }
    }

    // Mostrar los nombres ordenados
    printf("\nNombres ordenados alfabéticamente:\n");
    for (i = 0; i < NUM_PERSONAS; i++) {
        printf("Persona %d: %s\n", i + 1, personas[i]);
    }

    return 0;
}
