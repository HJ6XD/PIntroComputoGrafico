#pragma once
#include "Figuras.h"
class Triangulo :
    public Figuras
{
public:
    int height, width;
    Triangulo(Vector2 c, int w, int h, bool isD, Color col);
    void DrawFigure() override;
    void RasterizeFigure() override;

};

