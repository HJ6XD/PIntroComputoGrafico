#pragma once
#include "Figuras.h"

class Cuadrado :
    public Figuras
{
public:
    int width, height;

    Cuadrado(Vector2 str, int w, int h, bool isD, Color c);
    void DrawFigure() override;
    void RasterizeFigure() override;
    void MoveCenter(Vector2) override;
};

