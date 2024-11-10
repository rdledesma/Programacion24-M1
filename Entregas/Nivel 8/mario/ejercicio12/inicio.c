/*
Ejercicio 12: Diseñe un programa recursivo que permita mediante un menú, administrar una lista de
pacientes. Los datos a registrar por cada paciente serán: Apellido y Nombre, DNI, Tipo de Atención
(Clínica, Odontología, Traumatología), Fecha de Atención. El programa debe generar, dado un Tipo de
Atención y una Fecha de Atención, una nueva lista ordenada (Q-Sort) por el Apellido de los pacientes,
que se deben atender ese día. También dadas dos fechas indicar la cantidad de pacientes que se han
atendido entre esas fechas.
*/
#include <stdio.h>
#include "vector.h"

void menuR(Tlista,Tlista *);

int main(){
	
	Tlista lis,nlis;
	
	lis= inicializarLis();
	
	
	lis= cargarLis();
	menuR(lis,&nlis);
	return 0;
}
short opciones(){
	short opc;
	printf("===========MENU=========\n");
	printf("1) generar lists, dado un Tipo de Atención y una Fecha de Atención\n");
	printf("2) dadas dos fechas indicar la cantidad de pacientes que se han atendido entre esas fechas.\n");
	printf("3) Mostrar lista\n");
	printf("0) salir\n");
	printf("=======================\n");
	printf("ingrese una opcion:");
	scanf("%hd",&opc);
	fflush(stdin);
	return opc;
}
void menuR(Tlista lis,Tlista *nlis){
	short opc;
	int cant=0;
	opc=opciones();
	
	
	if(opc!=0){
		switch(opc){
		case 1:
			printf("=========generar lista , dado un Tipo de Atención y una Fecha de Atención=========\n");
			generarLis(lis,nlis);
			ordena_pacientes(nlis);  
			
			break;
		case 2:
			printf("=========dadas dos fechas indicar la cantidad de pacientes que se han atendido entre esas fechas=========\n");
			cant=indicaPasLis(lis);
			printf("la cantidad de pacientes en esa fecha es de %d pacientes\n",cant);
			break;
		case 3:
			printf("=========mostrar lista v=========\n");
			
			mostrarLis(lis);
			printf("=========mostrar lista A=========\n");
			mostrarLis(*nlis);
			break;
		case 0:
			printf("=========SALIR=========\n");
			break;
		}
		menuR(lis,nlis);
	}
;
}
