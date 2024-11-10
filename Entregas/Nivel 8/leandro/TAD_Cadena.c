#include "TAD_Cadena.h"
#include <string.h>
#include <stdio.h>

void limpia(char c){
	if ((c!='\n')&&(c!=EOF)){
		c=getchar();
		limpia(c);
	}
}	
	
void leeCadrec(TCadena cad, int tam, int j){
	char c;
	c=getchar();
	if((c!=EOF)&&(c!='\n')&&(j<tam-1)){
		cad[j]=c;
		leeCadrec(cad,tam,j+1);
	}
	else {
		cad[j]='\0';
		limpia(c);}
}
	

void leeCad(TCadena cad, int tam){ /*Completar con proceso recursivo*/
	leeCadrec(cad,tam,0);
}
void cargar_cadena(TCadena cad){leeCad(cad,20);
}

int compara_cadena(TCadena cad1, TCadena cad2){
	if (strcmp(cad1, cad2)==1) return 1; /*cad1 > cad2*/
			else if (strcmp(cad1, cad2)==0) return 0; /*cad1 = cad2*/
						else return -1; /*cad1 < cad2*/
}
