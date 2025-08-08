#include <iostream>
#include <raylib.h>
#include "../include/FuncionesDibujoLinea.h"
#include "../include/Circulo.h"
#include "../include/Cuadrado.h"
#include "../include/Triangulo.h"
#include <vector>

FuncionesDibujoLinea FDL;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Proximo pinball");

    SetTargetFPS(60);
    // Main game loop
    Cuadrado* cuadradoD = new Cuadrado({ 250,50 }, 100, 100, DARKPURPLE);
    cuadradoD->RasterizeFigureD();

    Triangulo* trianguloD = new Triangulo({ 50,150 }, { 100,50 }, { 150,150}, BLUE);
    trianguloD->DrawFigureD();
    trianguloD->RasterizeFigureD();

    Circulo* circuloD = new Circulo({ 500,100 }, 50, DARKBLUE);
    circuloD->DrawFigureD();
    circuloD->RasterizeFigureD();

    Cuadrado* cuadradoB = new Cuadrado({ 250,300 }, 100, 100, ORANGE);
    cuadradoB->RasterizeFigureB();
    Triangulo* trianguloB = new Triangulo({ 50,400 }, { 100,300 }, { 150,400 }, RED);
    trianguloB->DrawFigureB();
    trianguloB->RasterizeFigureB();

    Circulo* circuloB = new Circulo({ 500,350 }, 50, YELLOW);
    circuloB->DrawFigureB();
    circuloB->RasterizeFigureB();

    std::vector<Figuras*>* figuras = new std::vector<Figuras*>();
    figuras->push_back(cuadradoD);
    figuras->push_back(trianguloD);
    figuras->push_back(circuloD);
    figuras->push_back(cuadradoB);
    figuras->push_back(trianguloB);
    figuras->push_back(circuloB);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        FDL.DibujarCirculoBresenham(500, 350, 50);
        cuadradoB->TranslateFigure(1,-1);

        for (int i = 0; i < figuras->size(); i++) {
            figuras->at(i)->Draw();
        }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

