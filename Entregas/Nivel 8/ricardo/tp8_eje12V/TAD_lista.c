#include "TAD_lista.h"
void cargaVecRec(T_lis A,int N){
	if(N>0){
		cargaVecRec(A,N-1);
		A[N]=cargaR();
	}
}
void M_listaRec(T_lis A,int N){
	if(N>0){
		M_listaRec(A,N-1);
		mostraR(A[N]);
	}
}
void listaPacienteRec(T_lis A,int N,T_lis B,int M,int atc,fecha F,int*tam){
	if(N>0){
                                                    //viola encapsulamiento
		if(compAtencion(A[N],atc)==1&&compFecha(A[N].fatencion,F)==0){
			M++;
			B[M]=A[N];
		}
		listaPacienteRec(A,N-1,B,M,atc,F,tam);
	}
	else
	   *tam=M;
}
int contPacienteRec(T_lis A,int N,fecha x, fecha y){
	if(N>0){
                                                        //viola encapsulamiento
		if(compFecha(A[N].fatencion,x)==1 && compFecha(y,A[N].fatencion)==1)
			return 1+contPacienteRec(A,N-1,x,y);
		else
		contPacienteRec(A,N-1,x,y);
	}
	else
	   return 0;
}
lista cargaLista(){
	lista aux;
	printf("\ningrese la cantidad de pacientes:");
	scanf("%d",&aux.tam);
	cargaVecRec(aux.L_paciiente,aux.tam);
	return aux;
}
void muestraLista(lista A){
	M_listaRec(A.L_paciiente,A.tam);
}
void q_sort(T_lis A,int ini,int fin){
	int izq,der,med; 
	if(ini<fin){
		paciente piv;
		izq=ini;
		der=fin;
		piv=A[ini];
		while(izq<der){
			while(izq<der && comparaApellidos(A[der],piv)==1)
				der--;
			if(izq<der){
				A[izq]=A[der];
				izq++;
			}
			while(izq<der && comparaApellidos(piv,A[izq])==1)
			   izq++;
			if(izq<der){
				A[der]=A[izq];
				der--;
			}
		}
		A[der]=piv;
		med=der;
		q_sort(A,ini,med-1);
		q_sort(A,med+1,fin);
	}
}
lista atencion_fecha(lista A){
	lista B;
	int atc,M;
	fecha F;
	printf("\ningrese atencion ([1]clinica,[2] odontologia, [3] traumatologia) :");
	scanf("%d",&atc);
	printf("\n ingrese la fecha que desea ver:");
	F=cargaF();
	listaPacienteRec(A.L_paciiente,A.tam,B.L_paciiente,0,atc,F,&M);
	B.tam=M;
	q_sort(B.L_paciiente,1,B.tam);
	return B;
}
void CantPac(lista A){
	int c;
	fecha x,y;
	printf("\ningrese la primera fecha:");
	x=cargaF();
	printf("\ningrese la segunda fecha:");
	y=cargaF();
	c=contPacienteRec(A.L_paciiente,A.tam,x,y);
	printf("\n la cantidad de pacientes atendidos entre las fechas son :%d",c);
}
