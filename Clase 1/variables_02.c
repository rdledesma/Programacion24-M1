#include <stdio.h>

// Variable global
int globalVar = 10;

void function1() {
    // Variable local a function1
    int localVar1 = 20;

    printf("En function1 - globalVar: %d\n", globalVar);
    printf("En function1 - localVar1: %d\n", localVar1);

    // Modificar la variable global
    globalVar = 15;
}

void function2() {
    // Variable local a function2
    int localVar2 = 30;

    printf("En function2 - globalVar: %d\n", globalVar);
    printf("En function2 - localVar2: %d\n", localVar2);
}

int main() {
    // Variable local a main
    int localVarMain = 5;

    printf("En main - globalVar: %d\n", globalVar);
    printf("En main - localVarMain: %d\n", localVarMain);

    // Llamada a function1
    function1();

    // Llamada a function2
    function2();

    // Accediendo a las variables locales de main nuevamente
    printf("En main después de function1 - globalVar: %d\n", globalVar);
    printf("En main después de function1 - localVarMain: %d\n", localVarMain);

    // Intentar acceder a localVar1 y localVar2 aquí resultaría en un error si descomentas las siguientes líneas:
    // printf("%d\n", localVar1); // Error: localVar1 no está definida en main
    // printf("%d\n", localVar2); // Error: localVar2 no está definida en main

    return 0;
}
