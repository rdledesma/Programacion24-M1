#ifndef VECTOR_H
#define VECTOR_H
#include "registro.h"

typedef Tpaciente Tvec[50];
typedef struct{
	Tvec vec;
	int tam;
}Tlista;



Tlista inicializarLis();
Tlista cargarLis();

/*
//======opciones========
void generarLis(Tlista,Tlista)*/
int indicaPasLis(Tlista);
void mostrarLis(Tlista);
void ordena_pacientes(Tlista*);
#endif
