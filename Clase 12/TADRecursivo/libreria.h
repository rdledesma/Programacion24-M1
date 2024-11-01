#ifndef LIBRERIA_H
#define LIBRERIA_H

#define MAX_LIB 10

#include "libro.h"

typedef struct libreria 
{
    libro lista [MAX_LIB];
    int tam;
}libreria;

libreria crear();
void agregaFin(libreria*);
void muestra(libreria);
libreria filtraEditorial(libreria, Tcadena);
libreria filtraDisponibles(libreria);
void qSort(libreria *, int, int);


void muestraPorEditorial(libreria);
void cuentaDisponibilidad(libreria);
void eliminarLibro(libreria*);
#endif