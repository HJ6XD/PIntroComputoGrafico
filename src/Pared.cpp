#include "../include/Pared.h"

Pared::Pared(Vector2& c, int h, int w) : Obstacle(c, 0) {
    width = w;
    height = h;
    currentRotation = 0;
    miFigura = new Cuadrado(position, width, height, true, DARKPURPLE);
    isPin = false; isPared = true;
}

Pared::Pared(Vector2& c, int h, int w, int deg) : Obstacle(c, 0) {
    width = w;
    height = h;
    currentRotation = deg;
    miFigura = new Cuadrado(position, width, height, true, DARKPURPLE);
}

void Pared::Start()
{
    miFigura->InitializeFigure();
    if(currentRotation != 0) miFigura->RotateFigure(currentRotation);
}

