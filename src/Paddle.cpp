#include "../include/PaddleIzquierda.h"

PaddleIzquierda::PaddleIzquierda(Vector2 pos, int w, int h) : Obstacle(pos, 1)
{
	width = w;
	height = h;
	currentRotation = 30;
	rotationSpeed = 50;
	miFigura = new Cuadrado(position, width, height, false, GOLD);
}

void PaddleIzquierda::Start()
{
	miFigura->InitializeFigure();
	Vector2 nCenter = { position.x - width / 2 + height / 2, position.y };
	miFigura->MoveCenter(nCenter);
	miFigura->RotateFigure(currentRotation);
}

void PaddleIzquierda::Update()
{
	if (IsKeyDown(KEY_A)) {
		if (currentRotation > MAX_ROT && currentRotation != MAX_ROT) {
			currentRotation -= rotationSpeed * GetFrameTime();
			if (currentRotation < MAX_ROT) currentRotation = MAX_ROT;
			miFigura->RotateFigure(currentRotation);
		}
	}
	else if (currentRotation < MIN_ROT && currentRotation != MIN_ROT) {
		currentRotation += rotationSpeed * GetFrameTime();
		if (currentRotation > MIN_ROT) currentRotation = MIN_ROT;
		miFigura->RotateFigure(currentRotation);
	}
}

void PaddleIzquierda::Activate()
{
}
