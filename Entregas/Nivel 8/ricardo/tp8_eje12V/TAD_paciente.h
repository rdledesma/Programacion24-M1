#ifndef TAD_PACIENTE_H
#define TAD_PACIENTE_H
#include "TAD_fecha.h"
typedef struct{
	Tcad nom,ape;
	fecha fatencion;
	int tipo_atencion;
	long DNI;
}paciente;
paciente cargaR();
void mostraR(paciente);
#endif
