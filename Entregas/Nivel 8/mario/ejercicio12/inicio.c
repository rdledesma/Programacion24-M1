/*
Ejercicio 12: Dise�e un programa recursivo que permita mediante un men�, administrar una lista de
pacientes. Los datos a registrar por cada paciente ser�n: Apellido y Nombre, DNI, Tipo de Atenci�n
(Cl�nica, Odontolog�a, Traumatolog�a), Fecha de Atenci�n. El programa debe generar, dado un Tipo de
Atenci�n y una Fecha de Atenci�n, una nueva lista ordenada (Q-Sort) por el Apellido de los pacientes,
que se deben atender ese d�a. Tambi�n dadas dos fechas indicar la cantidad de pacientes que se han
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
	printf("1) generar lists, dado un Tipo de Atenci�n y una Fecha de Atenci�n\n");
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
			printf("=========generar lista , dado un Tipo de Atenci�n y una Fecha de Atenci�n=========\n");
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
