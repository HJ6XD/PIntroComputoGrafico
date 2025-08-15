#include "../include/Figuras.h"

void Figuras::Draw()
{
    for (int i = 0; i < puntos.size(); i++) {
        DrawPixel(puntos.at(i).x, puntos.at(i).y, color);
    }
}

void Figuras::InitializeFigure()
{
    DrawFigure();
    RasterizeFigure();
}

void Figuras::TranslateFigure(int x, int y)
{

    for (int i = 0; i < puntos.size(); i++) {
        puntos.at(i).x += x;
        puntos.at(i).y += y;
    }
}

void Figuras::RotateFigure(int deg) {
    float coseno = cos((deg * PI) / 180);
    float seno = sin((deg * PI) / 180);

    for (int i = 0; i < puntos.size(); i++) {
        puntos[i].x -= center.x;
        puntos[i].y -= center.y;
        int tx = puntos[i].x;
        int ty = puntos[i].y;
        puntos[i].x = ((tx * coseno) - (ty * seno));
        puntos[i].y = ((tx * seno) + (ty * coseno));

        puntos[i].x += center.x;
        puntos[i].y += center.y;
    }
}

void Figuras::DrawLineDDA(Vector2 p1, Vector2 p2)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = (float)dx / (float)steps;
    float yinc = (float)dy / (float)steps;
    for (int i = 0; i < steps; i++) {
        Vector2 p = { p1.x + (xinc * i), p1.y + (yinc * i) };
        p.x = std::floor(p.x);
        p.y = std::floor(p.y);
        if (CheckIfAlredyOnList(p))
            puntos.push_back(p);
    }
}

void Figuras::DrawLineBresenham(Vector2 p1, Vector2 p2)
{
    p1.x = std::floor(p1.x);
    p1.y = std::floor(p1.y);
    p2.x = std::floor(p2.x);
    p2.y = std::floor(p2.y);

    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    int incyi;
    if (dy >= 0) { incyi = 1; }
    else { dy *= -1; incyi = -1; }
    int incxi;
    if (dx >= 0) { incxi = 1; }
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

    int X = p1.x; int Y = p1.y;
    int avr = 2 * dy;
    int av = avr - dx;
    int avi = av - dx;

    while (X != p2.x || Y != p2.y) {
        float tx = X, ty = Y;
        Vector2 p = { std::floor(tx), std::floor(ty) };

        if(CheckIfAlredyOnList(p))
            puntos.push_back(p);

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

bool Figuras::CheckIfAlredyOnList(Vector2 newpoint)
{
    for (it = puntos.begin(); it != puntos.end(); ++it) {
        Vector2 temp = *it;
        if (temp.x != newpoint.x || temp.y != newpoint.y) continue;

        else return false;
    }
    return true;
}
