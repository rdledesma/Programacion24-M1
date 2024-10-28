#include <stdio.h>

/*
Dado dos numeros naturales, a y b,sumarlos 
de manera recursiva
*/

int sumaRecursiva(int, int);

int main(){
    int a,b;
    a = 2;
    b = 3;
    printf("\nSuma recursiva entre %d y %d es %d",a,b, sumaRecursiva(a,b));
    printf("\n");
}

int sumaRecursiva(int a, int b){
    if(b==0){
        return a;
    }
    else
        return sumaRecursiva(a+1, b-1);

}
