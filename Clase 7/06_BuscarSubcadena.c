#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Este es un ejemplo de cadena";
    char subcadena[] = "ejemplo";
    char *ptr;

    // Usamos strstr() para buscar la subcadena
    ptr = strstr(str, subcadena);

    if (ptr != NULL) {
        printf("La subcadena '%s' se encuentra en: %s\n", subcadena, ptr);
    } else {
        printf("La subcadena '%s' no se encuentra en la cadena.\n", subcadena);
    }

    return 0;
}
