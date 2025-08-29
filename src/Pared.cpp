#include "../include/Pared.h"

Pared::Pared(Vector2& c, int h, int w) : Obstacle(c, 0) {
    width = h;
    height = h;
    currentRotation = 0;
    miFigura = new Cuadrado(position, width, height, true, DARKPURPLE);
}

Pared::Pared(Vector2& c, int h, int w, int deg) : Obstacle(c, 0) {
    width = h;
    height = h;
    currentRotation = deg;
    miFigura = new Cuadrado(position, width, height, true, DARKPURPLE);
}

Vector2 Pared::ProvideCenter()
{
    return position;
}

int Pared::ProvideMinX()
{
    return (position.x - (width / 2));
}

int Pared::ProvideMaxX()
{
    return (position.x + (width / 2));
}

int Pared::ProvideMinY()
{
    return (position.y - (height / 2));;
}

int Pared::ProvideMaxY()
{
    return (position.y + (height / 2));;
}

int Pared::provideCurAngle()
{
    return currentRotation;
}

void Pared::Start()
{
base:Start();
    miFigura->RotateFigure(currentRotation);
}

