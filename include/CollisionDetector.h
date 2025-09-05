#pragma once
#include <vector>
#include "Pared.h"
#include "Pin.h"
#include "Pelota.h"
class CollisionDetector
{
public: 
	CollisionDetector(Pelota* p);

	Vector2 CheckCollisionWithPared(Obstacle*);

	Vector2 CheckCollisionWithPin(Pin* pin);

private:
	Pelota* player;

	float vectorDotProduct(Vector2 pt1, Vector2 pt2){
		return (pt1.x * pt2.x) + (pt1.y * pt2.y);
	}
};

