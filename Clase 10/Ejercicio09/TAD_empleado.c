#include <stdio.h>
#include "TAD_empleado.h"
#include <string.h>


Employee crateEmployee(){
    Employee aux;
    

    aux.dni = 123;
    
    printf("\n");
    return aux;
};


void updateEmployee(Employee e){
    printf("\n Update");

    printf("\n");
};


void showEmployee(Employee e){ 
    printf("\n Show");

    printf("\n dni %ld", e.dni);
    printf("\n");
};

void deleteEmployee(Employee e){ 
    printf("\n Delete");

    printf("\n");
};
