#include <stdio.h>

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco de %c a %c\n", origen, destino);
    } else {
        hanoi(n - 1, origen, auxiliar, destino);
        printf("Mover disco de %c a %c\n", origen, destino);
        hanoi(n - 1, auxiliar, destino, origen);
    }
}

int main() {
    int num_discos = 3;
    hanoi(num_discos, 'A', 'C', 'B');
    return 0;
}
