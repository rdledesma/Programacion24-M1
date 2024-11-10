#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "TAD_paciente.h"
typedef paciente T_lis[max];
typedef struct{
	T_lis L_paciiente;
	int tam;
}lista;
lista cargaLista();
void muestraLista(lista);
lista atencion_fecha(lista);
void CantPac(lista);
#endif
