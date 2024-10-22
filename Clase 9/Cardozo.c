#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float velocidad;
	int tiempo;
	char fecha[11]; 
	char id_entrenamiento[20];
} Entrenamiento;

Entrenamiento entrenamientos[100];
int count = 0;

void agregar_entrenamiento() {
	if (count >= 100) {
		printf("No se pueden agregar más entrenamientos.\n");
		return;
	}
	printf("Ingrese la velocidad (km/h): ");
	scanf("%f", &entrenamientos[count].velocidad);
	printf("Ingrese el tiempo (segundos): ");
	scanf("%d", &entrenamientos[count].tiempo);
	printf("Ingrese la fecha (DD/MM/AAAA): ");
	scanf("%s", entrenamientos[count].fecha);
	printf("Ingrese el ID del entrenamiento: ");
	scanf("%s", entrenamientos[count].id_entrenamiento);
	count++;
	printf("Entrenamiento agregado con éxito.\n");
}

void eliminar_entrenamiento() {
	char id[20];
	printf("Ingrese el ID del entrenamiento a eliminar: ");
	scanf("%s", id);
	for (int i = 0; i < count; i++) {
		if (strcmp(entrenamientos[i].id_entrenamiento, id) == 0) {
			for (int j = i; j < count - 1; j++) {
				entrenamientos[j] = entrenamientos[j + 1];
			}
			count--;
			printf("Entrenamiento eliminado.\n");
			return;
		}
	}
	printf("Entrenamiento no encontrado.\n");
}

void eliminar_entrenamientos_por_fecha() {
	int mes, anio;
	printf("Ingrese el mes (1-12): ");
	scanf("%d", &mes);
	printf("Ingrese el año (AAAA): ");
	scanf("%d", &anio);
	for (int i = 0; i < count; i++) {
		if (atoi(&entrenamientos[i].fecha[3]) == mes && atoi(&entrenamientos[i].fecha[6]) == anio) {
			for (int j = i; j < count - 1; j++) {
				entrenamientos[j] = entrenamientos[j + 1];
			}
			count--;
			i--; 
		}
	}
	printf("Entrenamientos eliminados del mes y año especificados.\n");
}

void mostrar_actividad_por_dia() {
	int dia;
	char id[20];
	printf("Ingrese el día (1-31): ");
	scanf("%d", &dia);
	printf("Ingrese el ID del entrenamiento: ");
	scanf("%s", id);
	for (int i = 0; i < count; i++) {
		if (atoi(&entrenamientos[i].fecha[0]) == dia && strcmp(entrenamientos[i].id_entrenamiento, id) == 0) {
			printf("%s, Velocidad: %.2f km/h, Tiempo: %d seg, Fecha: %s\n",
				   entrenamientos[i].id_entrenamiento, entrenamientos[i].velocidad,
				   entrenamientos[i].tiempo, entrenamientos[i].fecha);
			return;
		}
	}
	printf("No se encontraron actividades para el día y ID especificados.\n");
}

void filtrar_entrenamientos_por_tiempo() {
	int tiempo;
	printf("Ingrese el tiempo (segundos): ");
	scanf("%d", &tiempo);
	for (int i = 0; i < count; i++) {
		if (entrenamientos[i].tiempo >= tiempo - 30 && entrenamientos[i].tiempo <= tiempo + 30) {
			printf("%s, Velocidad: %.2f km/h, Tiempo: %d seg, Fecha: %s\n",
				   entrenamientos[i].id_entrenamiento, entrenamientos[i].velocidad,
				   entrenamientos[i].tiempo, entrenamientos[i].fecha);
		}
	}
}

void mostrar_actividades_en_rango() {
	char fecha_inicio[11], fecha_fin[11];
	printf("Ingrese la fecha de inicio (DD/MM/AAAA): ");
	scanf("%s", fecha_inicio);
	printf("Ingrese la fecha de fin (DD/MM/AAAA): ");
	scanf("%s", fecha_fin);
	for (int i = 0; i < count; i++) {
		if (strcmp(entrenamientos[i].fecha, fecha_inicio) >= 0 && strcmp(entrenamientos[i].fecha, fecha_fin) <= 0) {
			printf("%s, Velocidad: %.2f km/h, Tiempo: %d seg, Fecha: %s\n",
				   entrenamientos[i].id_entrenamiento, entrenamientos[i].velocidad,
				   entrenamientos[i].tiempo, entrenamientos[i].fecha);
		}
	}
}

void mostrar_todas_las_actividades() {
	for (int i = 0; i < count; i++) {
		printf("%s, Velocidad: %.2f km/h, Tiempo: %d seg, Fecha: %s\n",
			   entrenamientos[i].id_entrenamiento, entrenamientos[i].velocidad,
			   entrenamientos[i].tiempo, entrenamientos[i].fecha);
	}
}

int main() {
	int opcion;
	while (1) {
		printf("\n--- Menú ---\n");
		printf("1. Agregar un nuevo entrenamiento\n");
		printf("2. Eliminar un entrenamiento\n");
		printf("3. Eliminar entrenamientos por mes y año\n");
		printf("4. Mostrar actividad por día y ID\n");
		printf("5. Filtrar entrenamientos por rango de tiempo\n");
		printf("6. Mostrar actividades en un rango de fechas\n");
		printf("7. Mostrar todas las actividades\n");
		printf("8. Salir\n");
		printf("Seleccione una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1: agregar_entrenamiento(); break;
		case 2: eliminar_entrenamiento(); break;
		case 3: eliminar_entrenamientos_por_fecha(); break;
		case 4: mostrar_actividad_por_dia(); break;
		case 5: filtrar_entrenamientos_por_tiempo(); break;
		case 6: mostrar_actividades_en_rango(); break;
		case 7: mostrar_todas_las_actividades(); break;
		case 8: exit(0);
		default: printf("Opción no válida. Intente nuevamente.\n");
		}
	}
	return 0;
}