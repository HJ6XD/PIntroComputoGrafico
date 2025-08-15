#include "../include/Triangulo.h"



Triangulo::Triangulo(Vector2 c, int w, int h, bool isD, Color col) : height(h), width(w)
{
    puntos.clear();
    puntos = std::vector<Vector2>();
    color = col;
    center = c;

    isDDA = isD;
    isBresenham = !isD;
}

void Triangulo::DrawFigure()
{ 
    Vector2 vertex1, vertex2, vertex3;
    vertex1 = { center.x - width / 2 , center.y + height / 2 };
    vertex2 = { center.x, center.y - height / 2 };
    vertex3 = { center.x + width / 2 , center.y + height / 2 };

    if (isDDA) {
        DrawLineDDA(vertex1, vertex2);
        DrawLineDDA(vertex2, vertex3);
        DrawLineDDA(vertex3, vertex1);
    }
    else if (isBresenham) {
        DrawLineBresenham(vertex1, vertex2);
        DrawLineBresenham(vertex2, vertex3);
        DrawLineBresenham(vertex3, vertex1);
    }
}

void Triangulo::RasterizeFigure()
{
    float xmin, xmax, ymin, ymax;
    xmin = center.x - width / 2;
    ymin = center.y - height / 2;
    xmax = center.x + width / 2;
    ymax = center.y + height / 2;

    for (float cy = ymin; cy < ymax; cy++) {
        float curx1 = -1, curx2 = -1;
        for (it = puntos.begin(); it != puntos.end(); ++it) {
            Vector2 temp = *it;
            if (temp.y != cy) continue;

            if (curx1 == -1) curx1 = temp.x;
            else {
                curx2 = temp.x;
                if (isDDA)
                    DrawLineDDA({ curx1, cy }, { curx2,cy });
                else
                    DrawLineBresenham({ curx1, cy }, { curx2,cy });

                curx1 = -1; curx2 = -1;
                break;
            }
        }
    }
}