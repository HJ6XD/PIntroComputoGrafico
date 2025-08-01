#include "../include/Triangulo.h"


Triangulo::Triangulo(Vector2 v1, Vector2 v2, Vector2 v3) : vertex1(v1), vertex2(v2), vertex3(v3)
{
    puntos = std::vector<Vector2>();

}

void Triangulo::DrawFigure()
{
    DrawLineDDA(vertex1, vertex2);
    DrawLineDDA(vertex2, vertex3);
    DrawLineDDA(vertex3, vertex1);
}

void Triangulo::RasterizeFigure()
{
    float xmin, xmax, ymin, ymax;
    xmin = std::min(vertex1.x, vertex2.x);
    xmin = std::min(xmin, vertex3.x);

    ymin = std::min(vertex1.y, vertex2.y);
    ymin = std::min(ymin, vertex3.y);

    xmax = std::max(vertex1.x, vertex2.x);
    xmax = std::max(xmax, vertex3.x);

    ymax = std::max(vertex1.y, vertex2.y);
    ymax = std::max(ymax, vertex3.y);

    for (float cy = ymin; cy < ymax; cy++) {
        float curx1 = -1, curx2 = -1;
        for (it = puntos.begin(); it != puntos.end(); ++it) {
            Vector2 temp = *it;
            if (temp.y != cy) continue;

            if (curx1 == -1) curx1 = temp.x;
            else {
                curx2 = temp.x;
                DrawLineDDA({ curx1, cy }, { curx2,cy });
                curx1 = -1; curx2 = -1;
                break;
            }
        }
    }
}
