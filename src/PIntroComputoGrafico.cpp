#include <iostream>
#include <raylib.h>
#include <vector>
#include "../include/GameObject.h"
#include "../include/Pelota.h"
#include "../include/Pin.h"
#include "../include/CollisionDetector.h"
#include "../include/PelotaSpawner.h"
#include "../include/PaddleIzquierda.h"
#include "../include/PaddleDerecha.h"
#include "../include/Triangulo.h"
#include <algorithm>
std::vector<Obstacle*>* obstaculos = new std::vector<Obstacle*>();

void CrearMapa() {
    Obstacle* paredDerecha = new Pared({ 550, 500 }, 700, 40);
    paredDerecha->Start();
    obstaculos->push_back(paredDerecha);

    Obstacle* paredIzquierda = new Pared({ 50, 500 }, 700, 40);
    paredIzquierda->Start();
    obstaculos->push_back(paredIzquierda);

    Obstacle* abajoIzquierda = new Pared({ 130, 880 }, 40, 170, 30);
    abajoIzquierda->Start();
    obstaculos->push_back(abajoIzquierda);

    Obstacle* abajoDerecha = new Pared({ 470, 880 }, 40, 170, -30);
    abajoDerecha->Start();
    obstaculos->push_back(abajoDerecha);
    
    Obstacle* hastaAbajoI = new Pared({ 400, 950 }, 80, 40);
    hastaAbajoI->Start();
    obstaculos->push_back(hastaAbajoI);
    
    Obstacle* hastaAbajoD = new Pared({ 200, 950 }, 80, 40);
    hastaAbajoD->Start();
    obstaculos->push_back(hastaAbajoD);

    Obstacle* muerteAI = new Pared({ 180, 820 }, 30, 120, 30);
    muerteAI->Start();
    obstaculos->push_back(muerteAI);

    Obstacle* muerteAD = new Pared({ 420, 820 }, 30, 120, -30);
    muerteAD->Start();
    obstaculos->push_back(muerteAD);
    
    Obstacle* muerteEI = new Pared({ 130, 700 }, 200, 30);
    muerteEI->Start();
    obstaculos->push_back(muerteEI);

    Obstacle* muerteED = new Pared({ 470, 700 }, 200, 30);
    muerteED->Start();
    obstaculos->push_back(muerteED);
    
    Obstacle* techoI = new Pared({ 180, 90 }, 40, 300, -30);
    techoI->Start();
    obstaculos->push_back(techoI);

    Obstacle* techoD = new Pared({ 420, 90 }, 40, 300, 30);
    techoD->Start();
    obstaculos->push_back(techoD);

    //Creacion de los pines
    for (int i = 0; i < 4; i++) {
        int ypos = 250 + i * 75;
        int rad = 4 + 4 * i;
        for (int j = 0; j < 6; j++) {
            int xpos = 120 + j * 70;
            Vector2 pos = { xpos, ypos };
            Obstacle* cpin = new Pin(pos, rad, 1, RAYWHITE);
            cpin->Start();
            obstaculos->push_back(cpin);
        }
    }
}

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Proximo pinball");

    SetTargetFPS(30);

    PelotaSpawner* spawner = new PelotaSpawner({300,750});

    Pelota* pelota = spawner->providePelota();

    CollisionDetector detectorDeColision = CollisionDetector(pelota);

    PaddleIzquierda* padIzq = new PaddleIzquierda({250, 850}, 50, 20);
    padIzq->Start();
    obstaculos->push_back(padIzq);
    PaddleDerecha* padDer = new PaddleDerecha({ 350,850 }, 50, 20);
    padDer->Start();
    obstaculos->push_back(padDer);
    //Creacion del mapa
    CrearMapa();

   //Decoración
    Triangulo* tri1 = new Triangulo({300, 50}, 50,50, true, YELLOW);
    tri1->InitializeFigure();
    Triangulo* tri2 = new Triangulo({275, 100}, 50,50, true, YELLOW);
    tri2->InitializeFigure();
    Triangulo* tri3 = new Triangulo({325, 100}, 50,50, true, YELLOW);
    tri3->InitializeFigure();
    while (!WindowShouldClose())
    {
        spawner->Update();
        padIzq->Update();
        padDer->Update();
        if (pelota->CheckActive()) {
            pelota->Update();          
            
            for (int i = 0; i < obstaculos->size(); i++) {
                Vector2 ndir;
                if (obstaculos->at(i)->isPin == true) {
                    ndir = detectorDeColision.CheckCollisionWithPin(obstaculos->at(i));
                    if (ndir.x != 0 || ndir.y != 0)
                        pelota->Rebotar(ndir);
                }
                else if (obstaculos->at(i)->isPared == true) {
                    ndir = detectorDeColision.CheckCollisionWithPared(obstaculos->at(i));
                    if (ndir.x != 0 || ndir.y != 0)
                        pelota->Rebotar(ndir);
                }
            }
        }
        
        BeginDrawing();
        ClearBackground(DARKGRAY);


        for (int i = 0; i < obstaculos->size(); i++) {
            obstaculos->at(i)->Draw();
        }
        tri1->Draw();
        tri2->Draw();
        tri3->Draw();
        pelota->Draw();
        padDer->Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

