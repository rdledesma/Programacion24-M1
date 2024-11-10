#include "TAD_Cadena.h"
#include <string.h>
#include <stdio.h>



void leeCadR(TCadena cad, int tam, int j){ /*Completar con proceso recursivo*/
	char c;
	if(j>= tam-1)
		cad[j]='\0';
	else{
		c=getchar();
		if(c==EOF && c=='\n'){
			cad[j]='\0';}
		else{
			cad[j]=c;
			leeCadR(cad,tam,j+1);
		}
	}
}
void leeCad	(TCadena cad, int tam){
	leeCadR(cad,tam,0);
}
void cargar_cadena(TCadena cad){
	leeCad(cad,20);
}
int compara_cadena(TCadena cad1, TCadena cad2){
	if (strcmp(cad1, cad2)==1) return 1; /*cad1 > cad2*/
			else if (strcmp(cad1, cad2)==0) return 0; /*cad1 = cad2*/
						else return -1; /*cad1 < cad2*/
}
