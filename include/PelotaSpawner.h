#pragma once
#include "Pelota.h"
#include "raylib.h"
#include <iostream>
#include <string>
#include <iomanip>
class PelotaSpawner
{
public:
	PelotaSpawner(Vector2 pos);
	void SpawnBall();
	void Update();
	Pelota* providePelota();
	void DrawForceText();
private:
	Pelota* pelota;
	const float MAX_FORCE_MAG = 1200.f;
	Vector2 force;
	float forceMag;
	std::string forceText;
	Vector2 mousePos;
	Vector2 position;

};