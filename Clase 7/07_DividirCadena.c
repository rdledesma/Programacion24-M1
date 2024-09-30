#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hola,Mundo,En,Cadenas";
    char *token;

    // Usamos strtok() para dividir la cadena usando ',' como delimitador
    token = strtok(str, ",");

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
