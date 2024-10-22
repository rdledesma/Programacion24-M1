#include "persona.h"
#include <stdio.h>
#include <string.h>

Persona crearPersona(const char *nombre, int edad, float altura) {
    Persona p;
    strncpy(p.nombre, nombre, 50);
    p.edad = edad;
    p.altura = altura;
    return p;
}

void imprimirPersona(Persona p) {
    printf("Nombre: %s, Edad: %d, Altura: %.2f\n", p.nombre, p.edad, p.altura);
}
