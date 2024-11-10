#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} TNodo;

typedef TNodo* TPtr;

// Prototipos de funciones
TPtr crearLista();
void cargarLista(TPtr*, int);
void agregarCabecera(TPtr*, int);
void agregarFin(TPtr*, int);
void muestraLista(TPtr);
void añadirEnPosicionP(TPtr*, int, int);
void eliminarPares(TPtr*);
void añadirCerosPrimos(TPtr*);
void eliminarEnPosicionP(TPtr*, int);
bool esPrimo(int);

int main() {
    srand(time(NULL)); 
    TPtr lista = crearLista();

    int n = 30;
    cargarLista(&lista, n);

    printf("Lista inicial:\n");
    muestraLista(lista);

    agregarCabecera(&lista, 1);
    printf("\nLista después de agregar 1 al inicio:\n");
    muestraLista(lista);

    agregarFin(&lista, 20);
    printf("\nLista después de agregar 20 al final:\n");
    muestraLista(lista);

    añadirEnPosicionP(&lista, 9, 3);
    printf("\nLista después de añadir 9 en la posición 3:\n");
    muestraLista(lista);

    eliminarPares(&lista);
    printf("\nLista después de eliminar los elementos pares:\n");
    muestraLista(lista);

    añadirCerosPrimos(&lista);
    printf("\nLista después de añadir ceros alrededor de los números primos:\n");
    muestraLista(lista);

    eliminarEnPosicionP(&lista, 2);
    printf("\nLista después de eliminar el elemento en la posición 2:\n");
    muestraLista(lista);

    return 0;
}

// Función para crear una lista vacía
TPtr crearLista() {
    return NULL;
}

int generaUno(){
    // Generar un número aleatorio 
    // entre min y max
    int min, max;
    min = 1;
    max = 100;
    return (rand() % (max - min + 1)) + min;  
}

// Función para cargar una lista inicial con un arreglo de valores
void cargarLista(TPtr* lista, int n) {
    for (int i = 0; i < n; i++) {
        agregarFin(lista, generaUno());
    }
}

// Función para agregar un elemento al inicio de la lista
void agregarCabecera(TPtr* lista, int valor) {
    TPtr nuevo = (TPtr)malloc(sizeof(TNodo));
    nuevo->dato = valor;
    nuevo->sig = *lista;
    *lista = nuevo; //*lista es el primer nodo de la lista
                    //lista es un puntero no es el nodo
}

// Función para agregar un elemento al final de la lista
void agregarFin(TPtr* lista, int valor) {
    TPtr nuevo = (TPtr)malloc(sizeof(TNodo));
    nuevo->dato = valor;
    nuevo->sig = NULL;

    if (*lista == NULL) {
        *lista = nuevo;
    } else {
        TPtr actual = *lista;
        while (actual->sig != NULL) {
            actual = actual->sig;
        }
        actual->sig = nuevo;
    }
}

// Función para mostrar la lista
void muestraLista(TPtr lista) {
    if (lista == NULL) {
        printf("La lista está vacía.\n");
    } else {
        TPtr actual = lista;
        while (actual != NULL) {
            printf("%d -> ", actual->dato);
            actual = actual->sig;
        }
       //printf("NULL\n");
    }
}

// Función para añadir un valor en una posición específica (posición P)
void añadirEnPosicionP(TPtr* lista, int valor, int posicion) {
    TPtr nuevo = (TPtr)malloc(sizeof(TNodo));
    nuevo->dato = valor;

    if (posicion == 1) {
        nuevo->sig = *lista;
        *lista = nuevo;
    } else {
        TPtr actual = *lista;
        for (int i = 1; i < posicion - 1 && actual != NULL; i++) {
            actual = actual->sig;
        }
        if (actual != NULL) {
            nuevo->sig = actual->sig;
            actual->sig = nuevo;
        } else {
            printf("Posición fuera de rango.\n");
            free(nuevo);
        }
    }
}

// Función para eliminar todos los elementos pares de la lista
void eliminarPares(TPtr* lista) {
    TPtr actual = *lista, anterior = NULL;
    while (actual != NULL) {
        if (actual->dato % 2 == 0) {
            TPtr temp = actual;
            if (anterior == NULL) {
                *lista = actual->sig;
            } else {
                anterior->sig = actual->sig;
            }
            actual = actual->sig;
            free(temp);
        } else {
            anterior = actual;
            actual = actual->sig;
        }
    }
}

// Función para añadir ceros alrededor de números primos
void añadirCerosPrimos(TPtr* lista) {
    TPtr actual = *lista;
    while (actual != NULL) {
        if (esPrimo(actual->dato)) {
            // Insertar un 0 antes del número primo
            TPtr nuevoAntes = (TPtr)malloc(sizeof(TNodo));
            nuevoAntes->dato = 0;
            nuevoAntes->sig = actual;
            if (actual == *lista) {
                *lista = nuevoAntes;
            } else {
                TPtr temp = *lista;
                while (temp->sig != actual) {
                    temp = temp->sig;
                }
                temp->sig = nuevoAntes;
            }
            
            // Insertar un 0 después del número primo
            TPtr nuevoDespues = (TPtr)malloc(sizeof(TNodo));
            nuevoDespues->dato = 0;
            nuevoDespues->sig = actual->sig;
            actual->sig = nuevoDespues;
            
            actual = nuevoDespues->sig;  // Avanzar al siguiente nodo después del nuevo 0
        } else {
            actual = actual->sig;
        }
    }
}

// Función para eliminar un elemento en una posición específica (posición P)
void eliminarEnPosicionP(TPtr* lista, int posicion) {
    if (*lista == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    
    TPtr actual = *lista, anterior = NULL;

    if (posicion == 1) {
        *lista = actual->sig;
        free(actual);
    } else {
        for (int i = 1; i < posicion && actual != NULL; i++) {
            anterior = actual;
            actual = actual->sig;
        }
        if (actual != NULL) {
            anterior->sig = actual->sig;
            free(actual);
        } else {
            printf("Posición fuera de rango.\n");
        }
    }
}

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) return false;  // Los números menores o iguales a 1 no son primos
    if (numero == 2 || numero == 3) return true;  // 2 y 3 son primos
    if (numero % 2 == 0 || numero % 3 == 0) return false;  // Eliminar múltiplos de 2 y 3

    // Solo verificar divisores desde 5 hasta la raíz cuadrada de 'numero'
    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) {
            return false;  // Si es divisible por i o i + 2, no es primo
        }
    }
    
    return true;  // Si no se encuentra ningún divisor, es primo
}