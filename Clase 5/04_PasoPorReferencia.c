#include <stdio.h>


//En C, las funciones normalmente reciben una copia de los parámetros que les pasas.
// Si quieres que una función pueda modificar directamente el valor de una variable 
//fuera de la función, debes pasar la dirección de esa variable, es decir,
// usar un puntero.

//Cuando pasamos un puntero a una función, estamos pasando por referencia, 
//permitiendo que la función modifique la variable original. 
//Sin el uso de punteros, cualquier cambio que se realice dentro 
//de la función no afectaría a las variables fuera de ella.


//El operador & (llamado operador Dirección de) 
//se utiliza para obtener la dirección de memoria de una variable. 
//Si quieres saber dónde está guardada una variable en memoria, 
//puedes usar & antes del nombre de la variable.

//El operador * se utiliza para acceder al valor almacenado 
//en la dirección de memoria a la que apunta el puntero. 
//A esto se le llama desreferenciar el puntero.

int main() {
    int x = 5;    
    int *ptr = &x;    // &x devuelve la dirección de memoria de x. Esa dirección es lo que se guarda en ptr.
    printf("%d\n", *ptr);  // Imprime 5, el valor de x

}
