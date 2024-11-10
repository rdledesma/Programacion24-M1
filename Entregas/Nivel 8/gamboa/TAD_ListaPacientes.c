#include "TAD_ListaPacientes.h"
#include <stdio.h>
#include <string.h>
/*COMPLETAR*/
TLista inicializa_lista(){
	TLista nvo;
	nvo.tam=0;
	return nvo;
}
int retorna_tam(TLista L){
	return L.tam;
}
TLista carga_pacientes(){
	TLista Lis=inicializa_lista();
	printf("Ingrese tamaño de la lista: ");scanf("%d",&Lis.tam);
	int i;
	for(i=0;i<=Lis.tam;i++){
        //Debe evitar la violación al encapsulamentiendo, 
        //podría hacer uso de cargarUnPaciente
		printf("Apellido: ");cargar_cadena(Lis.lis[i].ape);
		printf("Nombre: ");cargar_cadena(Lis.lis[i].nom);
		printf("Dni: ");scanf("%ld",&Lis.lis[i].dni);
		printf("tipo de atencion: 1.Clínica || 2.Odontología || 3.Traumatología");scanf("%d",&Lis.lis[i].tipo);
		printf("ingrese fecha: ");scanf("%ld",&Lis.lis[i].fecha);
	}
	return Lis;
}
void agrega_pacientes(TLista * L){
	L->tam++;
    //Debe evitar la violación al encapsulamentiendo, 
      //podría hacer uso de mostrarUnPaciente
	printf("Apellido: ");cargar_cadena(L->lis[L->tam].ape);
	printf("Nombre: ");cargar_cadena(L->lis[L->tam].nom);
	printf("Dni: ");scanf("%ld",&L->lis[L->tam].dni);
	printf("tipo de atencion: 1.Clínica || 2.Odontología || 3.Traumatología");scanf("%d",&L->lis[L->tam].tipo);
	printf("ingrese fecha: ");scanf("%ld",&L->lis[L->tam].fecha);
}
void elimina_pacientes(TLista *L){
	int i=0,b;printf("DNI a buscar: ");scanf("%d",&b);
    
    //Debe evitar la violación al encapsulamentiendo, 
    //podría hacer uso de retornaDNI(list[i])

	while(i<=L->tam){
		if(L->lis[i].dni == b){
			int j=i;
			while(j<=L->tam-1){
				L->lis[j]=L->lis[j+1];
				j++;
			}
			printf("Paciente eliminado.");
		}
		i++;
	}
}
void modifica_pacientes(TLista *L){
	int i,b;printf("DNI a buscar: ");scanf("%d",&b);
	for(i=0;i<=L->tam;i++){
    //Debe evitar la violación al encapsulamentiendo, 
    //podría hacer uso de retornaDNI(list[i])
		if(L->lis[i].dni == b){
			modificar_paciente(&L->lis[i]);
		}
	}
}
void mostra_pacientes(TLista L){
	int i;
	for(i=0;i<=L.tam;i++){
		mostrar_paciente(L.lis[i]);
	}
}
void genera_atencion(TLista Lis, TLista *ord){/*generar y mostrar ordenada la lista de atencion segun un tipo y una fecha*/
	int i,j=0,fb,ab;printf("ingrese fecha a buscar: aaaa-mm-dd");scanf("%d",&fb);
	printf("Atencion a buscar: ");scanf("%d",&ab);
	for(i=0;i<=Lis.tam;i++){
        //Debe evitar la violación al encapsulamentiendo, 
    //podría hacer uso de retornaFecha(list[i]), retornaTipo(lis[i])
		if(Lis.lis[i].fecha == fb && Lis.lis[i].tipo ==ab){
			ord->tam++;
			ord->lis[j]=Lis.lis[i];
			j++;
		}
	}
	ordena_pacientes(ord);
}
void sort(TLista *L,int ini, int fin){
	int izq, der, med=(ini+fin)/2;
	RPaciente piv;
	if (ini<fin){
		strcpy(piv.ape,L->lis[ini].ape);
		izq=0;
		der=L->tam;
		while (izq<der){
			while (der>izq && compara_apellidos((L->lis[der]),(piv))==1){
				der--;
				if (der>izq){
					L->lis[izq]=L->lis[der];
					izq++;
				}
				while (izq<der && compara_apellidos(L->lis[izq],piv)==-1){
					izq++;
					if (izq<der){
						L->lis[der]=L->lis[izq];
						der--;
					}}
			}
		}
		L->lis[der]=piv;
		med=der;
		sort(L,ini,med-1);
		sort(L,med+1,fin);
}
}


	
void ordena_pacientes(TLista *L){
	sort(L,0,L->tam);
}
int cantidad_pacientes(TLista Lis){/*cantidad de pacientes atendidos entre dos fechas*/
	int c=0,i,f1,f2;
	printf("Fecha 1:");scanf("%d",&f1);
	printf("Fecha 2:");scanf("%d",&f2);
	for(i=0;i<=Lis.tam;i++){
        //Debe evitar la violación al encapsulamentiendo, 
    //podría hacer uso de retornaFecha(list[i])
		if(Lis.lis[i].fecha>=f1 && Lis.lis[i].fecha<=f2)
			c++;
	}
	return c;
}
