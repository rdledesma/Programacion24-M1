#ifndef TAD_LISTAPACIENTES_H
#define TAD_LISTAPACIENTES_H
#include "TAD_Paciente.h"
#define TMX 10

typedef RPaciente TVector [TMX];
typedef struct{
	TVector lis;
	int tam;
} TLista;

TLista inicializa_lista();
int retorna_tam(TLista);
TLista carga_pacientes();
void agrega_pacientes(TLista *);
void elimina_pacientes(TLista *);
void modifica_pacientes(TLista *);
void mostra_pacientes(TLista );
void genera_atencion(TLista, TLista *);
void ordena_pacientes(TLista *);
int cantidad_pacientes(TLista );

#endif
