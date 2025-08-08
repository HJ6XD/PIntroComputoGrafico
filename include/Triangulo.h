#pragma once
#include "Figuras.h"
class Triangulo :
    public Figuras
{
public:
    Vector2 vertex1;
    Vector2 vertex2;
    Vector2 vertex3;

    Triangulo(Vector2 v1, Vector2 v2, Vector2 v3, Color c);
    void DrawFigureD() override;
    void RasterizeFigureD() override;
    void DrawFigureB() override;
    void RasterizeFigureB() override;

};

