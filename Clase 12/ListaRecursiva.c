#include <stdio.h>
typedef int T_lista[20];
void ingresa(T_lista, int *);
void muestra_rec(T_lista, int);	
void elimina(T_lista, int, int*);
	
int main(void) {
	T_lista L;
	int n,p;
	ingresa(L,&n);
	muestra_rec(L, n);
	do
	{printf("\n Ingrese pos a eliminar");
	scanf("%d",&p);
	}while (p>n || p<1);
	elimina(L,p,&n);
	muestra_rec(L, n);
	return 0;
}

void ingresa_rec(T_lista L, int n){
if (n>0){
	ingresa_rec(L,n-1);
	printf("Ingrese elemento de posición %d ", n);
	scanf("%d",&L[n]);
}
}

void ingresa(T_lista L, int *n){
	printf("Ingrese tam: ");
	scanf("%d",n);
	ingresa_rec(L,*n);
}
void muestra_rec(T_lista L, int n){
	if (n>0){
		muestra_rec(L,n-1);
		printf("\nElemento de posición %d es %d ",n, L[n]);
	}
}

void corre_rec(T_lista L, int p, int n){
	if (p<n){
		L[p]=L[p+1];
		corre_rec(L, p+1, n);
	}
}

void elimina(T_lista L, int p, int* n){
	corre_rec(L,p,*n);
	*n=*n-1;
}