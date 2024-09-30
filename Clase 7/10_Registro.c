#include <stdio.h>

#define TM 20

// Definimos la estructura para fechas
typedef struct {
    int Dia, Mes, Anio;
} tregFecha;

// Prototipos de funciones
void leerFecha(tregFecha *fecha);
void mostrarFecha(tregFecha fecha);
int esFechaValida(tregFecha fecha);
int esAnioBisiesto(int anio);

int main() {
    tregFecha fecha;

    // Leer la fecha desde el teclado
    leerFecha(&fecha);

    // Verificar si la fecha es válida
    if (esFechaValida(fecha)) {
        printf("La fecha ingresada es válida.\n");
        mostrarFecha(fecha);
    } else {
        printf("La fecha ingresada no es válida.\n");
    }

    return 0;
}

// Función para leer una fecha desde el teclado
void leerFecha(tregFecha *fecha) {
    printf("Ingrese una fecha (DD MM AAAA): ");
    scanf("%d %d %d", &fecha->Dia, &fecha->Mes, &fecha->Anio);
}

// Función para mostrar una fecha en formato DD/MM/AAAA
void mostrarFecha(tregFecha fecha) {
    printf("Fecha ingresada: %02d/%02d/%04d\n", fecha.Dia, fecha.Mes, fecha.Anio);
}

// Función para verificar si una fecha es válida
int esFechaValida(tregFecha fecha) {
    // Días máximos para cada mes (febrero tiene 28 días, o 29 si es bisiesto)
    int diasPorMes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Verificar el rango del mes
    if (fecha.Mes < 1 || fecha.Mes > 12) {
        return 0;  // Mes no válido
    }

    // Si es febrero, comprobar si es año bisiesto
    if (fecha.Mes == 2 && esAnioBisiesto(fecha.Anio)) {
        diasPorMes[2] = 29;  // Febrero tiene 29 días en un año bisiesto
    }

    // Verificar el rango del día
    if (fecha.Dia < 1 || fecha.Dia > diasPorMes[fecha.Mes]) {
        return 0;  // Día no válido
    }

    // Si todo es correcto, la fecha es válida
    return 1;
}

// Función para determinar si un año es bisiesto
int esAnioBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return 1;  // Es bisiesto
    }
    return 0;  // No es bisiesto
}



/*
typedef struct {
    TD1 campo1;
    . . .
    TDN campoN;
}TRegistro;
*/