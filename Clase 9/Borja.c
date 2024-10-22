#include <stdio.h>
#include <stdlib.h>
#define TMAX 100
typedef struct{
	int dia, mes, anio;
}Tfecha;
typedef struct {
	float vel;
	long tiempo;
	Tfecha fecha;
	long ident;
}Training;
typedef Training Ent[TMAX];
void carga_lista (Ent , int*);
int menu();
void agregar(Ent, int*);
Training carga_reg();
void ordena(Ent, int);
void eliminar(Ent, int*);
void eliminar_ent(Ent, int);
void borrar(Training *);
void mostrar(Training);
void int_nuevalist(Ent, int);
int menusub();
void rango(Ent, int);
void muestra(Ent, int);
int main(int argc, char *argv[]) {
	Ent Treino;
	int i, N, op, Dia, band;
	long Identificacion;
	carga_lista(Treino, &N);
	op=menu();
	do{
		
	switch(op){
	case 0:
		printf("\nElegiste opcion: 0 **salir del menu**");
		break;
	case 1:
		printf("\nElegiste opcion: 1. **Agregar un entremaniento.** ");
		agregar(Treino, &N);
		ordena(Treino, N);
		break;
	case 2:
		printf("\nElegiste opcion: 2. **Eliminar un entremaniento.** ");
		eliminar_ent(Treino, N);
		break;
	case 3:
		printf("\nElegiste opcion: 3. **Eliminar actividades realizadas.** ");
		eliminar(Treino, &N);
		break;
	case 4:
		printf("\nElegiste opcion: 4. **Mostrar actividades correspondientes a un dia.** ");
		printf("\nIngrese un dia: ");
		scanf("%d", &Dia);
		printf("\nIngrese un numero de Identificacion: ");
		scanf("%ld", &Identificacion);
		for(i=1;i<=N;i++){
			if(Treino[i].fecha.dia==Dia && Treino[i].ident==Identificacion)
				mostrar(Treino[i]);}
		break;
	case 5:
		printf("\nElegiste opcion: 5. Filtrar entrenamiento por rango de tiempo. ");
		int_nuevalist(Treino, N);
		break;
	case 6:
		printf("\nElegiste opcion: 6. **Mostrar listas.** ");
		band=menusub();
		if(band==1)
			rango(Treino,N);
		system("pause");
		if(band==2)
			muestra(Treino,N);
		break;
	default:
		printf("\n **Debe elegir una opcion velida.**");
	}
	} while(op!=0);
	return 0;
}
void carga_lista (Ent Treino, int *N){
	int i;
	printf("\nIngrese la cantidad de entremanientos: ");
	scanf("%d", N);
	for (i=1;i<=*N;i++){
		Treino[i]=carga_reg();
	}
}
Training carga_reg(){
	Training A;
	printf("\nIngrese el numero de identificacion: ");
	scanf("%ld",&A.ident);
	printf("\nIngrese la Fecha de realizacion DD/MM/AAAA : ");
	printf("\n Dia: ");
	scanf("%d",&A.fecha.dia);
	printf("\t mes: ");
	scanf("%d",&A.fecha.mes);
	printf("\t año: ");
	scanf("%d",&A.fecha.anio);
	printf("\nIngrese el tiempo transcurrido: ");
	scanf("%ld",&A.tiempo);
	printf("\nIngrese la velocidad del ciclista: ");
	scanf("%f",&A.vel);
	return A;
}
int menu (){
	int op;
	printf("\n Opcion 1: Agregar un Entrenamiento.");
	printf("\n Opcion 2: Eliminar un entrenamiento.");
	printf("\n Opcion 3: Eliminar actividades realizadas.");
	printf("\n Opcion 4: Mostrar actividad correspondiente a un dia.");
	printf("\n Opcion 5: Filtrar entrenamientos por rango de tiempo.");
	printf("\n Opcion 6: Mostrar las listas.");
	printf("\n Opcion 0: Cerrar menu.");
	printf("\n Ingrese una opcion: ");
	scanf("%d",&op);
	return op;
}
void agregar(Ent Treino,int*N){
	Treino[*N+1]=carga_reg();
	*N=*N+1;
}
void ordena(Ent Treino,int N){
	int i,j;
	for(i=1;i<=N;i++){
		for(j=N;j>=i;j--){
			if(Treino[j].fecha.mes<Treino[j-1].fecha.mes){
				Treino[0]=Treino[j];
				Treino[j]=Treino[j-1];
				Treino[j-1]=Treino[0];}
		}
	}
}
void eliminar(Ent Treino, int *N){
	int i,j,M,A;
	i=1;
	printf("\n Ingrese fecha a eliminar MM AAAA : ");
	printf("\n Mes: ");
	scanf("%d",&M);
	printf("\n Año: ");
	scanf("%d",&A);
	while(i<*N){
		if((Treino[i].fecha.mes==M) && (Treino[i].fecha.anio==A)){
			for(j=i;j<*N;j++) 
				Treino[j]=Treino[j+1];
			*N=*N-1;}
		i++;}
}
void eliminar_ent(Ent Treino, int N){
	int i;
	long Idd;
	printf("\nIngrese el numero de identificacion: ");
	scanf("%ld",&Idd);
	for(i=1;i<N;i++){
		if(Treino[i].ident==Idd)
			borrar(&Treino[i]);}
}
void borrar (Training *Treino){
		Treino->fecha.dia=0;
		Treino->fecha.mes=0;
		Treino->fecha.anio=0;
		Treino->tiempo=0;
		Treino->vel=0;
}
void mostrar(Training Treino){
	printf("\n Numero de indentificacion es: %ld",Treino.ident);
	printf("\n Fecha: %d/%d/%d",Treino.fecha.dia,Treino.fecha.mes,Treino.fecha.anio);
	printf("\n Tiempo: %ld",Treino.tiempo);
	printf("\n Velocidad: %f\n",Treino.vel);
}
void int_nuevalist(Ent Treino, int N){
	int i;
	long T,a,b;
	printf("\nIngrese el Tiempo: ");
	scanf("%ld",&T);
	a=T-30;
	b=T+30;
	for(i=1;i<=N;i++){
		if((Treino[i].tiempo<=b) && (Treino[i].tiempo>=a))
			mostrar(Treino[i]);
}
}
int menusub(){
	int ops;
	printf("\n Opcion 1 Dado un rango entre dos fechas.");
	printf("\n Opcion 2 Toda la lista");
	printf("\n Ingrese una opcion: ");
	scanf("%d",&ops);
	return ops;
}
void rango(Ent Treino,int N){
	int d,d1,a,a1,m,m1;
	printf("\nIngrese la primera Fecha(ddmmaaaa): ");
	printf("\n Dia: ");
	scanf("%d",&d);
	printf("\t Mes: ");
	scanf("%d",&m);
	printf("\t Año: ");
	scanf("%d",&a);
	printf("\nIngrese la segunda Fecha(ddmmaaaa): ");
	printf("\n Dia: ");
	scanf("%d",&d1);
	printf("\n Mes: ");
	scanf("%d",&m1);
	printf("\n Año: ");
	scanf("%d",&a1);
}
void muestra(Ent Treino,int N){
	int i;
	for(i=1;i<=N;i++)
		mostrar(Treino[i]);	
}