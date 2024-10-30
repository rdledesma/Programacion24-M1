#include <stdio.h>
typedef int Tlista[50];
void carga_lista(Tlista, int);
void muestra_lista(Tlista, int);
void m_sort(Tlista, int, int);

int main(void) {
	Tlista x; 
	int tam;
	printf("Ingrese tam de lista "); 
	scanf("%d",&tam);
	carga_lista(x,tam);
	m_sort(x,1,tam);
	
	muestra_lista(x,tam);

	return 0;
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


void mezcla(Tlista l,int ini, int m, int fin)
{
	int aux[20]; int i,j,k,t;
	k=0;
	i=ini;
	j=m+1;
	while (i<=m && j<=fin){
		k++;
		if (l[i]<l[j]){
			aux[k]=l[i];
			i++;
		}
		else{
			aux[k]=l[j];
			j++;
		}
	}
	for(t=i;t<=m;t++){
		k++;
		aux[k]=l[t];
	}
	for(t=j;t<=fin;t++){
		k++;
		aux[k]=l[t];
	}
	for(t=1;t<=k;t++)
		l[ini+t-1]=aux[t];
}


void m_sort(Tlista l, int ini, int fin)
{
	int m;
	m=(ini+fin)/2;
	if (ini<fin){
		m_sort(l,ini,m);
		m_sort(l,m+1,fin);
		mezcla(l,ini,m,fin);
	}
}
