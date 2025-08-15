#include "../include/Cuadrado.h"

Cuadrado::Cuadrado(Vector2 str, int w, int h, bool isD, Color c) : start(str), width(w), height(h)
{
    puntos = std::vector<Vector2>();
    color = c;
    center = { start.x + width / 2, start.y + height / 2 };
    isDDA = isD;
    isBresenham = !isD;
}

void Cuadrado::DrawFigure()
{
    if(isDDA){
        DrawLineDDA(start, { start.x, start.y + height });
        DrawLineDDA(start, { start.x + width, start.y });
        DrawLineDDA({ start.x + width, start.y }, { start.x + width, start.y + height });
        DrawLineDDA({ start.x, start.y + height }, { start.x + width, start.y + height });
    }
    else if(isBresenham){
        DrawLineBresenham(start, { start.x, start.y + height });
        DrawLineBresenham(start, { start.x + width, start.y });
        DrawLineBresenham({ start.x + width, start.y }, { start.x + width, start.y + height });
        DrawLineBresenham({ start.x, start.y + height }, { start.x + width, start.y + height });
    }
}

void Cuadrado::RasterizeFigure()
{
    float xmin = start.x;
    float xmax = start.x + width;
    float ymin = start.y;
    float ymax = start.y + height;
    for (float cy = ymin; cy <= ymax; cy++) {
        if(isDDA)
            DrawLineDDA({ xmin, cy }, { xmax, cy });

        else if(isBresenham)
            DrawLineBresenham({ xmin, cy }, { xmax, cy });
    }
}