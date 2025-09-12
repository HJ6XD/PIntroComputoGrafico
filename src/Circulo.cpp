#include "../include/Circulo.h"

Circulo::Circulo(Vector2 c, int r, bool isD, Color co) : Figuras(c) {
    puntos = std::vector<Vector2>();
    color = co;
    isDDA = isD;
    isBresenham = !isD;
    radius = r;
}

void Circulo::DrawFigure()
{
    int curDeg = 0;
    Vector2 p1 = { center.x + radius, center.y };
    Vector2 p2;
    for (int i = 0; i < 37; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180); 
        p2.x = center.x + (cd * radius);
        p2.y = center.y + (sd * radius);
        if (isDDA)
            DrawLineDDA(p1, p2);
        else if (isBresenham)
            DrawLineBresenham(p1, p2);

        p1.x = p2.x;
        p1.y = p2.y;
        curDeg += 10;
    }
}

void Circulo::RasterizeFigure()
{
    float cx = radius;
    for (float cy = center.y; cy < center.y + radius; cy++) {
        for (it = puntos.begin(); it != puntos.end(); ++it) {
            Vector2 temp = *it;
            if (temp.y != cy) continue;

            cx -= (cx - (temp.x - center.x));
            break;
        }
        if(isDDA)
            DrawLineDDA({ center.x - cx, cy } , { center.x + cx, cy });
        else if(isBresenham)
            DrawLineBresenham({ center.x - cx, cy }, { center.x + cx, cy });

    }
    cx = radius;
    for (float cy = center.y; cy > center.y - radius; cy--) {
        for (it = puntos.begin(); it != puntos.end(); ++it) {
            Vector2 temp = *it;
            if (temp.y != cy) continue;

            cx -= (cx - (temp.x - center.x));
            break;
        }
        if (isDDA)
            DrawLineDDA({ center.x - cx, cy }, { center.x + cx, cy });
        else if (isBresenham)
            DrawLineBresenham({ center.x - cx, cy }, { center.x + cx, cy });
    }
}

