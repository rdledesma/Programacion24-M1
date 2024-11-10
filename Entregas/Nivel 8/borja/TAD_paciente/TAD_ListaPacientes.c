#include "TAD_ListaPacientes.h"
#include <stdio.h>
TLista carga_pacientes(){
	TLista Aux;
	int i;
	printf("\nIngrese el tamaño de la lista: ");
	scanf("%d", &Aux.tam);
	for(i=1;i<=Aux.tam;i++){
		Aux.lis[i]=cargar_paciente();
	}
	return Aux;
}
void agrega_pacientes(TLista *A){
	A->lis[A->tam+1]=cargar_paciente();
}
