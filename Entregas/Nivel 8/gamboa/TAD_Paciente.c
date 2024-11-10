#include "TAD_Paciente.h"
#include <stdlib.h>
#include <stdio.h>

RPaciente cargar_paciente(){
	RPaciente nvo;
	fflush(stdin);
	printf("\nIngrese el Nombre del paciente: ");
	cargar_cadena(nvo.nom);
	printf("\nIngrese el Apellido del paciente: ");
	cargar_cadena(nvo.ape);
	printf("\nIngrese el DNI del paciente: ");
	scanf("%ld", & nvo.dni);
	printf("\nTipo de atencion; 1: Clinica, 2: Odontologia o 3: Traumatologia");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & nvo.tipo);
	printf("\nIngrese Fecha de atencion aaaammdd: ");
	scanf("%ld", & nvo.fecha);
	return nvo;
}
void mostrar_paciente(RPaciente pac){
	int a, m, d;
	long f;
	f= pac.fecha;
	d= f%100;
	f= f/100;
	m= f%100;
	a= f/100;
	printf("\nNombre y Apellido del paciente: %s %s", pac.nom, pac.ape);
	printf("\nDNI del paciente: %ld ----- Su fecha de atencion es: %d/ %d/ %d", pac.dni, d, m, a);
	switch (pac.tipo){
	case 1: printf("\nAtencion solicitada para: Clinica");
			break;
	case 2: printf("\nAtencion solicitada para: Odontologia");
			break;
	case 3: printf("\nAtencion solicitada para: Traumatologia");
			break;
	};
}
void modificar_paciente(RPaciente *pac){
	RPaciente npac;
	npac= *pac;
	printf("\n---- Datos actuales del paciente ----");
	mostrar_paciente(npac);
	printf("\n---- Modificar todos los Datos actuales del paciente ----");
	npac= cargar_paciente();
	*pac= npac;
}
long retorna_DNI(RPaciente pac){
	return pac.dni;
}
int compara_DNI(RPaciente pac, long DNI){
	if(pac.dni==DNI) return 1;
	else return 0;
}
int compara_fecha(RPaciente pac, long f1, long f2){
	if(pac.fecha<=f2 && pac.fecha>=f1) return 1;
		else return 0;
}
int compara_fecha_tipo(RPaciente pac, long f1, int tipo){
	if(pac.fecha==f1 && pac.tipo==tipo) return 1;
	else return 0;
}
int compara_apellidos(RPaciente pac1, RPaciente pac2){
	if (compara_cadena(pac1.ape, pac2.ape)==1) return 1;
	else if (compara_cadena(pac1.ape, pac2.ape)==0) return 0;
		 else return -1;
}
