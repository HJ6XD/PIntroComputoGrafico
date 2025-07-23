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

void FuncionesDibujoLinea::DibujarLineaCada10DDA(int X, int Y, int steps)
{
    int curDeg = 0;
    float x1;
    float y1;
    for (int i = 0; i < 36; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180);
        x1 = X + (cd * steps);
        y1 = Y + (sd * steps);
        DibujarLineaDDA(X, Y, x1, y1);
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

void FuncionesDibujoLinea::DibujarLineaBresenham(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int incyi;
    if (dy >= 0){ incyi = 1; }
    else { dy *= -1; incyi = -1; }
    int incxi;
    if (dx >= 0){ incxi = 1; }
    else { dx *= -1; incxi = -1; }

    int incyr, incxr;
    if (dx >= dy) {
        incyr = 0;
        incxr = incxi;
    }
    else {
        incyr = incyi;
        incxr = 0;
        int k = dx; dx = dy; dy = k;
    }

    int X = x1; int Y = y1;
    int avr = 2 * dy;
    int av = avr - dx;
    int avi = av - dx;
    
    while (X != x2 || Y != y2) {
        DrawPixel(X, Y, GOLD);

        if (av >= 0) {
            X += incxi;
            Y += incyi;
            av += avi;
        }
        else {
            X += incxr;
            Y += incyr;
            av += avr;
        }
    }    
}

void FuncionesDibujoLinea::DibujarLineaCada10Bresenham(int X, int Y, int rad) {
    int curDeg = 0;
    float x1;
    float y1;
    for (int i = 0; i < 36; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180);
        x1 = X + (cd * rad);
        y1 = Y + (sd * rad);
        DibujarLineaBresenham(X, Y, x1, y1);
        curDeg += 10;
    }
}
