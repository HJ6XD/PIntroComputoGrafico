#pragma once
#include "Pelota.h"
#include "raylib.h"
#include <iostream>
class PelotaSpawner
{
public:
	PelotaSpawner(Vector2 pos);
	void SpawnBall();
	void Update();
	Pelota* providePelota();

private:
	Pelota* pelota;
	const float MAX_FORCE_MAG = 1200.f;
	Vector2 force;
	float forceMag;
	Vector2 mousePos;
	Vector2 position;
};

