#ifndef TAD_PACIENTE_H
#define TAD_PACIENTE_H
/* Apellido y Nombre, DNI, Tipo de Atención (Clínica, Odontología, 
Traumatología), Fecha de Atención */
#include "TAD_Cadena.h"

typedef struct{
	TCadena ape, nom;
	long dni;
	int tipo;
	long fecha; /*Formato largo aaaammdd*/
}RPaciente;

RPaciente cargar_paciente();
void mostrar_paciente(RPaciente);
void modificar_paciente(RPaciente *);
long retorna_DNI(RPaciente);
int compara_DNI(RPaciente, long);
int compara_fecha(RPaciente, long, long);
int compara_fecha_tipo(RPaciente, long, int);
int compara_apellidos(RPaciente, RPaciente);

#endif
