#pragma once
#include "Figuras.h"

class Cuadrado :
    public Figuras
{
public:
    Vector2 start;
    int width, height;

    Cuadrado(Vector2 str, int w, int h, Color c);
    void DrawFigureD() override;
    void RasterizeFigureD() override;
    void DrawFigureB() override;
    void RasterizeFigureB() override;

};

