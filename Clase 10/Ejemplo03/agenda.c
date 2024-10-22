#include "agenda.h"
#include <stdio.h>

void inicializarAgenda(Agenda *agenda) {
    agenda->cantidad = 0;
}

int agregarPersona(Agenda *agenda, Persona p) {
    if (agenda->cantidad < MAX_PERSONAS) {
        agenda->personas[agenda->cantidad++] = p;
        return 1;  // Éxito
    }
    return 0;  // Error: Agenda llena
}

void listarAgenda(Agenda *agenda) {
    for (int i = 0; i < agenda->cantidad; i++) {
        imprimirPersona(agenda->personas[i]);
    }
}
