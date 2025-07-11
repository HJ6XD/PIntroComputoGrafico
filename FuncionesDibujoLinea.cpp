#include "FuncionesDibujoLinea.h"

void FuncionesDibujoLinea::DibujarLineaDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = (float)dx / (float)steps;
    float yinc = (float)dy / (float)steps;
    for (int i = 0; i < steps; i++) {
        DrawPixel(x1 + (xinc * i), y1 + (yinc * i), BLUE);
    }
}

void FuncionesDibujoLinea::DibujarLineaCada10(int steps)
{
    Vector2 center = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
    int curDeg = 0;
    float x1;
    float y1;
    for (int i = 0; i < 36; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180);
        x1 = center.x + (cd * steps);
        y1 = center.y + (sd * steps);
        DibujarLineaDDA(center.x, center.y, x1, y1);
        curDeg += 10;
    }
}

void FuncionesDibujoLinea::DibujarCirculoDDA(int rad)
{
    Vector2 center = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
    int curDeg = 0;
    float x1 = center.x + rad;
    float y1 = center.y;
    float x2;
    float y2;
    for (int i = 0; i < 9; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180);
        x2 = center.x + (cd * rad);
        y2 = center.y + (sd * rad);
        DibujarLineaDDA(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        curDeg += 45;
    }
}
