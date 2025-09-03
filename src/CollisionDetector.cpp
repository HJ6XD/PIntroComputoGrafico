#include "../include/CollisionDetector.h"

CollisionDetector::CollisionDetector(Pelota* p): player(p) {
}

Vector2 CollisionDetector::CheckCollisionWithPared(Pared* pared) {
	std::vector<Vector2> vertices = std::vector<Vector2>();
	Vector2 v1 = { pared->ProvideMinX(), pared->ProvideMinY() };
	vertices.push_back(v1);
	Vector2 v2 = { pared->ProvideMaxX(), pared->ProvideMinY() };
	vertices.push_back(v2);
	Vector2 v3 = { pared->ProvideMinX(), pared->ProvideMaxY() };
	vertices.push_back(v3);
	Vector2 v4 = { pared->ProvideMaxX(), pared->ProvideMaxY() };
	vertices.push_back(v4);

	Vector2 playerPos = player->position;

	int minDist = std::numeric_limits<int>::max();
	Vector2 closestDelta = { 0,0 };
	Vector2 axis = { 0,0 };

	for (Vector2 ver : vertices) {

		Vector2 delta = { ver.x - playerPos.x, ver.y - playerPos.y };
		float dist = (delta.x * delta.x) + (delta.y * delta.y);
		if (dist < minDist) {
			minDist = dist;
			closestDelta = delta;
		}
	}

	float magnitud = sqrt((closestDelta.x * closestDelta.x) + (closestDelta.y * closestDelta.y));
	if (magnitud != 0) {
		axis.x = closestDelta.x /magnitud;
		axis.y = closestDelta.y /magnitud;
	}

	float temp = vectorDotProduct(axis, playerPos);
	float circMin = temp - player->radio;
	float circMax = temp + player->radio;

	float pmin = vectorDotProduct(axis, vertices[0]);
	float pmax = std::numeric_limits<int>::min();

	for (int i = 1; i < vertices.size(); i++) {
		float dot = vectorDotProduct(axis, vertices[i]);
		pmin = std::min(pmin, dot);
		pmax = std::min(pmax, dot);
	}

	Vector2 vOffset = { playerPos.x - pared->position.x, playerPos.y - pared->position.y };
	float sOffset = vectorDotProduct(axis, vOffset);
	circMin += sOffset;
	circMax += sOffset;

	if ((pmin - circMax) > 0 || (circMin - pmax) > 0)
	{
		// there is a gap - bail
		return { 0,0 };
    }

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
