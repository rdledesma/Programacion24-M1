#include "TAD_Lista.h"

TLista crearLista(){
    TLista l;
    int i;
    printf("\n Ingrese Tamaño: ");
    scanf("%d", &l.tam);
    scanf("%*c");

    for(i=1; i<=l.tam; i++){
        printf("\n Ingrese Nombre[%d]: ",i);
        leeCad(l.lista[i]);
    }

    return l;

}

void muestra_rec(TCadena L[], int n){
	if (n>0){
		muestra_rec(L,n-1);
		printf("%s, ", L[n]);
	}
}

void mostrar(TLista l){
    int i;
    printf("[ ");
    muestra_rec(l.lista, l.tam);
    printf(" ]");
}



void mezcla(TCadena l [],int ini, int m, int fin)
{
	
    TCadena aux[MAXList];

    int i,j,k,t;
	k=0;
	i=ini;
	j=m+1;
	while (i<=m && j<=fin){
		k++;
		if ( strcmp(l[i],l[j])<0){
			strcpy(aux[k],l[i]);
			i++;
		}
		else{
			strcpy(aux[k],l[j]);
			j++;
		}
	}
	for(t=i;t<=m;t++){
		k++;
		strcpy(aux[k],l[t]);
	}
	for(t=j;t<=fin;t++){
		k++;
		strcpy(aux[k],l[t]);
	}
	for(t=1;t<=k;t++)
		strcpy(l[ini+t-1],aux[t]);
}


void m_sort(TCadena * l, int ini, int fin)
{
	int m;
	m=(ini+fin)/2;
	if (ini<fin){
		m_sort(l,ini,m);
		m_sort(l,m+1,fin);
		mezcla(l,ini,m,fin);
	}
}


void ordenar(TLista l){
    m_sort(&l.lista, 1, l.tam);

    mostrar(l);

}