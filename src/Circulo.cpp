#include "../include/Circulo.h"

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
        DrawLineDDA(p1, p2);
        p1.x = p2.x;
        p1.y = p2.y;
        curDeg += 10;
    }
}

void Circulo::RasterizeFigure()
{
    for (float cy = center.y; cy < center.y + radius; cy++) {
        for (int cx = 0; cx < radius; cx++) {
            DrawLineDDA({ center.x - radius + cx, cy }, { center.x + radius - cx, cy });
        }
    }
    for (float cy = center.y; cy > center.y - radius; cy--) {
        for (int cx = 0; cx < radius; cx++) {
            DrawLineDDA({ center.x - radius + cx, cy }, { center.x + radius - cx, cy });
        }
    }
}
