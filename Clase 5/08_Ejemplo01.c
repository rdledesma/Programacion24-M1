/*Enunciado 1: Gestión de un Sistema Bancario

Un sistema bancario necesita gestionar el saldo de múltiples cuentas. 
Los clientes pueden realizar operaciones de depósito o retiro en sus cuentas. 
El sistema debe validar que el retiro no exceda el saldo actual. 
El programa debe permitir que un cliente consulte su saldo 
y realice operaciones de depósito o retiro. 
Si se realiza un retiro, el saldo de la cuenta debe ser actualizado de forma correcta.
Se pide:
Crear un procedimiento que permita depositar dinero en la cuenta.
Crear un procedimiento que permita retirar dinero de la cuenta (validando que no se exceda el saldo).
Ambos procedimientos deben recibir como parámetro la dirección del saldo para poder modificarlo.
*/

#include <stdio.h>

// Procedimiento para depositar dinero
void depositar(float *saldo, float cantidad) {
    *saldo += cantidad;  // Sumar la cantidad al saldo
}

// Procedimiento para retirar dinero (con validación)
void retirar(float *saldo, float cantidad) {
    if (*saldo >= cantidad) {
        *saldo -= cantidad;  // Restar la cantidad del saldo
        printf("Retiro exitoso de %.2f\n", cantidad);
    } else {
        printf("Saldo insuficiente para retirar %.2f\n", cantidad);
    }
}

int main() {
    float saldo = 1000.0;
    printf("Saldo inicial: %.2f\n", saldo);

    depositar(&saldo, 200.0);  // Depositar 200
    printf("Saldo después del depósito: %.2f\n", saldo);

    retirar(&saldo, 150.0);    // Retirar 150
    printf("Saldo después del retiro: %.2f\n", saldo);

    retirar(&saldo, 1200.0);   // Intentar retirar más del saldo disponible
    printf("Saldo final: %.2f\n", saldo);

    return 0;
}
