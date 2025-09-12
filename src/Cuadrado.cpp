#include "../include/Cuadrado.h"

Cuadrado::Cuadrado(Vector2 cen, int w, int h, bool isD, Color c) : Figuras(cen)
{
    width = w;
    height = h;
    puntos = std::vector<Vector2>();
    color = c;
    center = cen;
    isDDA = isD;
    isBresenham = !isD;
}

void Cuadrado::DrawFigure()
{
    if(isDDA){
        DrawLineDDA({ center.x - width / 2, center.y - height / 2 }, { center.x + width / 2, center.y - height / 2 });
        DrawLineDDA({ center.x - width / 2, center.y - height / 2 }, { center.x - width / 2, center.y + height / 2 });
        DrawLineDDA({ center.x - width / 2, center.y + height / 2 }, { center.x + width / 2, center.y + height / 2 });
        DrawLineDDA({ center.x + width / 2, center.y - height / 2 }, { center.x + width / 2, center.y + height / 2 });
    }
    else if(isBresenham){
        DrawLineBresenham({ center.x - width / 2, center.y - height / 2 }, { center.x + width / 2, center.y - height / 2 });
        DrawLineBresenham({ center.x - width / 2, center.y - height / 2 }, { center.x - width / 2, center.y + height / 2 });
        DrawLineBresenham({ center.x - width / 2, center.y + height / 2 }, { center.x + width / 2, center.y + height / 2 });
        DrawLineBresenham({ center.x + width / 2, center.y - height / 2 }, { center.x + width / 2, center.y + height / 2 });
    }
}

void Cuadrado::RasterizeFigure()
{
    float xmin = center.x - width / 2;
    float xmax = center.x + width / 2;
    float ymin = center.y - height / 2;
    float ymax = center.y + height / 2;
    for (float cy = ymin; cy <= ymax; cy++) {
        if(isDDA)
            DrawLineDDA({ xmin, cy }, { xmax, cy });

        else if(isBresenham)
            DrawLineBresenham({ xmin, cy }, { xmax, cy });
    }
}

void Cuadrado::MoveCenter(Vector2 newCenter)
{
    center = newCenter;
}
