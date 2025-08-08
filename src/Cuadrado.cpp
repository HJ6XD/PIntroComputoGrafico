#include "../include/Cuadrado.h"

Cuadrado::Cuadrado(Vector2 str, int w, int h, Color c) : start(str), width(w), height(h)
{
    puntos = std::vector<Vector2>();
    color = c;
}

void Cuadrado::DrawFigureD()
{
    DrawLineDDA(start, {start. x, start.y + height });
    DrawLineDDA(start, { start.x + width, start.y });
    DrawLineDDA({ start.x + width, start.y }, { start.x + width, start.y + height});
    DrawLineDDA({ start.x, start.y + height}, { start.x + width, start.y + height });
}

void Cuadrado::RasterizeFigureD()
{
    float xmin = start.x;
    float xmax = start.x + width;
    float ymin = start.y;
    float ymax = start.y + height;
    for (float cy = ymin; cy <= ymax; cy++) {
        DrawLineDDA({ xmin, cy }, { xmax, cy });
    }
}

void Cuadrado::DrawFigureB()
{
    DrawLineBresenham(start, { start.x, start.y + height });
    DrawLineBresenham(start, { start.x + width, start.y });
    DrawLineBresenham({ start.x + width, start.y }, { start.x + width, start.y + height });
    DrawLineBresenham({ start.x, start.y + height }, { start.x + width, start.y + height });
}

void Cuadrado::RasterizeFigureB()
{
    float xmin = start.x;
    float xmax = start.x + width;
    float ymin = start.y;
    float ymax = start.y + height;
    for (float cy = ymin; cy <= ymax; cy++) {
        DrawLineBresenham({ xmin, cy }, { xmax, cy });
    }
}
