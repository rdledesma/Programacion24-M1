#include <stdio.h>

int main() {
    const int MAX_EDAD = 100; // Declaración de una constante

    printf("La edad máxima permitida es: %d\n", MAX_EDAD);

    // Intentar modificar la constante resultará en un error
    // MAX_EDAD = 110; // Esto provocará un error de compilación

    return 0;
}

/*
Comment:
MAX_EDAD es una constante y se declara usando la palabra clave const.
Intentar modificar MAX_EDAD después de su declaración 
(como en el comentario) provocará un error de compilación, 
ya que una constante no puede cambiar su valor.

*/