#pragma once
#include <list>
#include "Pared.h"
#include "Pin.h"
#include "Pelota.h"
class CollisionDetector
{
public: 
	CollisionDetector(Pelota* p);

	bool CheckCollisionWithPared(Pared*);

	Vector2 CheckCollisionWithPin(Pin* pin);

private:
	Pelota* player;
};

