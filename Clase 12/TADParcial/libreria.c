#include "libreria.h"
#include "libro.h"
#include <stdio.h>


libreria crear(){
    libreria nue;
    nue.tam = -1;
    return nue;
}

int vacia(libreria l ){
    return l.tam<0 ;
} 


void agregaFin(libreria* lib){
    libro nue;

    nue = creaLibro();
    lib->tam = lib->tam + 1;
    lib->lista[lib->tam] = nue;
    
}
void muestra(libreria lib){
    int i;
    
    if(!vacia(lib)){
        printf("\nMostrando Lista\n");
        for(i=0; i<=lib.tam; i++){
            muestraLibro(lib.lista[i]);
        }
    }
    else{
        printf("\nLista vacia\n");
    }
        
    
     
}


libreria filtraEditorial(libreria l, Tcadena editorial){
    int i, contGroup;
    libreria grupo;
    grupo = crear();
    
    contGroup = 0;

    for(i=0; i<=l.tam; i++){
        if( comparaEditorial(l.lista[i], editorial) == 0 ){
            grupo.tam = contGroup;
            grupo.lista[contGroup] = l.lista[i];
            contGroup ++;
        }
    }
    return grupo;
}

libreria filtraDisponibles(libreria l){
    int i, contGroup;
    libreria grupo;
    grupo = crear();
    
    contGroup = 0;

    for(i=0; i<=l.tam; i++){
        if( disponibilidad(l.lista[i])){
            grupo.tam = contGroup;
            grupo.lista[contGroup] = l.lista[i];
            contGroup ++;
        }
    }
    return grupo;
}

void qSort(libreria * l, int ini, int fin)
{
    libro piv;
	int izq, der, med;
	
	if (ini<fin){
		piv=l->lista[ini];
		izq=ini;
		der=fin;
		while (der>izq){
			while (der>izq && esmayor(l->lista[der], piv))
				der--;
			if (der>izq){
				l->lista[izq]=l->lista[der];
				izq++;
			}
			while (der>izq && esmenor(l->lista[izq], piv))
				izq++;
			if (der>izq){
				l->lista[der]=l->lista[izq];
				der--;
			}
		}
		l->lista[izq]=piv;
		med=izq;
		qSort(l,ini,med-1);
		qSort(l,med+1,fin);
	}
}



void muestraPorEditorial(libreria l){
    Tcadena edit;
    libreria aux;
    if(!vacia(l)){

        aux = filtraDisponibles(l);
        if(!vacia(aux)){

            printf("Ingrese Editorial: ");
            cargaCadena(edit);
            aux = filtraEditorial(aux, edit);

            if(!vacia(aux)){
                qSort(&aux, 0, aux.tam);
                muestra(aux);
            }
            else{
                printf("\n No hay disponibles para %s \n ", edit);
            }
        }
        else{
            printf("\n No hay disponibles \n ");
        }

    }else{
        printf("\n Ĺibreria vacía\n ");
    }
}

int calculaDisponibilidadRec(libreria l, int idx, int lim ){
    if(idx == l.tam){
        if( cantidad(l.lista[idx]) < lim ){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if( cantidad(l.lista[idx]) < lim ){
            return 1  + calculaDisponibilidadRec(l, idx +1, l.tam);
        }
        else{
            return 0 + calculaDisponibilidadRec(l, idx +1, l.tam);
        }
    }

}

void cuentaDisponibilidad(libreria l){
    int res, limite;

    if(!vacia(l)){
        limite = 2;
        res = calculaDisponibilidadRec(l,0,limite);
        printf("\n %d libros tienen disponibidad menor a %d \n", res, limite);
    }
    else{
        printf("\nLibreria vacía \n");
    }
} 

int devuelvePosicion(libreria l, int buscado){
    int i,pos;
    i=0;
    while(i<=l.tam &&  (ISBN(l.lista[i]) != buscado)){
        i ++;
    }

    return i;
}

void correrUno(libreria *l, int pos){
    int i;
    i = pos;
    for(i=pos; i<l->tam; i++){
        l->lista[i] = l->lista[i+1];  
    }
    l->tam--;
}

void eliminarLibro(libreria* l){
    int ISBN, pos;
    if(!vacia(*l)){
        printf("Ingrese ISBN: ");
        scanf("%d",&ISBN);
        fflush(stdin);
        pos  = devuelvePosicion(*l, ISBN);
        
        if(pos< l->tam){
            correrUno(l, pos );
            printf("\n Eliminado \n");
        }
        else{
            printf("\n ISBN no encontrado \n");
        }



    }
    else{
        printf("\nLibreria vacía \n");
    }
}