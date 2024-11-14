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
TPtr crearPila();
void pushN(TPtr*, int n);
void push(TPtr* p, TPtr nuevo);
void mostrarPila(TPtr);
TPtr pop(TPtr*);
void mostrarNodo(TPtr);

void Eliminar(TPtr*, int);

int main(){
    TPtr pila;
    
    int Elementos;


    pila = crearPila();

    Elementos = 3;

    pushN(&pila, Elementos);
    mostrarPila(pila);


    
    //pop(&pila);
    //pop(&pila);

    //mostrarPila(pila);
    
    //pushN(&pila, Elementos);
    Eliminar(&pila, 1);
    
    mostrarPila(pila);

    return 0;
}



// Función para crear una pila vacía (inicializar una pila)
TPtr crearPila() {
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

void push(TPtr* p, TPtr nuevo){
    //TPtr nuevo = crearNodo();
    nuevo->sig = *p;
    *p = nuevo;

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
void mostrarPila(TPtr p) {
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
    TPtr aux, nuevP;

    nuevP = crearPila();

    if(! estaVacia(*p)){
        aux = pop(p);

        while (aux !=NULL )
        {
            if( aux->dato != E){
                push(&nuevP, aux);
            }
            aux = pop(p);
        }
        
        while (nuevP !=NULL )
        {
            push(p, pop(&nuevP));
        } 

    }
    else{
        printf("\nPila Vacía \n\n");
    }

}

