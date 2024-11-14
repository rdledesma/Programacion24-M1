#include "libro.h"
#include <stdio.h>
#include "cadena.h"
#include <string.h>


libro creaLibro(void){
    libro nue;
    printf("\n  **Cargar un Libro ** \n");
    fflush(stdin);
	
    printf("\n Titulo: ");
    cargaCadena(nue.titulo);    

    printf("\n ISBN: ");
    scanf("%ld",&nue.ISBN);    
    fflush(stdin);
    
    printf("\n Cantidad Disponible: ");
    scanf("%d",&nue.cantidad);    
    scanf("%*c");

    printf("\n Editorial: ");
    cargaCadena(nue.edit);   


    return nue;
}
void muestraLibro(libro l ){
    printf("\n  ****");
    printf("\n Titulo: %s \n ISBN: %ld \n Cant.: %d  \n Edit: %s", 
    l.titulo, l.ISBN, l.cantidad, l.edit );
    printf("\n  ****");
}



int comparaEditorial(libro l , Tcadena t){
    return strcmp(l.edit, t);
 
}


int cantidad(libro l ){
    return l.cantidad;
}

int ISBN(libro l ){
    return l.ISBN;
}


int disponibilidad(libro l ){
    return l.cantidad>0;
}

int esmayor(libro l1, libro l2){
    return strcmp(l1.edit, l2.edit) > 0;
}

int esmenor(libro l1, libro l2){
    return strcmp(l1.edit, l2.edit) < 0;
}