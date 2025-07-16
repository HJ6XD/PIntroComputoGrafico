#include <iostream>
#include <raylib.h>
#include "FuncionesDibujoLinea.h"

FuncionesDibujoLinea FDL;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "PIXEL Tierno");

    SetTargetFPS(60);
    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);
        FDL.DibujarLineaCada10(100);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

