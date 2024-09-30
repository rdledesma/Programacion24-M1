#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Cadena de origen";
    char dest[20];  // Aseguramos que el tamaño sea suficiente

    // Usamos strcpy() para copiar la cadena src en dest
    strcpy(dest, src);

    printf("Cadena copiada: %s\n", dest);

    return 0;
}
