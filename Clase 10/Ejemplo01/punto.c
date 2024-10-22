#include "punto.h"
#include <math.h>

Punto crearPunto(float x, float y) {
    Punto p = {x, y};
    return p;
}

float distancia(Punto p1, Punto p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
