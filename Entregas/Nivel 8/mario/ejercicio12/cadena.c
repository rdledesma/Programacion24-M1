#include "cadena.h"
#include <string.h>

void Leecad(Tcad cad){
	LeecadR(cad,50,0);
	fflush(stdin);
}
void LeecadR(Tcad cad,int tam,int j){
	char c;
	if(j>=tam-1)
		cad[j]='\0';
	else{
		c=getchar();
		if(c==EOF || c=='\n')
			cad[j]='\n';
		else{
			cad[j]=c;
			LeecadR(cad,tam,j+1);
		}
	}
}
	int compara_cadena(Tcad cad1, Tcad cad2){
		if (strcmp(cad1, cad2)==1) return 1; /*cad1 > cad2*/
		else if (strcmp(cad1, cad2)==0) return 0; /*cad1 = cad2*/
		else return -1; /*cad1 < cad2*/
	}
