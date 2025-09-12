#pragma once
#include "Figuras.h"

class Circulo :
    public Figuras
{
public:
    int radius;

    Circulo(Vector2 c, int r, bool isD, Color co);

    void DrawFigure() override;
    void RasterizeFigure() override;

};

