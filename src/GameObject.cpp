#include "../include/GameObject.h"

float GameObject::GetMagnitud(Vector2 vector)
{
	float x2 = vector.x * vector.x;
	float y2 = vector.y * vector.y;
	float magnitud = sqrt(x2 + y2);
	return magnitud;
}
