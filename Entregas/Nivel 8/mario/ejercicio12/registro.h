#ifndef REGISTRO_H
#define REGISTRO_H

#include "cadena.h"

typedef struct{
	int dia;
	int mes;
	int anio;
}Tfecha;

typedef struct{
	Tcad nom;
	Tcad ape;
	long dni;
	short tipo;
	Tfecha fecha;
}Tpaciente;

Tpaciente cargarRegistro();
void mostrarReg(Tpaciente);
int retDia(Tpaciente);
int retMes(Tpaciente);
int retAnio(Tpaciente);
int retTurno(Tpaciente);



#endif
