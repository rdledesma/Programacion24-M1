#include "TAD_paciente.h"
int comparaApellidos(paciente A,paciente B);
int Tatencion(){
	int r;
	printf("\n eliga el tipo de atencion que desea:");
	printf("\n\t atencion 1: clinica \n\t atencion 2: odontologia \n\t atencion 3: traumatologia");
	printf("\n escoga una opcion:");
	scanf("%d",&r);
	if(r!=1 && r!=2 && r!=3)
		return Tatencion();
	else
		return r;
}
void Matencion(int A){
	switch(A){
	case 1: printf("\n atencion clinica"); break;
	case 2: printf("\n atencion odontologica"); break;
	case 3: printf("\n atencion traumatologica"); break;
	}
}
int rtAtencion(paciente A){
	return A.tipo_atencion;
}
int compAtencion(paciente A,int atc){
	if(rtAtencion(A)==atc)
		return 1;
	else
		return 0;
}
paciente cargaR(){
	paciente aux;
	printf("\n ingrese el nombre:");
	cargaCad(aux.nom);
	printf("\n ingrese apellido:");
	cargaCad(aux.ape);
	printf("\n ingrese el DNI:");
	scanf("%ld",&aux.DNI);
	printf("ingrese la fecha de atencion:");
	aux.fatencion=cargaF();
	aux.tipo_atencion=Tatencion();
	return aux;
}
void mostraR(paciente A){
	printf("\n nombre:%s",A.nom);
	printf("\n apellido:%s",A.ape);
	printf("\n DNI:%ld",A.DNI);
	printf("\n fecha de atencion:");
	muestraF(A.fatencion);
	Matencion(A.tipo_atencion);
}
int comparaApellidos(paciente A,paciente B){
	return compCadena(A.ape,B.ape);
}
