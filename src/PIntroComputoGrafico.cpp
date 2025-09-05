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

    Vector2 strartParedPos = { 300, 600 };
    Obstacle* pared = new Pared(strartParedPos, 80, 120, 20);
    pared->Start();
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

        Vector2 ndir = detectorDeColision.CheckCollisionWithPared(pared);
            if (ndir.y != 0 || ndir.x != 0)
            pelota->Rebotar(ndir);

        /*for (int i = 0; i < gameObjects->size(); i++) {
            gameObjects->at(i)->Draw();
        }*/
        pelota->Draw();
        pared->Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

