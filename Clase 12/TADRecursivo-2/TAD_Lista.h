#ifndef TAD_LISTA
#define TAD_LISTA
#define MAXList 20
#include "TAD_Cadena.h"

typedef struct 
{
    
    TCadena lista[MAXList];
    int tam;

}TLista;

TLista crearLista();
void MSort(TLista);
void mostrar(TLista);
void ordenar(TLista);


#endif