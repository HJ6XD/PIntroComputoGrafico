#pragma once
#include "Figuras.h"

class Circulo :
    public Figuras
{
public:
    Vector2 center;
    int radius;

    Circulo(Vector2 c, int r, Color co);

    void DrawFigureD() override;
    void RasterizeFigureD() override;
    void DrawFigureB() override;
    void RasterizeFigureB() override;
};

