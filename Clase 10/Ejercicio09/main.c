#include <stdio.h>
#include "TAD_empleado.h"

int main(){

    Employee emp1;

    emp1 = crateEmployee();
    updateEmployee(emp1);
    showEmployee(emp1);
    
    deleteEmployee(emp1);
    return 0;
}