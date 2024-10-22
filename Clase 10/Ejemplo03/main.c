#include "agenda.h"

int main() {
    Agenda agenda;
    inicializarAgenda(&agenda);

    Persona p1 = crearPersona("Ana", 25, 1.68);
    Persona p2 = crearPersona("Luis", 32, 1.80);

    agregarPersona(&agenda, p1);
    agregarPersona(&agenda, p2);

    listarAgenda(&agenda);
    return 0;
}
