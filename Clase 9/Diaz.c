#include <stdio.h>
/*
==========COMPLETO==============
Ejercicio10: 
*/
#define max 50
typedef struct{
	int dia;
	int mes;
	int anio;
}Tfecha;
typedef struct{
	int vel;
	int tiempo;
	Tfecha fecha;
	int cod;
}Tentrenamiento;

typedef Tentrenamiento Tvec[max];

short menu();
//======prototipos para cargar registro========
void cargarVector(Tvec,int);
Tentrenamiento cargarRegistro();
void cargarUno(Tvec,int*);

//======prototipos para mostrar registro========
void mostrarVector(Tvec,int);
void mostrarRegistro(Tentrenamiento);

void mostrarfiltrado(Tvec,int);
void mostrarRangofechas(Tvec,int);
void generarVectorfiltrado(Tvec,int,Tvec,int*);

//======prototipos para eliminar registro=======
void eliminaFiltrado(Tvec,int*);
void eliminarRegistro(Tvec,int*,int);
void eliminaUno(Tvec,int*);

//prototipo de busqyeda secuencial
int busquedaSecuencial(Tvec,int,int);

int main() {
	Tvec A,T;
	int N,M=0;
	short opc;
	
	printf("ingrese tamaño del vector:");
	scanf("%d",&N);

	cargarVector(A,N);
	mostrarVector(A,N);
	do{
		opc=menu();
		switch(opc){
		case 1:
			printf("===========AGREGAR UN ALUMNO=============\n");
			cargarUno(A,&N);
			//falta verificar que no se ingrese mas de un dni repetido
			break;
		case 2:
			printf("=======ELIMINAR UN ENTRENAMIENTO===========\n");
			eliminaUno(A,&N);
			//funciona bien solo falta los contadores
			break;
		case 3:
			printf("===========ELIMINAR ACTIVIDAD DADO UN MES Y AÑO===========\n");
			//Llamar al módulo que elimina ese código
			eliminaFiltrado(A,&N);
			break;
		case 4:
			printf("===========MOSTRAR ACTIVIDADES POR NUMERO DE ID Y DIA============\n");
			mostrarfiltrado(A,N);
			break;
		case 5:
			printf("===========MOSTRAR POR RANGO DE TIEMPO============\n");
			generarVectorfiltrado(A,N,T,&M);
			printf("=======vector T ======\n");
			mostrarVector(T,M);
			break;
		case 6:
			printf("===========MOSTRAR POR RANGO FECHA============\n");
			mostrarRangofechas(A,N);
			break;
		case 7:
			printf("===========MOSTRAR LISTA COMPLETA============\n");
			mostrarVector(A,N);
			printf("=======vector T ======\n");
			mostrarVector(T,M);
			break;
		}
		
		
	} while(opc!=0);
	return 0;
}
//===========================================
short menu(){
	short opcion;
	
	printf("===========MENU=========\n");
	printf("1) Agregar un nuevo entrenamiento\n");
	printf("2) Eliminar un entrenamiento por id\n");
	printf("3) Eliminar entrenamientos por dia y mes\n");
	printf("4) Mostrar por Filtro id y dia\n");
	printf("5) MOstrar por rango de tiempo \n");
	printf("6) Mostrar por rango de fechas\n");	
	printf("7) Mostrar la lista\n");
	printf("0) salir\n");
	printf("=======================\n");
	
	do{
		printf("ingrese una opcion:");
		scanf("%hd",&opcion);
		
	} while(!(opcion>=0&&opcion<8));
	
	return opcion;
}
void cargarVector(Tvec v,int tam){
	int i;
	Tentrenamiento aux;
	for(i=1;i<=tam;i++){
		aux=cargarRegistro();
		v[i]=aux;
	}
}
Tentrenamiento cargarRegistro(){
	Tentrenamiento aux;
	printf("ingrese una velocidad del ciclista:");
	scanf("%d",&aux.vel);
	
	printf("ingrese el tiempo transcurrido:");
	scanf("%d",&aux.tiempo);
	
	printf("ingrese el dia:");
	scanf("%d",&aux.fecha.dia);
	
	printf("ingrese el mes:");
	scanf("%d",&aux.fecha.mes);
	
	printf("ingrese el año:");
	scanf("%d",&aux.fecha.anio);
	
	printf("ingrese un numero de indentificacion:");
	scanf("%d",&aux.cod);
	return aux;
}	
void cargarUno(Tvec v,int *tam){
	v[*tam+1]=cargarRegistro();
	*tam=*tam+1;
}

void mostrarVector(Tvec vec,int tam){
	int i;
	for(i=1;i<=tam;i++){
		mostrarRegistro(vec[i]);
	}
}
void mostrarRegistro(Tentrenamiento AUX){
	printf("Su velocidad:%d\n",AUX.vel);
	
	printf("Su tiempo transcurrido: %d\n",AUX.tiempo);
	
	printf(" La fecha:%d/%d/%d\n",AUX.fecha.dia,AUX.fecha.mes,AUX.fecha.anio);
	
	printf("Su indentificacion:%d\n",AUX.cod);
}

//======elimina registro registro========
void eliminaFiltrado(Tvec v,int *tam){
	int dia,mes,i=1;
	printf("ingrese un dia:");
	scanf("%d",&dia);

	printf("ingrese un mes:");
	scanf("%d",&mes);
	
	while(i<=*tam){
		if(v[i].fecha.dia==dia && v[i].fecha.mes==mes)
			eliminarRegistro(v,tam,i);
		else
			i++;
	}
}
void eliminarRegistro(Tvec v,int *tam,int pos){
	int i;
	for(i=pos;i<=*tam-1;i++){
		v[i]=v[i+1];
	}
	*tam=*tam-1;
}

void eliminaUno(Tvec v,int *tam){
	int cod,pos;
	printf("ingrese un codigo:");
	scanf("%d",&cod);
	pos=busquedaSecuencial(v,*tam,cod);
	if(pos>0)
		eliminarRegistro(v,tam,pos);
	else
		printf("codigo no encontrado\n");
}
int busquedaSecuencial(Tvec v,int tam, int buscar){
	int i=1,ret;
	while(i<=tam && v[i].cod!=buscar)
		i++;
	if(i<=tam)
		ret=i;
	else
		ret=-1;
	return ret;
}

void mostrarfiltrado(Tvec v,int tam){
	int dia,cod,i;
	printf("ingrese un codigo:");
	scanf("%d",&cod);
	printf("ingrese un dia:");
	scanf("%d",&dia);
	for(i=1;i<=tam;i++){
		if(v[i].fecha.dia==dia && v[i].cod==cod)
			mostrarRegistro(v[i]);
	}
}
void mostrarRangofechas(Tvec v,int tam){
	int dia1,dia2,mes1,mes2,anio1,anio2,i;
	printf("ingrese un dia:");
	scanf("%d",&dia1);
	printf("ingrese un mes:");
	scanf("%d",&mes1);
	printf("ingrese un año:");
	scanf("%d",&anio1);
	
	printf("ingrese un dia:");
	scanf("%d",&dia2);
	printf("ingrese un mes:");
	scanf("%d",&mes2);
	printf("ingrese un año:");
	scanf("%d",&anio2);
	
	for(i=1;i<=tam;i++){
		if((v[i].fecha.dia>=dia1 && v[i].fecha.mes>=mes1 && v[i].fecha.anio>=anio1)&&(v[i].fecha.dia<=dia2 && v[i].fecha.mes<=mes2 && v[i].fecha.anio<=anio2))
			mostrarRegistro(v[i]);
	}
}


void generarVectorfiltrado(Tvec v,int tam,Tvec T,int *M){
	int tiempo,i;
	printf("ingrese un tiempo:");
	scanf("%d",&tiempo);
	for(i=1;i<=tam;i++){
		if((tiempo-30)<= v[i].tiempo && v[i].tiempo<=(tiempo+30)){
			T[*M+1]=v[i];
			*M=*M+1;
		}
		
	}
}