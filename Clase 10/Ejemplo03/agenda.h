#ifndef AGENDA_H
#define AGENDA_H

#include "persona.h"

#define MAX_PERSONAS 100

typedef struct {
    Persona personas[MAX_PERSONAS];
    int cantidad;
} Agenda;

void inicializarAgenda(Agenda *agenda);
int agregarPersona(Agenda *agenda, Persona p);
void listarAgenda(Agenda *agenda);

#endif
