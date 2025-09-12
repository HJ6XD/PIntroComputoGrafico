#pragma once
#include "GameObject.h"
class PaddleIzquierda : public Obstacle
{
public:
	PaddleIzquierda(Vector2 pos, int w, int h);
	void Start() override;
	void Update() override;
	void Activate();
private:
	float lastRot;
	float rotationSpeed;
	const float MAX_ROT = -30;
	const float MIN_ROT = 20;
};

