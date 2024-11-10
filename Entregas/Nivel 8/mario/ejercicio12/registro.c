#include "registro.h"

Tpaciente cargarRegistro(){
	Tpaciente aux;
	printf("ingrese nombre:");
	Leecad(aux.nom);

	printf("ingrese apellido:");
	Leecad(aux.ape);
	
	printf("ingrese un dni:");
	scanf("%ld",&aux.dni);
	
	printf("ingrese un tipo(Clínica [1], Odontología [2], Traumatología [3]):");
	scanf("%hd",&aux.tipo);

	printf("ingrese  fecha de atencion:");
	printf("ingrese el dia:");
	scanf("%d",&aux.fecha.dia);

	printf("ingrese el mes:");
	scanf("%d",&aux.fecha.mes);

	printf("ingrese el año:");
	scanf("%d",&aux.fecha.anio);
	fflush(stdin);
	
	return aux;

}
void mostrarReg(Tpaciente AUX){
	printf("Su nombre:%s\n",AUX.nom);
	printf("Su apellido:%s\n",AUX.ape);	
	printf("Su  dni: %ld\n",AUX.dni);
	printf("Su tipo de atencion:%hd\n",AUX.tipo);
	printf(" La fecha:%d/%d/%d\n",AUX.fecha.dia,AUX.fecha.mes,AUX.fecha.anio);
}
int retDia(Tpaciente aux){
	return aux.fecha.dia;
}
int retMes(Tpaciente aux ){
	return aux.fecha.mes;
}
int retAnio(Tpaciente aux){
	return aux.fecha.anio;
}
int retTurno(Tpaciente aux){
	return aux.tipo;
}	
int compara_apellidos(Tpaciente pac1, Tpaciente pac2){
	if (compara_cadena(pac1.ape, pac2.ape)==1) return 1;
	else if (compara_cadena(pac1.ape, pac2.ape)==0) return 0;
	else return -1;
}
