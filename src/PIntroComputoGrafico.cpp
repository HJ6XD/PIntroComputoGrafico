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

    Vector2 pelotaPos = { 310, 150 };
    Pelota* pelota = new Pelota(pelotaPos);
    pelota->Start();

    Vector2 strartPinPos = { 300, 450 };
    Pin* pin = new Pin(strartPinPos, 50, 200, BLUE);
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

        Vector2 ndir = detectorDeColision.CheckCollisionWithPin(pin);
            if (ndir.y != 0 || ndir.x != 0)
            pelota->Rebotar(ndir);

        /*for (int i = 0; i < gameObjects->size(); i++) {
            gameObjects->at(i)->Draw();
        }*/
        pelota->Draw();
        pin->Draw();
        DrawLine(0, 400, 600, 400, GOLD);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

