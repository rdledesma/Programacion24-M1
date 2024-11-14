#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} TNodo;

typedef TNodo* TPtr;

// Prototipos de funciones
//Funcion para crear un nodo
TPtr crearNodo();
TPtr crearCola();
void pushN(TPtr*, int);
void push(TPtr*, TPtr);
void mostrarCola(TPtr);
TPtr pop(TPtr*);
void mostrarNodo(TPtr);
int estaVacia(TPtr);


void Eliminar(TPtr*, int);

int main(){
    TPtr cola;    
    int Elementos;
    cola = crearCola();

    Elementos = 2;
    pushN(&cola, Elementos);
    mostrarCola(cola);

    //pop(&cola);
    //pop(&cola);

    Eliminar(&cola, 1);
    mostrarCola(cola);

    return 0;
}



// Función para crear una cola vacía (inicializar cola)
TPtr crearCola() {
    return NULL;
}

TPtr crearNodo(){

    TPtr nodo = (TPtr)malloc(sizeof(TNodo));
    printf("\nValor: ");
    scanf("%d", &nodo->dato);
    fflush(stdin);    
    nodo->sig = NULL;
    return nodo;

};

void push(TPtr* c, TPtr nuevo){
    TPtr aux;
    

    if(estaVacia(*c)){
        nuevo->sig = *c;
        *c = nuevo;
    }
    else{
        aux = *c;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

}

// Función para insertar n elementos en la pila
void pushN(TPtr* p, int n) {

    for (int i = 0; i < n; i++) {
        push(p, crearNodo());
    }
}

int estaVacia(TPtr p){
    return p == NULL;
}

void mostrarNodo(TPtr nodo){
    printf("%d -> ",nodo->dato);
}

TPtr pop(TPtr * p){
    TPtr aux; 
    aux = NULL; 
    if (!estaVacia(*p))
    {
        aux  = *p;
        *p = (*p)->sig;    
    }
    
    return aux;
}


// Función para mostrar la pila
void mostrarCola(TPtr p) {
    TPtr aux; 
    if(! estaVacia(p)){
        printf("\n\n");
        aux = pop(&p);
        while (aux !=NULL )
        {
            mostrarNodo(aux);
            aux = pop(&p);
        }
    }
    else{
        printf("\nPila Vacía \n\n");
    }

}


// Función para eliminar todas la ocurrencias E de la pila
void Eliminar(TPtr *p, int E ) {
    TPtr aux, nuevC;

    nuevC = crearCola();

    if(! estaVacia(*p)){
        aux = pop(p);

        while (aux !=NULL )
        {
            if( aux->dato != E){
                push(&nuevC, aux);
            }
            aux = pop(p);
        }
        
        while (nuevC !=NULL )
        {
            push(p, pop(&nuevC));
        } 

    }
    else{
        printf("\n Cola Vacía \n\n");
    }

}

