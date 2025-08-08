#include "../include/Circulo.h"

Circulo::Circulo(Vector2 c, int r, Color co) : center(c), radius(r) {
    puntos = std::vector<Vector2>();
    color = co;
}

void Circulo::DrawFigureD()
{
    int curDeg = 0;
    Vector2 p1 = { center.x + radius, center.y };
    Vector2 p2;
    for (int i = 0; i < 37; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180); 
        p2.x = center.x + (cd * radius);
        p2.y = center.y + (sd * radius);

        DrawLineDDA(p1, p2);

        p1.x = p2.x;
        p1.y = p2.y;
        curDeg += 10;
    }
}

void Circulo::RasterizeFigureD()
{
    float cx = radius;
    for (float cy = center.y; cy < center.y + radius; cy++) {
        for (it = puntos.begin(); it != puntos.end(); ++it) {
            Vector2 temp = *it;
            if (temp.y != cy) continue;

            cx -= (cx - (temp.x - center.x));
            break;
        }
        DrawLineDDA({ center.x - cx, cy } , { center.x + cx, cy });
    }
    cx = radius;
    for (float cy = center.y; cy > center.y - radius; cy--) {
        for (it = puntos.begin(); it != puntos.end(); ++it) {
            Vector2 temp = *it;
            if (temp.y != cy) continue;

            cx -= (cx - (temp.x - center.x));
            break;
        }
        DrawLineDDA({ center.x - cx, cy }, { center.x + cx, cy });
    }
}

void Circulo::DrawFigureB()
{
    int curDeg = 0;
    Vector2 p1 = { center.x + radius, center.y };
    Vector2 p2;
    for (int i = 0; i < 37; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180);
        p2.x = center.x + (cd * radius);
        p2.y = center.y + (sd * radius);

        DrawLineBresenham(p1, p2);

        p1.x = p2.x;
        p1.y = p2.y;
        curDeg += 10;
    }
}

void Circulo::RasterizeFigureB()
{
    float cx = radius;
    for (float cy = center.y; cy < center.y + radius; cy++) {
        for (it = puntos.begin(); it != puntos.end(); ++it) {
            Vector2 temp = *it;
            if (temp.y != cy) continue;

            cx -= (cx - (temp.x - center.x));
            break;
        }
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
        DrawLineBresenham({ center.x - cx, cy }, { center.x + cx, cy });
    }
}
