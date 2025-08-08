#include "../include/Cuadrado.h"

Cuadrado::Cuadrado(Vector2 str, int w, int h) : start(str), width(w), height(h)
{
    puntos = std::vector<Vector2>();
}

void Cuadrado::DrawFigure()
{
    DrawLineDDA(start, {start. x, start.y + height });
    DrawLineDDA(start, { start.x + width, start.y });
    DrawLineDDA({ start.x + width, start.y }, { start.x + width, start.y + height});
    DrawLineDDA({ start.x, start.y + height}, { start.x + width, start.y + height });
}

void Cuadrado::RasterizeFigure()
{
    float xmin = start.x;
    float xmax = start.x + width;
    float ymin = start.y;
    float ymax = start.x + height;
    for (float cy = ymin; cy < ymax; cy++) {
        DrawLineBresenham({ xmin, cy }, { xmax, cy });
    }
}
