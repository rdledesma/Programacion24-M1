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
TPtr crearNodo();

void agregarCabecera(TPtr*);
//void agregarFin(TPtr*, int);
void muestraLista(TPtr);
void aniadirEnPosicionP(TPtr*, int, int);
void eliminarEnPosicionP(TPtr*, int);
void ordenarPorInsercion(TPtr*);
void insertarOrdenado(TPtr*, TPtr);


int main() {
    srand(time(NULL)); 
    TPtr lista;

    lista = crearLista();



    
    printf("Lista inicial:\n");
    muestraLista(lista);


    agregarCabecera(&lista);
    agregarCabecera(&lista);
    printf("Lista con dos:\n");
    muestraLista(lista);


    printf("Lista con dos:\n");
    ordenarPorInsercion(&lista);
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

TPtr crearNodo(){
    TPtr nuevo = (TPtr)malloc(sizeof(TNodo));
    nuevo->dato = generaUno();
    nuevo->sig = NULL;
    return nuevo;
}



// Función para agregar un elemento al inicio de la lista
void agregarCabecera(TPtr* lista) {

    TPtr nuevo;
    nuevo = crearNodo();
    nuevo->sig = *lista;
    *lista = nuevo;
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

    printf("\n\n");
}




// Función para añadir un valor en una posición específica (posición P)
void aniadirEnPosicionP(TPtr* lista, int valor, int posicion) {
    TPtr actual ;

    TPtr nuevo = (TPtr)malloc(sizeof(TNodo));
    nuevo->dato = valor;

    if (posicion == 1) {
        nuevo->sig = *lista;
        *lista = nuevo;
    } else {
        actual = *lista;
        for (int i = 1; i < posicion - 1 && actual != NULL; i++) {
            actual = actual->sig;
        }
        if (actual != NULL) {
            nuevo->sig = actual->sig;
            actual->sig = nuevo;
        } else {
            printf("Posición fuera de rango.\n");
            free(nuevo);
            nuevo = NULL;
        }
    }
}





// Función para eliminar un elemento en una posición específica (posición P)
void eliminarEnPosicionP(TPtr* lista, int posicion) {
    TPtr actual = *lista, anterior = NULL;
    int i;
    if (*lista != NULL) {
        if (posicion == 1) {
            *lista = actual->sig;
            free(actual);
        } 
        else {
            for (i = 1; i < posicion && actual != NULL; i++) {
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
    else
        printf("\n La lista esta vacia\n");

    
    

    
}



// Ordenar la lista enlazada usando ordenamiento por inserción
void ordenarPorInsercion(TPtr* lista) {
    TPtr actual, siguiente;
    TPtr listaOrdenada;

    listaOrdenada = crearLista(); 


    
    if (*lista != NULL && (*lista)->sig != NULL) {

        actual = *lista; // Empezamos desde el primer nodo de la lista original
        while (actual != NULL) {
            siguiente = actual->sig; // Guardamos el siguiente nodo
            insertarOrdenado(&listaOrdenada, actual); // Insertamos el nodo actual en la lista ordenada
            actual = siguiente; // Avanzamos al siguiente nodo en la lista original
        }

        *lista = listaOrdenada; // Actualizamos la lista original con la lista ordenada    
        
    }
    

    
}

// Función auxiliar para insertar un nodo en la lista ordenada en su posición correcta
void insertarOrdenado(TPtr* listaOrdenada, TPtr nuevoNodo) {
    TPtr actual;


    if (*listaOrdenada == NULL || (*listaOrdenada)->dato >= nuevoNodo->dato) {
        // Insertar al principio si la lista ordenada está vacía o el primer nodo es mayor o igual al nuevo nodo
        nuevoNodo->sig = *listaOrdenada;
        *listaOrdenada = nuevoNodo;
    } else {
        // Buscar la posición correcta en la lista ordenada
        actual = *listaOrdenada;
        while (actual->sig != NULL && actual->sig->dato < nuevoNodo->dato) {
            actual = actual->sig;
        }
        // Insertar el nuevo nodo en su posición
        nuevoNodo->sig = actual->sig;
        actual->sig = nuevoNodo;
    }
}
