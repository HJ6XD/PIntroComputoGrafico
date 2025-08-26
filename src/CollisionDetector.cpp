#include "../include/CollisionDetector.h"

CollisionDetector::CollisionDetector(Pelota* p): player(p) {
}

bool CollisionDetector::CheckCollisionWithPared(Pared*) {
	return false;
}

bool CollisionDetector::CheckCollisionWithPin(Pin* pin)
{
	Vector2 distance = { pin->position.x - player->position.x, pin->position.y - player->position.y };
	float dmag = sqrt(((distance.x * distance.x) + (distance.y * distance.y)));
	float radios = (player->radio + pin->radio);
	if (dmag > radios)
		return false;
	else
		return true;
}
