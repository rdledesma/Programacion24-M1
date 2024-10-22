/*Ejercicio 10: Una entrenadora de ciclismo lleva un registro con información de N entrenamientos*/
/*	realizados por un ciclista. Para cada entrenamiento, se registra la Velocidad del ciclista, el Tiempo*/
/*	transcurrido (en segundos), La fecha de realización (Dia/Mes/Año), y un Número de identificación para*/
/*	cada sesión. Se pide crear un programa que permita cargar la lista de N entrenamientos, además realizar*/
/*	un menú que permita:*/
/*	a) Agregar un nuevo entrenamiento.*/
/*	b) Eliminar un entrenamiento: Dado un Número de identificación, eliminar de la lista la información*/
/*	correspondiente a ese entrenamiento.*/
/*	c) Dado un mes y un año eliminar todas las actividades realizadas.*/
/*	d) Dado un día y un número de identificación. Mostar su actividad mostrar las actividades*/
/*	correspondientes.*/
/*	e) Filtrar entrenamientos por rango de tiempo: Dado un tiempo T, generar y mostrar una nueva lista con*/
/*	los entrenamientos cuyo tiempo transcurrido se encuentre en el intervalo [T-30 segundos y T+30*/
/*		segundos].*/
/*	f) Mostrar las listas:*/
/*	1. Dado un rango de dos Fecha 1 y Fecha 2, mostrar todas las actividades realizadas en ese rango.*/
/*	2. Mostrar toda la información registrada de los entrenamientos realizados.*/


#include <stdio.h>
#include <string.h>

#define MAX_ENTRENAMIENTOS 20

typedef struct {
	int dia,mes,anio;
}Tfecha;

typedef struct {
	int id;
	float velocidad;
	int tiempo;
	Tfecha fecha;
} Entrenamiento;

typedef Entrenamiento ListaEntrenamientos[MAX_ENTRENAMIENTOS];

int menu();
void Cargar_ListaEntrenamientos(ListaEntrenamientos, int*);
void eliminarEntrenamiento(ListaEntrenamientos ,int *);
void eliminarPorMesAnio(ListaEntrenamientos , int *);
void mostrarActividad(ListaEntrenamientos , int) ;
void filtrarPorTiempo(ListaEntrenamientos , int);
void mostrarPorRangoFechas(ListaEntrenamientos ,int);
void Mostrar_ListaEntrenamientos(ListaEntrenamientos, int);


int main() {
	ListaEntrenamientos entrenamientos;
	int n = 0,i;
	int opcion;
	
	printf("Ingrese el tamaño de lista: ");
	scanf("%d",&i);
	while(n<=i-1){
	Cargar_ListaEntrenamientos(entrenamientos,&n);
}
	
	do {
		opcion=menu();
		switch (opcion) {
		case 1:
			Cargar_ListaEntrenamientos(entrenamientos, &n);
			break;
		case 2:
			eliminarEntrenamiento(entrenamientos, &n);
			break;
		case 3:
			eliminarPorMesAnio(entrenamientos, &n);
			break;
		case 4:
			mostrarActividad(entrenamientos, n);
			break;
		case 5:
			filtrarPorTiempo(entrenamientos, n);
			break;
		case 6:
			mostrarPorRangoFechas(entrenamientos, n);
			break;
		case 7:
			Mostrar_ListaEntrenamientos(entrenamientos, n);
			break;
		case 8:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opcion no valida.\n");
		}
	} while (opcion != 8);
	
	return 0;
}
//Funciones privadas


int menu(){
	int opcion;
	printf("\nMenu:\n");
	printf("1. Agregar entrenamiento\n");
	printf("2. Eliminar entrenamiento\n");
	printf("3. Eliminar por mes y año\n");
	printf("4. Mostrar actividad por dia e ID\n");
	printf("5. Filtrar por rango de tiempo\n");
	printf("6. Mostrar por rango de fechas\n");
	printf("7. Mostrar todos los entrenamientos\n");
	printf("8. Salir\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &opcion);
	return opcion;
}

Tfecha Cargar_Fecha() {
	Tfecha Aux;
	
	printf("Ingrese Dia: ");
	scanf("%d", &Aux.dia);
	printf("Ingrese Mes: ");
	scanf("%d", &Aux.mes);
	printf("Ingrese Año: ");
	scanf("%d", &Aux.anio);
	return Aux;
}

void Mostrar_Fecha(Tfecha dfecha) {
	printf("Fecha: %02d/",dfecha.dia);
	printf("%02d/", dfecha.mes);
	printf("%04d\n", dfecha.anio);
}
	
	//Funciones de Registros 
	
Entrenamiento Cargar_Datos() {
	Entrenamiento Aux;
	printf("Ingrese ID: ");
	scanf("%d", &Aux.id);
	printf("Ingrese Velocidad: ");
	scanf("%f", &Aux.velocidad);
	printf("Ingrese Tiempo (en segundos): ");
	scanf("%d", &Aux.tiempo);
	Aux.fecha=Cargar_Fecha();
	return Aux;
}

void Mostrar_Datos(Entrenamiento Dato) {
	printf("ID: %d ", Dato.id);
	printf("Velocidad: %.2f ", Dato.velocidad);
	printf("Tiempo: %d ", Dato.tiempo);
	Mostrar_Fecha(Dato.fecha);
}
	
//Funciones de Lista de Registros
	
void Cargar_ListaEntrenamientos(ListaEntrenamientos entrenamientos, int *n){
	if (*n < MAX_ENTRENAMIENTOS) {
		entrenamientos[*n]=Cargar_Datos();
		printf("\n");
		(*n)++;
	} else {
		printf("No se pueden agregar más entrenamientos.\n");
	}
}

	
void eliminarEntrenamiento(ListaEntrenamientos entrenamientos, int *n) {
	int id;
	printf("Ingrese ID del entrenamiento a eliminar: ");
	scanf("%d", &id);
	
	for (int i = 0; i < *n; i++) {
		if (entrenamientos[i].id == id) {
			for (int j = i; j < *n - 1; j++) {
				entrenamientos[j] = entrenamientos[j + 1];
			}
			(*n)--;
			return;
		}
	}
	printf("Entrenamiento con ID %d no encontrado.\n", id);
}

void eliminarPorMesAnio(ListaEntrenamientos entrenamientos, int *n) {
	int mes,anio;
	printf("Ingrese mes y año (MM AAAA): ");
	scanf("%d %d", &mes, &anio);
	
	for (int i = 0; i < *n; ) {
		if (entrenamientos[i].fecha.mes == mes && entrenamientos[i].fecha.anio == anio) {
			for (int j = i; j < *n - 1; j++) {
				entrenamientos[j] = entrenamientos[j + 1];
			}
			(*n)--;
		} else {
			i++;
		}
	}
}

void mostrarActividad(ListaEntrenamientos entrenamientos, int n) {
	int id,dia;
	
	printf("Ingrese dia e ID (DD ID): ");
	scanf("%d %d", &dia, &id);
	
	for (int i = 0; i < n; i++) {
		if (entrenamientos[i].fecha.dia == dia && entrenamientos[i].id == id) {
				   Mostrar_Datos(entrenamientos[i]);
			return;
		}
	}
	printf("Actividad no encontrada para el dia %d con ID %d.\n", dia, id);
}

void filtrarPorTiempo(ListaEntrenamientos entrenamientos, int n) {
	int T;
	printf("Ingrese tiempo T: ");
	scanf("%d", &T);
	
	printf("Entrenamientos en el rango [%d, %d]:\n", T - 30, T + 30);
	for (int i = 0; i < n; i++) {
		if (entrenamientos[i].tiempo >= T - 30 && entrenamientos[i].tiempo <= T + 30) {
			Mostrar_Datos(entrenamientos[i]);
		}
	}
}



void mostrarPorRangoFechas(ListaEntrenamientos entrenamientos, int n) {
	int dia1, mes1, anio1, dia2, mes2, anio2;
	printf("Ingrese rango de fechas (DD MM AAAA DD MM AAAA): ");
	scanf("%d %d %d %d %d %d", &dia1, &mes1, &anio1, &dia2, &mes2, &anio2);
	
	printf("\nEntrenamientos entre %02d/%02d/%04d y %02d/%02d/%04d:\n", dia1, mes1, anio1, dia2, mes2, anio2);
	for (int i = 0; i < n; i++) {
		if ((entrenamientos[i].fecha.anio > anio1 || (entrenamientos[i].fecha.anio == anio1 && entrenamientos[i].fecha.mes > mes1) || 
			 (entrenamientos[i].fecha.anio == anio1 && entrenamientos[i].fecha.mes == mes1 && entrenamientos[i].fecha.dia >= dia1)) &&
			(entrenamientos[i].fecha.anio < anio2 || (entrenamientos[i].fecha.anio == anio2 && entrenamientos[i].fecha.mes < mes2) || 
			 (entrenamientos[i].fecha.anio == anio2 && entrenamientos[i].fecha.mes == mes2 && entrenamientos[i].fecha.dia <= dia2))) {
			Mostrar_Datos(entrenamientos[i]);
		}
	}
}

	
void Mostrar_ListaEntrenamientos(ListaEntrenamientos entrenamientos, int n){
	printf("Todos los entrenamientos:\n");
	for (int i = 0; i < n; i++) {
			   Mostrar_Datos(entrenamientos[i]);
	}
}