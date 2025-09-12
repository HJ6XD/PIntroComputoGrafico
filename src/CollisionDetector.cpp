#include "../include/CollisionDetector.h"

CollisionDetector::CollisionDetector(Pelota* p) : player(p) {}

Vector2 CollisionDetector::CheckCollisionWithPared(Obstacle* pared)
{
    //Revisión si esta en rango para chacer colision
    Vector2 distance = { player->position.x - pared->position.x, player->position.y - pared->position.y };
    float dmag = ((distance.x * distance.x) + (distance.y * distance.y));
    float radios = (player->radio + std::max(pared->width, pared->height));
    dmag = sqrt(dmag);
    if (dmag > radios) { return { 0,0 }; } // si está muy lejos, devuelve 0 para no hacer toda la ootra cochinada

    std::vector<Vector2> vertices = pared->getVertices(); // en espacio de mundo
    Vector2 playerPos = player->position;

    auto normalize = [&](Vector2 v) {
        float len = std::sqrt(v.x * v.x + v.y * v.y);
        return (len > 0.f) ? Vector2{ v.x / len, v.y / len } : Vector2{ 0,0 };
        };
    auto dot = [&](const Vector2& a, const Vector2& b) {
        return a.x * b.x + a.y * b.y;
        };
    auto projectPoly = [&](const Vector2& axis, float& pmin, float& pmax) {
        float proj = vectorDotProduct(vertices[0], axis);
        pmin = proj; pmax = proj;
        for (int i = 1; i < (int)vertices.size(); ++i) {
            proj = vectorDotProduct(vertices[i], axis);
            pmin = std::min(pmin, proj);
            pmax = std::max(pmax, proj);
        }
        };
    auto projectCircle = [&](const Vector2& axis, float& cmin, float& cmax) {
        float centerProj = vectorDotProduct(playerPos, axis);
        cmin = centerProj - player->radio;
        cmax = centerProj + player->radio;
        };

    float overlapMin = std::numeric_limits<float>::max();
    Vector2 smallestAxis = { 0,0 };
    bool separated = false; // <- si encontramos un eje separador, true

    // 1) Normales de los lados del poligono
    for (int i = 0; i < (int)vertices.size(); ++i) {
        Vector2 p1 = vertices[i];
        Vector2 p2 = vertices[(i + 1) % vertices.size()];
        Vector2 edge = { p2.x - p1.x, p2.y - p1.y };
        float len2 = edge.x * edge.x + edge.y * edge.y;
        if (len2 == 0.f) continue; // lado degenerado

        Vector2 axis = normalize({ -edge.y, edge.x }); // normal, no el lado

        float pmin, pmax, cmin, cmax;
        projectPoly(axis, pmin, pmax);
        projectCircle(axis, cmin, cmax);

        if (pmin > cmax || cmin > pmax) {
            separated = true; // eje separador -> no hay colision
            break;
        }
        else {
            float overlap = std::min(pmax, cmax) - std::max(pmin, cmin);
            if (overlap < overlapMin) {
                overlapMin = overlap;
                smallestAxis = axis;
            }
        }
    }

    // 2) Eje hacia el vertice mas cercano
    if (!separated) {
        float minDistSq = std::numeric_limits<float>::max();
        Vector2 closestDelta = { 0,0 };
        for (const Vector2& v : vertices) {
            Vector2 d = { playerPos.x - v.x, playerPos.y - v.y };
            float dsq = d.x * d.x + d.y * d.y;
            if (dsq < minDistSq) {
                minDistSq = dsq;
                closestDelta = d;
            }
        }
        if (minDistSq > 0.f) {
            Vector2 axis = normalize(closestDelta);
            float pmin, pmax, cmin, cmax;
            projectPoly(axis, pmin, pmax);
            projectCircle(axis, cmin, cmax);

            if (pmin > cmax || cmin > pmax) {
                separated = true;
            }
            else {
                float overlap = std::min(pmax, cmax) - std::max(pmin, cmin);
                if (overlap < overlapMin) {
                    overlapMin = overlap;
                    smallestAxis = axis;
                }
            }
        }
    }

    if (separated) {
        // No hubo colision
        return { 0,0 };
    }

    // Orientar la normal para que apunte del poligono hacia el circulo
    Vector2 polyCenter = { 0,0 };
    for (auto& v : vertices) { polyCenter.x += v.x; polyCenter.y += v.y; }
    polyCenter.x /= vertices.size();
    polyCenter.y /= vertices.size();
    Vector2 normal = smallestAxis;
    Vector2 dir = { playerPos.x - polyCenter.x, playerPos.y - polyCenter.y };
    if (vectorDotProduct(dir, normal) < 0.f) {
        normal.x = -normal.x;
        normal.y = -normal.y;
    }

    // Rebote: reflejar velocidad respecto a la normal
    Vector2 vel = player->GetVelocity();
    float speed = std::sqrt(vel.x * vel.x + vel.y * vel.y);
    float d = vel.x * normal.x + vel.y * normal.y;
    Vector2 reflected = { vel.x - 2.f * d * normal.x, vel.y - 2.f * d * normal.y };
    Vector2 refnorm = normalize(reflected);
    return refnorm; // si prefieres, devuelve `normal`
}

Vector2 CollisionDetector::CheckCollisionWithPin(Obstacle* pin)
{
	Vector2 distance = { player->position.x - pin->position.x, player->position.y - pin->position.y };
	float dmag = ((distance.x * distance.x) + (distance.y * distance.y));
	float radios = (player->radio + pin->width);
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
