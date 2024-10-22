#ifndef PERSONA_H
#define PERSONA_H

typedef struct {
    char nombre[50];
    int edad;
    float altura;
} Persona;

Persona crearPersona(const char *nombre, int edad, float altura);
void imprimirPersona(Persona p);

#endif
