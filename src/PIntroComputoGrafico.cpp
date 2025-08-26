#include <iostream>
#include <raylib.h>
#include <vector>
#include "../include/GameObject.h"
#include "../include/Pelota.h"
#include "../include/Pin.h"
#include "../include/CollisionDetector.h"

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Proximo pinball");

    SetTargetFPS(30);

    std::vector<GameObject*>* gameObjects = new std::vector<GameObject*>();

    Pelota* pelota = new Pelota({ 300, 150 });
    pelota->Start();

    Pin* pin = new Pin({ 300, 400 }, 50, BLUE);
    pin->Start();

    CollisionDetector detectorDeColision = CollisionDetector(pelota);
    // Main game loop
    while (!WindowShouldClose())
    {
        /*for (int i = 0; i < gameObjects->size(); i++) {
            gameObjects->at(i)->Update();
        }*/
        pelota->Update();
        BeginDrawing();
        ClearBackground(DARKGRAY);

        if (detectorDeColision.CheckCollisionWithPin(pin))
            pelota->Rebotar();

        /*for (int i = 0; i < gameObjects->size(); i++) {
            gameObjects->at(i)->Draw();
        }*/
        pelota->Draw();
        pin->Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

