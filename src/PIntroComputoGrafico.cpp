#include <iostream>
#include <raylib.h>
#include <vector>
#include "../include/GameObject.h"
#include "../include/Pelota.h"
#include "../include/Pin.h"
#include "../include/CollisionDetector.h"
std::vector<Obstacle*>* obstaculos = new std::vector<Obstacle*>();

void CrearMapa() {
    Vector2 obpos1 = { 550, 450 };
    Obstacle* paredDerecha = new Pared(obpos1, 800, 30);
    paredDerecha->Start();
    obstaculos->push_back(paredDerecha);

    Vector2 obpos2 = { 50, 450 };
    Obstacle* paredIzquierda = new Pared(obpos2, 800, 30);
    paredIzquierda->Start();
    obstaculos->push_back(paredIzquierda);

    Vector2 obpos3 = { 130, 880 };
    Obstacle* abajoIzquierda = new Pared(obpos3, 30, 170, 30);
    abajoIzquierda->Start();
    obstaculos->push_back(abajoIzquierda);

    Vector2 obpos4 = { 470, 880 };
    Obstacle* abajoDerecha = new Pared(obpos4, 30, 170, -30);
    abajoDerecha->Start();
    obstaculos->push_back(abajoDerecha);
    
    Vector2 obpos5 = { 400, 950 };
    Obstacle* hastaAbajoI = new Pared(obpos5, 80, 30);
    hastaAbajoI->Start();
    obstaculos->push_back(hastaAbajoI);
    
    Vector2 obpos6 = { 200, 950 };
    Obstacle* hastaAbajoD = new Pared(obpos6, 80, 30);
    hastaAbajoD->Start();
    obstaculos->push_back(hastaAbajoD);

    Vector2 obpos7 = { 180, 820 };
    Obstacle* muerteAI = new Pared(obpos7, 20, 120, 30);
    muerteAI->Start();
    obstaculos->push_back(muerteAI);

    Vector2 obpos8 = { 420, 820 };
    Obstacle* muerteAD = new Pared(obpos8, 20, 120, -30);
    muerteAD->Start();
    obstaculos->push_back(muerteAD);
    
    Vector2 obpos9 = { 130, 700 };
    Obstacle* muerteEI = new Pared(obpos9, 200, 20);
    muerteEI->Start();
    obstaculos->push_back(muerteEI);

    Vector2 obpos10 = { 470, 700 };
    Obstacle* muerteED = new Pared(obpos10, 200, 20);
    muerteED->Start();
    obstaculos->push_back(muerteED);

    //Creacion de los pines
    /*for (int i = 0; i < 10; i++) {
        int randYPos = GetRandomValue(100, 550);
        int randXPos = GetRandomValue(110, 490);
        int randRad = GetRandomValue(5, 15);

        Vector2 randomPos = { randXPos, randYPos };
        Obstacle* circ = new Pin(randomPos, randRad, 12, RAYWHITE);
        circ->Start();
        obstaculos->push_back(circ);
    }*/
}

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Proximo pinball");

    SetTargetFPS(30);

    Vector2 pelotaPos = { 510, 150 };
    Pelota* pelota = new Pelota(pelotaPos);
    pelota->Start();

    CollisionDetector detectorDeColision = CollisionDetector(pelota);

    //Creacion del mapa
    CrearMapa();

    // Main game loop
    while (!WindowShouldClose())
    {
        for (int i = 0; i < obstaculos->size(); i++) {
            obstaculos->at(i)->Update();
        }
        pelota->Update();

        for (int i = 0; i < obstaculos->size(); i++) {
            Vector2 ndir;
            ndir = detectorDeColision.CheckCollisionWithPared(obstaculos->at(i));
            if (ndir.x != 0 || ndir.y != 0)
                pelota->Rebotar(ndir);
            /*if (obstaculos->at(i)->isPin == true) {
                ndir = detectorDeColision.CheckCollisionWithPin(obstaculos->at(i));
                if (ndir.x != 0 || ndir.y != 0)
                    pelota->Rebotar(ndir);
            }
            else if (obstaculos->at(i)->isPared == true) {
                ndir = detectorDeColision.CheckCollisionWithPared(obstaculos->at(i));
                if (ndir.x != 0 || ndir.y != 0)
                    pelota->Rebotar(ndir);
            }*/
        }

        BeginDrawing();
        ClearBackground(DARKGRAY);


        for (int i = 0; i < obstaculos->size(); i++) {
            obstaculos->at(i)->Draw();
        }
        pelota->Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

