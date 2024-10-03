#include<stdio.h>
#define MAX 30

typedef char tCadena[MAX];

void leeCad(tCadena, int);

int main() {
    tCadena cadena;
    leeCad(cadena,11);
    printf("La cadena ingresada es: %s\n", cadena);
    return 0;
}
/*

El primer bucle guardará Hola Mun en cadena,
y el resto (do) será descartado por el segundo bucle.
La cadena resultante será "Hola Mun".
*/

/* CONSULTAR USO DE fgets() en lugar de getchar()()
*/



void leeCad (tCadena cad, int tam) {
    int j;
    char c;

    j = 0; /* Se comienza la lectura de caracteres del Buffer */
    c = getchar();  /* Se lee el primer carácter de la entrada estándar (teclado) */


    /* 
    Inicia un bucle while que se ejecuta mientras:
    - No se encuentre el fin de archivo (EOF)
    - No se haya encontrado el carácter de nueva línea ('\n')
    - No se haya alcanzado el límite de la cadena (tam-1)
    */
    while (c != EOF && c != '\n' && j < tam - 1) {
        cad[j] = c;  /* Almacena el carácter leído en la posición j de la cadena cad */
        j++;         /* Incrementa el índice de la cadena */
        c = getchar();  /* Lee el siguiente carácter de la entrada */
    }

    cad[j] = '\0';  /* Agrega el carácter nulo '\0' para terminar la cadena correctamente */

    /* 
    Un segundo bucle while que vacía el buffer si quedó algo por leer:
    - Este bucle se ejecuta si el buffer de entrada tiene más caracteres
      (por ejemplo, si el usuario ingresó más de tam-1 caracteres o si
      hay caracteres después del salto de línea).
    - Se ejecuta hasta que se encuentra el fin de archivo (EOF) o un salto de línea ('\n').
    */
    while (c != EOF && c != '\n') {
        c = getchar();  /* Lee y descarta cualquier carácter que quede en el buffer */
    }
}



/*
Problema con scanf():
    scanf() por defecto separa las palabras 
    ingresadas cuando encuentra espacios. 

    Al ingresar "Casa Blanca", 
    scanf() solo leerá "Casa" y dejará fuera "Blanca". 
    Esto es una limitación de cómo funciona scanf().
    
    scanf("%5s", Pal) permite limitar la cantidad
    de caracteres que se leen, 
    pero en este caso, no previene el problema del espacio en las cadenas.
*/


/*
Problema con gets():

    Aunque gets() lee una línea completa,
    no tiene control sobre el límite de la longitud de la cadena,
    lo que puede provocar un desbordamiento de búfer si la entrada es mayor a la cantidad de caracteres definidos para una cadena.
    Esto puede corromper la memoria o causar un comportamiento 
    inesperado en el programa, lo que hace que gets() sea inseguro.
    De hecho,en versiones modernas de C,
     gets() ha sido desaprobado y se recomienda no usarlo
*/