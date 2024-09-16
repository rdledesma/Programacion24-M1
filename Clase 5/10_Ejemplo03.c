/*
Un sistema de control climático ajusta 
la temperatura de una habitación en base a 
las preferencias del usuario. 
Los usuarios pueden aumentar o disminuir la temperatura
deseada en intervalos de un grado.
Si la temperatura solicitada excede los límites permitidos
(por ejemplo, entre 16°C y 30°C), 
el sistema debe alertar al usuario.

Requerimientos:
    Crear un procedimiento que permita aumentar la temperatura 
    (validando que no exceda el límite máximo).
    Crear un procedimiento que permita disminuir la temperatura 
    (validando que no baje del límite mínimo).
    Ambos procedimientos deben recibir como parámetro la temperatura actual, 
    y modificarla por referencia.
*/



#include <stdio.h>
#define LIMITE_MIN 16
#define LIMITE_MAX 30


// Procedimiento para aumentar la temperatura
void aumentarTemperatura(int *temp) {
    if (*temp < LIMITE_MAX) {
        (*temp)++;
        printf("Temperatura aumentada a %d°C\n", *temp);
    } else {
        printf("La temperatura no puede exceder los %d°C\n", LIMITE_MAX);
    }
}

// Procedimiento para disminuir la temperatura
void disminuirTemperatura(int *temp) {
    if (*temp > LIMITE_MIN) {
        (*temp)--;
        printf("Temperatura disminuida a %d°C\n", *temp);
    } else {
        printf("La temperatura no puede ser inferior a %d°C\n", LIMITE_MIN);
    }
}

int main() {
    int temperatura = 22;
    printf("Temperatura inicial: %d°C\n", temperatura);

    aumentarTemperatura(&temperatura);  // Aumentar 1°C
    disminuirTemperatura(&temperatura);  // Disminuir 1°C
    disminuirTemperatura(&temperatura);  // Disminuir nuevamente
    disminuirTemperatura(&temperatura);  // Otra vez

    return 0;
}



/*

En C, las directivas #define y la palabra clave const 
se utilizan para definir valores constantes, 
pero tienen diferencias importantes en su comportamiento y uso.


#define:
    Es una directiva de preprocesador,
    lo que significa que se procesa antes de la compilación del código.
    No tiene tipo: el preprocesador reemplaza todas las ocurrencias de
    LIMITE_MIN y LIMITE_MAX en el código por los valores 16 y 30
    respectivamente antes de que el compilador analice el código.
    No hay verificación de tipos, 
    lo que significa que si cometes un error al usar #define, 
    es más difícil de detectar.
    
    Puede ser utilizado para definir tanto constantes como macros que pueden realizar operaciones.

    No tiene información de tipo, por lo que no se hace verificación de tipo.
    El uso de #define en macros puede ser propenso a errores si no se manejan 
    correctamente los paréntesis o los tipos.

const:
    Es una palabra clave que define una variable constante, lo que significa que se declara como un objeto de tipo específico que no puede cambiar su valor después de la inicialización.
    Tiene tipo, lo que le permite al compilador realizar verificaciones de tipo y ayudar a evitar errores.
    Se almacena en memoria, lo que significa que ocupa espacio y es evaluado en tiempo de ejecución (aunque, en algunos casos, el compilador puede optimizarlo).
    Ejemplo:

    Las constantes definidas con const tienen tipo, lo que significa que el compilador puede hacer verificaciones para asegurarse de que se usan correctamente.
    Se pueden usar en el depurador para rastrear el valor durante la ejecución.
    En muchos casos, el compilador puede optimizar el código para que estas constantes no ocupen espacio en tiempo de ejecución.


    A diferencia de #define, ocupa memoria, ya que crea una variable en el código.

    Usa #define para definir valores constantes sencillos si no te importa
    la verificación de tipos o cuando quieres definir macros.
    Usa const si necesitas seguridad en los tipos y 
    preferirías que el compilador te ayude a detectar errores

*/