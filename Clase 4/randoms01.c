#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Inicializa la semilla con el valor del tiempo actual

    /*
    srand(time(NULL)); se utiliza para inicializar la 
    semilla del generador de números aleatorios en C, de manera que los 
    números generados por la función rand() sean diferentes cada vez que ejecutes el programa
    */

    /*
    La función srand() establece la semilla
     para la generación de números aleatorios. La semilla es un valor inicial que 
    determina cómo la secuencia de números
     pseudoaleatorios será generada por la función rand().
    */
    /*
    Si no llamas a srand(), la secuencia de números 
    generada por rand() será siempre la misma cada vez que ejecutes el programa,
     ya que rand() comenzará con una semilla predeterminada.
    */


    /*
    
    La función time() está definida en la biblioteca <time.h>. 
    Cuando llamas a time(NULL), esta función devuelve el número de segundos transcurridos 
    desde el 1 de enero de 1970 (lo que se conoce como el "Unix epoch").*/

    /*
    Pasando NULL como argumento le indica que no queremos almacenar 
    el valor de tiempo en una estructura de tiempo especial,
     solo queremos el número de segundos.
    */

    /*
    Al pasar el valor de time(NULL) como argumento a srand(),
     usamos el tiempo actual (en segundos) como la semilla del generador de números aleatorios.
    Esto hace que cada vez que ejecutes el programa en un momento distinto, 
    la semilla sea diferente, lo que genera una secuencia distinta de números aleatorios.
    */
    // Genera y muestra 5 números aleatorios
    for(int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }


    /*
    Si no inicializas el generador de números aleatorios con srand(), 
    obtendrás siempre la misma secuencia de números cada vez que ejecutes el programa.
    Al usar el tiempo como semilla (mediante srand(time(NULL))), 
    te aseguras de que los números aleatorios sean diferentes en cada ejecución,
     ya que el tiempo actual cambia constantemente.
    
    */


    return 0;
}
