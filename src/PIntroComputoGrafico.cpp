#include <iostream>
#include <raylib.h>
#include "../include/FuncionesDibujoLinea.h"
#include "../include/Circulo.h"
#include "../include/Cuadrado.h"
#include "../include/Triangulo.h"

FuncionesDibujoLinea FDL;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Proximo pinball");

    SetTargetFPS(60);
    // Main game loop

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        //Dibujar Circulo de lineas
        /*FDL.DibujarLineaCada10Bresenham(250,225,100);
        FDL.DibujarLineaCada10DDA(550, 225, 100);*/

        ////Dibujar Circulos
        //FDL.DibujarCirculoDDA(100, 100, 60);
        //FDL.DibujarCirculoBresenham(100, 300, 60);

        ////Dinujar Cuadrados
        //FDL.DibujarCuadradoDDA(240, 40, 120, 120);
        //FDL.DibujarCuadradoBresenham(240, 240, 120, 120);
        //
        ////Dibujar triangulos
        //FDL.DibujarTrianguloDDA(440,160,500,40,560,160);
        //FDL.DibujarTrianguloBresenham(440, 360, 500, 240, 560, 360);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

