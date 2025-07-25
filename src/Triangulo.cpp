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
