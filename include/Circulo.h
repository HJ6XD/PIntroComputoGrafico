#pragma once
#include "Figuras.h"

class Circulo :
    public Figuras
{
public:
    Vector2 center;
    int radius;

    Circulo(Vector2 c, int r) : center(c), radius(r) {
        puntos = std::vector<Vector2>();
    }

    void DrawFigure() override;
};

