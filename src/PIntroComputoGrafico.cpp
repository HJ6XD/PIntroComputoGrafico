#include <iostream>
#include <raylib.h>
#include <vector>
#include "../include/GameObject.h"
#include "../include/Pelota.h"

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Proximo pinball");

    SetTargetFPS(30);

    std::vector<GameObject*>* gameObjects = new std::vector<GameObject*>();

    GameObject* pelota = new Pelota({ 300, 150 });
    pelota->Start();
    gameObjects->push_back(pelota);

    // Main game loop
    while (!WindowShouldClose())
    {
        /*for (int i = 0; i < gameObjects->size(); i++) {
            gameObjects->at(i)->Update();
        }*/
        pelota->Update();
        BeginDrawing();
        ClearBackground(DARKGRAY);

        /*for (int i = 0; i < gameObjects->size(); i++) {
            gameObjects->at(i)->Draw();
        }*/
        pelota->Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

