#include "../include/CollisionDetector.h"

CollisionDetector::CollisionDetector(Pelota* p): player(p) {
}

bool CollisionDetector::CheckCollisionWithPared(Pared*) {
	return 0;
}

Vector2 CollisionDetector::CheckCollisionWithPin(Pin* pin)
{
	Vector2 distance = { player->position.x - pin->position.x, player->position.y - pin->position.y };
	float dmag = ((distance.x * distance.x) + (distance.y * distance.y));
	float radios = (player->radio + pin->radio);
	std::cout << "distancia" << dmag << std::endl;
	std::cout << "radios " << radios << std::endl;
	dmag = sqrt(dmag);
	//radios = (radios * radios);
	if (dmag > radios) {
		std::cout << "no hubo colision" << std::endl;		
		return { 0,0 };		
	}
	else {
		std::cout << "si colisionaron" << std::endl;
		distance.x /= dmag;
		distance.y /= dmag;
		return distance;
	}
}
