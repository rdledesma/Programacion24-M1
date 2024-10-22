#ifndef PUNTO_H
#define PUNTO_H

typedef struct {
    float x;
    float y;
} Punto;

Punto crearPunto(float x, float y);
float distancia(Punto p1, Punto p2);

#endif
