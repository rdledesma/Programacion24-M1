#include <stdio.h>

/*
En C, una variable es un nombre simbólico
 para un área de memoria que puede almacenar un
 valor que puede cambiar durante la ejecución de un programa.
 Las variables son fundamentales en cualquier lenguaje de programación,
ya que permiten almacenar, manipular y recuperar datos.

*/


int main() {
    int edad;
    /*Declaración:
    Antes de usar una variable, 
    debes declararla, 
    lo que le dice al compilador qué tipo de datos 
    almacenará la variable y 
    le reserva un espacio en la memoria.
    */

    edad = 25;
    /*Asignación:
     Después de declarar una variable, 
     puedes asignarle un valor.*/
    
    int edad = 25;
    /*
    Inicialización con asignación o Inicialización:
    Puedes declarar y asignar un valor a la variable 
    en una sola línea.*/


    /*
    
    Las variables son esenciales en C para almacenar y manipular datos.
    Deben ser declaradas antes de ser usadas, especificando su tipo de dato.
    El tipo de dato define qué tipo de valor puede almacenar la variable (entero, decimal, carácter, etc.).
    Las variables pueden tener un alcance local o global dependiendo de dónde se declaren en el código.
    
    */


    int numero = 10; //int: Enteros (números enteros).
    float precio = 19.99; //float: Números de punto flotante (decimales).
    char letra = 'A'; //char: Caracteres individuales.
    double pi = 3.14159; //double: Números de punto flotante de doble precisión (más precisión que float).


    int edad = 30;         // Declarar e inicializar una variable entera
    float altura = 1.75;   // Declarar e inicializar una variable de punto flotante
    char inicial = 'J';    // Declarar e inicializar una variable de carácter





    printf("Edad: %d años\n", edad);
    printf("Altura: %.2f metros\n", altura);
    printf("Inicial del nombre: %c\n", inicial);

    return 0;
}