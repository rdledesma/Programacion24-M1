#include <stdio.h>
#include <string.h>
struct Fecha{
	int dia;
	int mes;
	int anio;
};
struct Entrenamientos{
	int vel;
	int time;
	struct Fecha fecha;
	int ID;
};
typedef struct Entrenamientos Vec[50];

void agrega(Vec,int*);
void elimina(Vec,int*);
void elimAct(Vec*,int);
void muestraAct(Vec*,int);
void filtro(Vec*,Vec*,int);
void muestra(Vec,int);
void menu(Vec,int);
int main(){
    int N,i;
	Vec vector;
	printf("Entrenamientos a cargar: ");scanf("%d",&N);
	for(i=1;i<=N;i++){
		printf("Identificador: ");scanf("%d",&vector[i].ID);
		printf("dia: ");scanf("%d",&vector[i].fecha.dia);
		printf("mes: ");scanf("%d",&vector[i].fecha.mes);
		printf("año: ");scanf("%d",&vector[i].fecha.anio);
		printf("velocidad: ");scanf("%d",&vector[i].vel);
		printf("tiempo: ");scanf("%d",&vector[i].time);
	}
	menu(vector,N);
	return 0;
}

void agrega(Vec V, int *N){
	(*N)++;
	printf("Identificador: ");scanf("%d",&V[*N].ID);
	printf("dia: ");scanf("%d",&V[*N].fecha.dia);
	printf("mes: ");scanf("%d",&V[*N].fecha.mes);
	printf("año: ");scanf("%d",&V[*N].fecha.anio);
	printf("velocidad: ");scanf("%d",&V[*N].vel);
	printf("tiempo: ");scanf("%d",&V[*N].time);
}

void elimina(Vec V, int *N){
	int i=1,b;
	printf("Identificacion a buscar: ");
    scanf("%d",&b);
	
    while(i>=*N && V[i].ID !=b){
		i++;
	}
	if(V[i].ID !=b){
		while(i>=*N){
			V[i]=V[i+1];
			i++;
		}
		(*N)--;
	}
	else
	   printf("Identificador no encontrado");
}

/*
void elimAct(Vec *V, int N){
	int mb,ab,i=1;
	printf("Mes a buscar: ");scanf("%d",&mb);
	printf("Año a buscar: ");scanf("%d",&ab);
	while(i!=N){
		while(i>=N && V[i]->fecha.mes !=mb && V[i]->fecha.anio !=ab){
		i++;}
		if(V[i]->fecha.mes !=mb){
			while(i>=N){
				*V[i]=*V[i+1];
				i++;
			}
			N--;
	}
}}
void muestraAct(Vec*V, int N){
	int db,idb,i;
	printf("Dia a buscar: ");scanf("%d",&db);
	printf("Identificador a buscar");scanf("%d",&idb);
	for(i=1;i<=N;i++){
		if(V[i]->ID == idb && V[i]->fecha.dia){
			printf("Identificador: %d",V[i]->ID);
			printf("Fecha: %d / %d / %d",V[i]->fecha.dia,V[i]->fecha.mes,V[i]->fecha.anio);
			printf("Tiempo: %d",V[i]->time);
			printf("Velocidad: %d",V[i]->vel);
		}
	}
}
void filtro(Vec *V,Vec *F, int N){
	int i,Tb;
	printf("Tiempo a buscar");scanf("%d",&Tb);
	for(i=1;i<=N;i++){
		if(V[i]->time > Tb-30 && V[i]->time < Tb+30){
			*F[i]=*V[i];
		}
	}
}
*/
void muestra(Vec V,int N){
	int i;
	for(i=1;i<=N;i++){
		printf("Identificador: %d",V[i].ID);
		printf("Fecha: %d / %d / %d",V[i].fecha.dia,V[i].fecha.mes,V[i].fecha.anio);
		printf("Tiempo: %d",V[i].time);
		printf("Velocidad: %d",V[i].vel);
	}
}





Ejercicio 4:

    Verdadero.
    Las estructuras en C pueden contener arreglos como uno de sus campos, 
	lo que permite almacenar colecciones de datos en una estructura.

    Falso.
    Un puntero que no apunta a ninguna dirección válida se llama puntero nulo, no genérico. 
	El puntero genérico es void*, que puede apuntar a cualquier tipo de dato.

    Verdadero.
    El operador & en C devuelve la dirección de memoria de una variable.


    Verdadero.
    Las colas siguen la política FIFO (First In, First Out),
	 donde el primer elemento en entrar es el primero en salir.

    
    Verdadero.
    La instrucción #define se utiliza para definir constantes y macros en el preprocesador de C.

    
    Falso.
    Las variables globales en C se declaran fuera de las funciones,
	 no dentro de ellas, para que sean accesibles en todo el programa.


En C, los struct pueden contener funciones como campos.
La función return termina la ejecución del programa completo, no solo de la función donde se encuentra.








void menu(Vec V, int N){
	int opc;
	do{printf("MENU\n1.Agregar un Entrenamiento\n2.Eliminar un entrenamiento\n3.Eliminar actividades de un periodo\n4.Mostrar actividades de un dia\n5.Filtrar entrenamientos\n6.Mostrar las listas\n0.Salir\nOpcion: ");scanf("%d",&opc);
		switch(opc){
		case 1:
			agrega(V,&N);
			break;
		case 2:
			elimina(V,&N);
			break;
		
        /* 
        case 3:
			elimAct(V,N);
			break;
		case 4:
			muestraAct(V,N);
			break;
		case 5:
			Vec F;
			filtro(V,&F,N);
			break;
		case 6:{
			int l;printf("mostrar: 1.Lista en un rango de tiempo\n2.lista original\nopcion: ");scanf("%d",&l);
			if(l==2)
				muestra(F,N);
			/*
            else
				{int d1,m1,a1,d2,m2,a2,i; No supe del todo como resolver esta problematica de filtrar por fechas
				printf("fecha inicio(dia):");scanf("%d",&d1);
				printf("fecha inicio(mes):");scanf("%d",&m1);
				printf("fecha inicio(año):");scanf("%d",&a1);
				printf("fecha final(dia):");scanf("%d",&d2);
				printf("fecha final(mes):");scanf("%d",&m2);
				printf("fecha final(año):");scanf("%d",&a2);
				for(i=1;i<=N;i++){
					if(V[i]->fecha.anio >= a1 && V[i]->fecha.anio <= a2 ){
						if(V[i]->fecha.anio == a1 &&V[i]->fecha.mes >= m1){
							if(V[i]->fecha.mes == m1 && V[i]->fecha.dia >= d1){
								printf("Identificador: %d",V[i]->ID);
								printf("Fecha: %d / %d / %d",V[i]->fecha.dia,V[i]->fecha.mes,V[i]->fecha.anio);
								printf("Tiempo: %d",V[i]->time);
								printf("Velocidad: %d",V[i]->vel);
							}
						}
						else if(V[i]->fecha.anio == a2 &&V[i]->fecha.mes <= m2){
							if(V[i]->fecha.mes == m2 && V[i]->fecha.dia <= d2){
								printf("Identificador: %d",V[i]->ID);
								printf("Fecha: %d / %d / %d",V[i]->fecha.dia,V[i]->fecha.mes,V[i]->fecha.anio);
								printf("Tiempo: %d",V[i]->time);
								printf("Velocidad: %d",V[i]->vel);
							}
						}
					}
				}
				
			};}
			break;
        */
        case 9:
            for (int i=1; i<=N; i++){
                printf("\n\n Entrenamieno : %d",i);
                printf("\n Identificador: %d",V[i].ID);
                printf("\n Fecha: %d / %d / %d",V[i].fecha.dia,V[i].fecha.mes,V[i].fecha.anio);
                printf("\n Tiempo: %d",V[i].time);
                printf("\n Velocidad: %d",V[i].vel);
            }
            break;
		case 0:
			printf("Saliendo");
			break;
		default:
			break;
		}
	} while(opc!=0);
}

