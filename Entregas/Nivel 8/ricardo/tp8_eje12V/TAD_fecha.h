#ifndef TAD_FECHA_H
#define TAD_FECHA_H
#include "TAD_cadena.h"
typedef struct{
	int d,m,a;
}fecha;
fecha cargaF();
void muestraF(fecha);
#endif
