#include "TAD_lista.h"
void menuRec(lista);
int main() {
	lista A;
	A=cargaLista();
	menuRec(A);
	return 0;
}
void menuRec(lista A){
	lista B;
	int opcion;
	printf("\n menu de opciones:");
	printf("\n\t opcion 0: salir \n\t opcion 1: mostrar lista \n\t opcion 2: atenciones del dia  \n\t opcion 3:cantidad de atenciones realizadas entre 2 fechas");
	printf("\ningrese una opcion:");
	scanf("%d",&opcion);
	switch(opcion){
	case 0:
		printf("\n hasta luego");
		break;
	case 1:
		muestraLista(A);
		menuRec(A);
		break;
	case 2:
		B=atencion_fecha(A);
		muestraLista(B);
		menuRec(A);
		break;
	case 3:
		CantPac(A);
		menuRec(A);
		break;
	default:
		printf("\n ingreso una opcion no vcalida:");
		menuRec(A);
	}
}
