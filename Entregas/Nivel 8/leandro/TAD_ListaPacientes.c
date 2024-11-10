#include "TAD_ListaPacientes.h"
#include <stdio.h>

/*COMPLETAR*/
int retorna_tam(TLista aux){return aux.tam;}

TLista inicializa_lista(){
	TLista Aux;
	
	Aux.tam=0;

	return Aux;
}

void CargaVectorRec(TVector Vec, int T){
	if (T>1)
		CargaVectorRec(Vec,T-1);
	printf("\n Ingresa los datos del paciente . . .");
	Vec[T]=cargar_paciente();}
	
TLista carga_pacientes(){
	TLista Aux;
	printf("\n ingresa el tamaño de la lista:");
	scanf("%d",&Aux.tam);
	CargaVectorRec(Aux.lis,Aux.tam);
	return Aux;
}

void AgregueUno(TVector Vec, int* tam){
	++*tam;
	Vec[*tam]=cargar_paciente();
}

void agrega_pacientes(TLista* Lista){
	AgregueUno(Lista->lis,&Lista->tam);
}
int BuscaDniRecursivoSEC(TVector Vec, int tam, long dni){
	if (tam>0){
		if(compara_DNI(Vec[tam],dni))
		   return tam;
	
	else{
		return(BuscaDniRecursivoSEC(Vec,tam-1,dni));}
	}
	else 
		return -1;
}
void eliminaRecursivo(TVector Vec, int Tam,int pos){
	if (pos<Tam){
		Vec[pos]=Vec[pos+1];
		eliminaRecursivo(Vec,Tam,pos+1);
	}
}
void elimina_pacientes(TLista *Pacientes){
	int pos;
	long dni;
	printf("\nIngresa el Dni a buscar: ");
	scanf("%ld",&dni);
	pos=BuscaDniRecursivoSEC(Pacientes->lis,Pacientes->tam,dni);
	if (pos>0){
		eliminaRecursivo(Pacientes->lis,Pacientes->tam,dni);
		Pacientes->tam--;
	}
	else
		printf("\n no se encontro a nadie con ese dni. . .");
	
}
void ModificaRecursivo(TVector Vec, int Tam, int opc){
	if(opc==1){
		int pos;
		long dni;
		printf("\n ingrese el dni a buscar . . .");
		scanf("%ld",&dni);
		pos=BuscaDniRecursivoSEC(Vec,Tam,dni);
		if(pos>0)
			modificar_paciente(&Vec[pos]);
		else
			printf("\n No se encontro tal DNI. . .");
		printf("\n desea modificar otro paciente? \n1.si \n2.no");
		scanf("%d",&opc);
		ModificaRecursivo(Vec,Tam,opc);
	}
	
}

void modifica_pacientes(TLista *Pacientes){
	ModificaRecursivo(Pacientes->lis,Pacientes->tam,1);
}

void muestraRecursivo(TVector Vec, int tam){
	if(tam>1)
		muestraRecursivo(Vec,tam-1);
	printf("\n los datos del paciente. . .");
	mostrar_paciente(Vec[tam]);
	printf("\n---------------");
}	
	
void mostra_pacientes(TLista Pacientes){
	muestraRecursivo(Pacientes.lis,Pacientes.tam);
}

void GenerarVectorNuevo(TVector Vec1, int Tam1, TVector VecG, int *Tam2,int tipo,long fecha){
	if(Tam1>1){
		GenerarVectorNuevo(Vec1,Tam1-1,VecG,Tam2,tipo,fecha);
	}
	if(compara_fecha_tipo(Vec1[Tam1],fecha,tipo));
	++*Tam2;
	VecG[*Tam2]=Vec1[Tam1];
		
}	

	
void QuickSort(TVector Vec, int ini, int fin){
	int izq,der,med;
	RPaciente piv;
	if(ini<fin){
		piv=Vec[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while((der>izq)&&(compara_apellidos(Vec[der],piv)>0))
				der--;
			if(der>izq){
				Vec[izq]=Vec[der];
				izq++;
			}
			while((izq<der)&&(compara_apellidos(Vec[izq],piv)<0))
			   izq++;
			if(izq<der){
				Vec[der]=Vec[izq];
				der--;
			}
			
		}
		Vec[der]=piv;
		med=der;
		QuickSort(Vec,ini,med-1);
		QuickSort(Vec,med+1,fin);
	}
}
	
void genera_atencion(TLista Pacientes, TLista *Nuevos){
	long fecha;
	int tipo;
	printf("\ningrese la fecha de atencion para una nueva lista del formato (aaaammdd)");
	scanf("%ld",&fecha);
	printf("\n Ingrese el tipo de especializacion. . . .");
	scanf("%d",&tipo);
	*Nuevos=inicializa_lista();
	GenerarVectorNuevo(Pacientes.lis,Pacientes.tam,Nuevos->lis,&Nuevos->tam,tipo,fecha);
	ordena_pacientes(Nuevos);
}
void ordena_pacientes(TLista *ListaNueva){
	QuickSort(ListaNueva->lis,1,ListaNueva->tam);
}

void ContarPacientesRec(TVector Vector, int tam, long fechaini,long fechafin,int *Contador ){
	if(tam>0)
		ContarPacientesRec(Vector,tam-1,fechaini,fechafin,Contador);
	if(compara_fecha(Vector[tam],fechaini,fechafin))
		Contador++;
}

int cantidad_pacientes(TLista Lista){
	long Fecha1, Fecha2;
	int Contador;
	Contador=0;
	printf("\n Ingresa la fecha inicial (aaaammdd)");
	scanf("%ld",&Fecha1);
	printf("\n Ingresa la fecha final(aaaammdd)");
	scanf("%ld",&Fecha2);
	ContarPacientesRec(Lista.lis,Lista.tam,Fecha1,Fecha2,&Contador);
	return Contador;
} 
