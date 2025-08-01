#include "../include/Figuras.h"

void Figuras::Draw()
{
    for (int i = 0; i < puntos.size(); i++) {
        DrawPixel(puntos.at(i).x, puntos.at(i).y, RAYWHITE);
    }
}

void Figuras::DrawLineDDA(Vector2 p1, Vector2 p2)
{
    /*puntos.push_back(p1);
    puntos.push_back(p2);*/ 
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = (float)dx / (float)steps;
    float yinc = (float)dy / (float)steps;
    for (int i = 0; i < steps; i++) {
        DrawPixel(p1.x + (xinc * i), p1.y + (yinc * i), BLUE);
        Vector2 p = { p1.x + (xinc * i), p1.y + (yinc * i) };
        p.x = std::floor(p.x);
        p.y = std::floor(p.y);
        puntos.push_back(p);
    }
}
