#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hola";
    char str2[] = "Mundo";
    char str3[] = "Hola";

    // Comparando dos cadenas diferentes
    if (strcmp(str1, str2) == 0) {
        printf("Las cadenas '%s' y '%s' son iguales.\n", str1, str2);
    } else {
        printf("Las cadenas '%s' y '%s' son diferentes.\n", str1, str2);
    }

    // Comparando dos cadenas iguales
    if (strcmp(str1, str3) == 0) {
        printf("Las cadenas '%s' y '%s' son iguales.\n", str1, str3);
    }

    return 0;
}
