#include "vector.h"


Tlista inicializarLis(){
	Tlista L;
	L.tam=0;
	return L;
}
Tlista cargarLis(){
	Tlista lis;
	short N;
	printf("ingrese cantidad de pacientges:");
	scanf("%hd",&N);
	fflush(stdin);

	lis.tam=N;
	cargaVectorR(lis.vec,lis.tam);
	return lis;
}

void mostrarLis(Tlista lis){
	mostrarVectorR(lis.vec,lis.tam);
}

void generarLis(Tlista lis,Tlista *nlis){
	int dia,mes;
	int jj;
	short turno;
	
	printf("ingrese  fecha de atencion:");
	printf("ingrese el dia:");
	scanf("%d",&dia);
	
	printf("ingrese el mes:");
	scanf("%d",&mes);
	
	printf("ingrese el año:");
	scanf("%d",&jj);


	printf("ingrese un tipo de atencion(Clínica [1], Odontología [2], Traumatología [3]):");
	scanf("%hd",&turno);
	//fflush(stdin);
		//printf(" Ingresado###- Dia: %d, Mes: %d, Anio: %d, Turno:%hd\n", dia, mes, jj,turno);
	*nlis=inicializarLis();//printf("tam gen:%d\n",nlis->tam);

	generaVecR(lis.vec,lis.tam,nlis->vec,&nlis->tam,turno,dia,mes,jj);
	//nlis->tam=3;
	
	//printf("tam gen:%d\n",nlis->tam);
	//printf("\n");
	//mostrarVectorR(,Atam);
}
	
//========modulos privados==========
void cargaVectorR(Tvec v,int tam){
	if(tam>0){
		cargaVectorR(v,tam-1);
		v[tam]=cargarRegistro();
	}
}
void mostrarVectorR(Tvec v,int tam){
	if(tam>0){
		mostrarVectorR(v,tam-1);
		mostrarReg(v[tam]);
	}
}

void generaVecR(Tvec v, int tam, Tvec A, int *Atam, short turno, int dia, int mes, int anio) {
	//printf("Comparando: Ingresado - Dia: %d, Mes: %d, Anio: %d\n", dia, mes,anio);
	if (tam > 0) {
		//printf("Comparando: Ingresado - Dia: %d, Mes: %d, Anio: %d\n", dia, mes, anio);
		//printf("Registro - Dia: %d, Mes: %d, Año: %d\n", retDia(v[tam]), retMes(v[tam]), retAnio(v[tam]));
		
		if ((dia == retDia(v[tam])) && (mes == retMes(v[tam]))&& anio == retAnio(v[tam]) && turno == retTurno(v[tam]) ) {
			
			(*Atam)++;
			//printf("hola\n");
			A[*Atam] = v[tam];
			generaVecR(v, tam - 1, A, Atam, turno, dia, mes, anio);
		} else {
			generaVecR(v, tam - 1, A, Atam, turno, dia, mes, anio);//printf("chau\n");
			
		}
	}
}
void QSort_rec(Tvec A, int ini, int fin){
	Tpaciente piv;
	int izq, der, med;
	if (ini<fin) { 	
		piv=A[ini];
		izq=ini;
		der=fin;
		while (izq<der) {
			while (der>izq && compara_apellidos(A[der], piv)==1)
				der--;
			if (der>izq) {	
				A[izq]=A[der];
				izq++; 
			}
			while (izq<der && compara_apellidos(A[izq], piv)==-1)
				izq++;
			if (izq<der){
				A[der]=A[izq];
				der--; 
			}
			
		}
		A[der]=piv; 
		med=der;
		QSort_rec(A,ini,med-1);
		QSort_rec(A,med+1,fin);
	}
}
void ordena_pacientes(Tlista *nlis){  
	int ini, fin;
	ini=1;
	fin= nlis->tam;
	QSort_rec(nlis->vec, ini, fin);
}
//dia == retDia(v[tam]) && mes == retMes(v[tam]) && anio == retAnio(v[tam]) && turno == retTurno(v[tam])
int indicaPasLis(Tlista lis){
	int dia,mes,anio,dia2,mes2,anio2;
	printf("ingrese  fecha de atencion\n");
	printf("ingrese el dia:");
	scanf("%d",&dia);
	
	printf("ingrese el mes:");
	scanf("%d",&mes);
	
	printf("ingrese el año:");
	scanf("%d",&anio);
	
	
	printf("ingrese  fecha de atencion\n");
	printf("ingrese el dia:");
	scanf("%d",&dia2);
	
	printf("ingrese el mes:");
	scanf("%d",&mes2);
	
	printf("ingrese el año:");
	scanf("%d",&anio2);
	
	return indicaPasVecR(lis.vec,lis.tam,dia,mes,anio,dia2,mes2,anio2);
}

int indicaPasVecR(Tvec v,int tam,int dia,int mes,int anio,int dia2,int mes2, int anio2){
	if(tam>0){
		if(dia<=retDia(v[tam]) && mes<=retMes(v[tam]) && anio<=retAnio(v[tam]) && retDia(v[tam])<=dia2 && mes<=retMes(v[tam])<=mes2 && retAnio(v[tam])<=anio2 ){
			return 1+ indicaPasVecR(v,tam-1,dia,mes,anio,dia2,mes2,anio2);
		}
		else
		   indicaPasVecR(v,tam-1,dia,mes,anio,dia2,mes2,anio2);
	}
	else
		return 0;
}


