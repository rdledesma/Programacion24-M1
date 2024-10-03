#include <stdio.h>
#include <string.h>

#define MAX 300  // Tamaño máximo de la cadena para la frase

typedef char tcadena[MAX];  // Definimos el tipo tcadena

// Función para contar las palabras en la frase y encontrar la palabra más larga
void procesarFrase(tcadena frase, tcadena palabraMasLarga, int* cantidadPalabras) {

    int maxLen = 0;
    *cantidadPalabras = 0;
    // Variables temporales para procesar las palabras
    tcadena palabraActual = "";
    int lenActual = 0;
    // Recorremos la frase caracter por caracter
    for (int i = 0; i <= strlen(frase); i++) {
        // Si es un espacio o fin de la cadena, tratamos la palabra
        if (frase[i] == ' ' || frase[i] == '\0') {
            if (lenActual > 0) {  // Hay una palabra para procesar
                palabraActual[lenActual] = '\0';  // Finalizamos la palabra actual
                (*cantidadPalabras)++;  // Contamos una nueva palabra
                
                // Verificamos si esta palabra es la más larga hasta el momento
                if (lenActual > maxLen) {
                    maxLen = lenActual;
                    strcpy(palabraMasLarga, palabraActual);  // Guardamos la palabra más larga
                }
                lenActual = 0;  // Reiniciamos la longitud para la siguiente palabra
            }
        } else {
            // Continuamos formando la palabra actual
            palabraActual[lenActual] = frase[i];
            lenActual++;
        }
    }
}



int main() {
    tcadena frase;
    tcadena palabraMasLarga;
    int cantidadPalabras;

    // Pedimos al usuario que ingrese una frase
    printf("Ingrese una frase: ");
    fgets(frase, MAX, stdin);  // Usamos fgets para leer la frase (incluyendo espacios)
    frase[strcspn(frase, "\n")] = '\0';  // Eliminamos el salto de línea al final si existe

    // Llamamos a la función para procesar la frase
    procesarFrase(frase, palabraMasLarga, &cantidadPalabras);
    
    // Mostramos los resultados
    printf("La palabra más larga es: '%s'\n", palabraMasLarga);
    printf("La frase tiene %d palabras.\n", cantidadPalabras);

    return 0;
}
