#include <stdio.h>
typedef int Tlista[50];
void carga_lista(Tlista, int);
void muestra_lista(Tlista, int);
void carga_fin(Tlista, int);
void muestra_fin(Tlista, int);
void q_sort(Tlista, int, int);

int main(void) {
	int x[20]; 
	int tam;
	printf("Ingrese tam de lista "); 
	scanf("%d",&tam);
	carga_lista(x,tam);
	q_sort(x,1,tam);
	
	muestra_lista(x,tam);

/*	carga_fin(x,tam);
	muestra_fin(x,tam);
*/	return 0;
}

void carga_lista(Tlista l, int n)
{
	if (n>1)
		carga_lista(l,n-1);
	printf("\n ingrese valor posicion %d ",n);
	scanf("%d",&l[n]);
}

void muestra_lista(Tlista l, int n)
{
	if (n>1)
		muestra_lista(l,n-1);
	printf("\t lista[%d] %d",n,l[n]);
}

void carga_fin(Tlista l, int n)
{
	printf("\n ingrese valor posicion %d ",n);
	scanf("%d",&l[n]);
	if (n>1)
		carga_fin(l,n-1);

}

void muestra_fin(Tlista l, int n)
{
	printf("\t lista[%d] %d",n,l[n]);
	if (n>1)
		muestra_fin(l,n-1);

}

void q_sort(Tlista l, int ini, int fin)
{
	int piv, izq, der, med;
	
	if (ini<fin){
		piv=l[ini];
		izq=ini;
		der=fin;
		while (der>izq){
			while (der>izq && l[der]>piv)
				der--;
			if (der>izq){
				l[izq]=l[der];
				izq++;
			}
			while (der>izq && l[izq]<piv)
				izq++;
			if (der>izq){
				l[der]=l[izq];
				der--;
			}
		}
		l[izq]=piv;
		med=izq;
		q_sort(l,ini,med-1);
		q_sort(l,med+1,fin);
	}
}