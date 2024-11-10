#include "TAD_fecha.h"
int compFecha(fecha A,fecha B);
fecha cargaF(){
	fecha aux;
	printf("\n ingrese dia:");
	scanf("%d",&aux.d);
	printf("\ningrese el mes:");
	scanf("%d",&aux.m);
	printf("\n ingrese el anio:");
	scanf("%d",&aux.a);
	return aux;
}
void muestraF(fecha A){
	printf("%d/%d/%d/",A.d,A.m,A.a);
}
int compFecha(fecha A,fecha B){
	int r;
	if(A.a==B.a && A.m==B.m && A.d==B.d)
		r=0;
	else if(A.a>=B.a){
		if(A.a>B.a)
			r=1;
		else if(A.m>=B.m){
			if(A.m>B.m)
				r=1;
			else if(A.d>B.d)
				r=1;
			else
				r=-1;
		}
		else
			r=-1;
	}
	else
		r=-1;
	return r;
}
