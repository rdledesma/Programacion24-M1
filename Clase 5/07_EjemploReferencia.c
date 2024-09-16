#include <stdio.h>

void intercambiar(int *a, int *b);

/*
Llamada a la función: Cuando llamamos a intercambiar(&x, &y), 
estamos pasando las direcciones de memoria de x e y (no los valores).
&x es la dirección de memoria de x.
&y es la dirección de memoria de y.
*/

/*

Uso de punteros en la función: 
Dentro de la función intercambiar,
los parámetros *a y *b son punteros que apuntan a x e y respectivamente.
*a accede al valor de x y *b accede al valor de y.
*/

/*
ntercambio: Al intercambiar *a y *b, 
estamos cambiando directamente los valores de x e y 
a través de los punteros, lo que afecta a 
las variables originales.
*/


/*
Usamos punteros para:

    Modificar variables fuera de una función: Si quieres que 
    una función modifique una variable global o una 
    variable local de otra función,
    debes pasar la dirección de la variable con & y 
    usar punteros dentro de la función para manipularla.
    
    Trabajar con grandes cantidades de datos de manera eficiente:
    Si pasas grandes estructuras o arrays a una función, 
    es más eficiente pasar un puntero que hacer una copia entera de los datos.
*/



int main() {
    int x = 5, y = 10;
    printf("Antes de intercambiar: x = %d, y = %d\n", x, y);

    intercambiar(&x, &y);  // Pasamos la dirección de x y y

    printf("Después de intercambiar: x = %d, y = %d\n", x, y);
    return 0;
}


void intercambiar(int *a, int *b) {
    int temp = *a;  // temp guarda el valor de 'a' (el valor al que apunta 'a')
    *a = *b;  // Ahora 'a' tiene el valor de 'b'
    *b = temp;  // 'b' tiene el valor original de 'a'
}