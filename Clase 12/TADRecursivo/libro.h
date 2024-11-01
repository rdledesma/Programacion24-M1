#ifndef AGENDA_H
#define AGENDA_H
#include <string.h>
#include "cadena.h"

typedef struct{
    Tcadena titulo;
    long ISBN;
    int cantidad;
    float precio;
    Tcadena edit;
}libro;

libro creaLibro(void);
void muestraLibro(libro);

int comparaEditorial(libro, Tcadena);
int disponibilidad(libro);
int esmayor(libro, libro);
int esmenor(libro, libro);
int cantidad(libro l );
int ISBN(libro l);
#endif