#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hola Mundo";
    char *ptr;

    // Usamos strchr() para buscar el carácter 'M'
    ptr = strchr(str, 'M');

    if (ptr != NULL) {
        printf("El carácter 'M' se encuentra en la posición: %ld\n", ptr - str);
    } else {
        printf("El carácter 'M' no se encuentra en la cadena.\n");
    }

    return 0;
}
