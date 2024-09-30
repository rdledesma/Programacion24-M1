#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hola Mundo";
    
    // Usamos strlen() para obtener la longitud de la cadena
    size_t len = strlen(str);

    printf("La longitud de la cadena '%s' es: %zu\n", str, len);

    return 0;
}
