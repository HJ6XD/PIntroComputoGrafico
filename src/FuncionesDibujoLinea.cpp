#include "../include/FuncionesDibujoLinea.h"

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

void FuncionesDibujoLinea::DibujarCirculoDDA(int X, int Y, int rad)
{
    int curDeg = 0;
    float x1 = X + rad;
    float y1 = Y;
    float x2;
    float y2;
    for (int i = 0; i < 37; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180);
        x2 = X + (cd * rad);
        y2 = Y + (sd * rad);
        DibujarLineaDDA(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        curDeg += 10;
    }
}

void FuncionesDibujoLinea::DibujarCuadradoDDA(int X, int Y, int W, int H)
{
    DibujarLineaDDA(X, Y, X, Y + H);
    DibujarLineaDDA(X, Y, X + W, Y);
    DibujarLineaDDA(X + W, Y, X + W, Y + H);
    DibujarLineaDDA(X, Y + H, X + W, Y + H);
}

void FuncionesDibujoLinea::DibujarTrianguloDDA(int x1, int y1, int x2, int y2, int x3, int y3)
{
    DibujarLineaDDA(x1, y1, x2, y2);
    DibujarLineaDDA(x2, y2, x3, y3);
    DibujarLineaDDA(x3, y3, x1, y1);
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

void FuncionesDibujoLinea::DibujarCirculoBresenham(int X, int Y, int rad)
{
    int curDeg = 0;
    float x1 = X + rad;
    float y1 = Y;
    float x2;
    float y2;
    for (int i = 0; i < 37; i++) {
        float cd = cos((curDeg * PI) / 180);
        float sd = sin((curDeg * PI) / 180);
        x2 = X + (cd * rad);
        y2 = Y + (sd * rad);
        DibujarLineaBresenham(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        curDeg += 10;
    }
}

void FuncionesDibujoLinea::DibujarCuadradoBresenham(int X, int Y, int W, int H)
{
    DibujarLineaBresenham(X, Y, X, Y + H);
    DibujarLineaBresenham(X, Y, X + W, Y);
    DibujarLineaBresenham(X + W, Y, X + W, Y + H);
    DibujarLineaBresenham(X, Y + H, X + W, Y + H);
}

void FuncionesDibujoLinea::DibujarTrianguloBresenham(int x1, int y1, int x2, int y2, int x3, int y3)
{
    DibujarLineaBresenham(x1, y1, x2, y2);
    DibujarLineaBresenham(x2, y2, x3, y3);
    DibujarLineaBresenham(x3, y3, x1, y1);
}


