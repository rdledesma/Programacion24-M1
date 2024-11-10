#include "TAD_cadena.h"
void leecadRec(Tcad,int,int);
void cargaCad(Tcad);
int compCadena(Tcad,Tcad);
void LimpiaBufferRec(char c){
	if(c!=EOF&&c!='\n'){
		c=getchar();
		LimpiaBufferRec(c);
	}
}
void leecad(Tcad A,int N){
	leecadRec(A,N,0);
}
void leecadRec(Tcad A,int N,int j){
	char c;
	c=getchar();
	if(c != EOF && c!='\n' && j < N){
		A[j] = c;
		leecadRec(A,N,j+1);
	}
	else{
		A[j]='\0';
		LimpiaBufferRec(c);
	}
}
void cargaCad(Tcad A){
	fflush(stdin);
	leecad(A,max);
}
int compCadena(Tcad A,Tcad B){
	return strcmp(A,B);
}
