#include <stdio.h>

typedef int TVec[10];
void CargarRecursivo(TVec, int);
void MostrarRecursivo(TVec, int);

void CargarRecursivo(TVec v, int n){
    if (n == 0){
        printf("\n Ingrese el elemento 0 ");
        scanf("%d", &v[0]);
    }
    else{
        CargarRecursivo(v, (n-1));

        printf("\n Ingrese el elemento %d ",n);
        scanf("%d", &v[n]);
    }
}







int main(){
    int i,k;
    TVec list;

    k = 4;
    CargarRecursivo(list, k);

    printf("[");
    for(i=0; i<=k; i++ ){
        printf(" %d",list[i]);
    }
    printf("]");

    return 0;
}