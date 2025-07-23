#include <iostream>
#include <raylib.h>
#include "FuncionesDibujoLinea.h"

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
        FDL.DibujarLineaCada10Bresenham(250,225,100);  
        FDL.DibujarLineaCada10DDA(550, 225, 100);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

