#ifndef EMPLEADO_H
#define EMPLEADO_H
#define MAX_CAD 50


typedef char tcad[MAX_CAD];


typedef struct {
    tcad name;
    long dni;
    long dateStart;
    char turn;
} Employee;

Employee crateEmployee();
void updateEmployee(Employee e);
void showEmployee(Employee e);
void deleteEmployee(Employee e);
#endif