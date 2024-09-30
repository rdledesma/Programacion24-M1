#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hola";
    char str2[] = " Mundo";

    // Usamos strcat() para concatenar str2 al final de str1
    strcat(str1, str2);

    printf("Cadena concatenada: %s\n", str1);

    return 0;
}
