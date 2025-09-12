#include "../include/PaddleDerecha.h"

PaddleDerecha::PaddleDerecha(Vector2 pos, int w, int h) : Obstacle(pos, 1)
{
	width = w;
	height = h;
	currentRotation = -30;
	rotationSpeed = 90;
	miFigura = new Cuadrado(position, width, height, false, GOLD);
	isPared = true;
	lastRot = currentRotation;
}

void PaddleDerecha::Start()
{
	miFigura->InitializeFigure();
	Vector2 nCenter = { position.x + width / 2 - height / 2, position.y };
	miFigura->MoveCenter(nCenter);
	miFigura->RotateFigure(currentRotation);
}

void PaddleDerecha::Update() {
    float newRotation = currentRotation;

    if (IsKeyDown(KEY_D)) {
        if (newRotation < MAX_ROT) {
            newRotation += rotationSpeed * GetFrameTime();
            if (newRotation > MAX_ROT) newRotation = MAX_ROT;
        }
    }
    else {
        if (newRotation > MIN_ROT) {
            newRotation -= rotationSpeed * GetFrameTime();
            if (newRotation < MIN_ROT) newRotation = MIN_ROT;
        }
    }

    // delta = rotación nueva - rotación anterior
    float deltaRot = newRotation - lastRot;

    if (deltaRot != 0) {
        miFigura->RotateFigure(deltaRot); // rota solo lo que cambió
    }

    currentRotation = newRotation;
    lastRot = newRotation;
}

void PaddleDerecha::Activate()
{
}
