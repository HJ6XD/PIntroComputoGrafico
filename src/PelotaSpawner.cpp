#include "../include/PelotaSpawner.h"

PelotaSpawner::PelotaSpawner(Vector2 pos): position(pos), force({0,0}), forceMag(0.f),
mousePos({ GetMousePosition ()})
{
	pelota = new Pelota(position);
	pelota->Start();
	pelota->SetActive(false);
}

void PelotaSpawner::SpawnBall()
{
	/*pelota = new Pelota(position);
	pelota->Start();*/
	pelota->SetPosition(position);
	pelota->SetVelocity(force);
	pelota->SetActive(true);
}
void PelotaSpawner::Update()
{
	if (IsKeyDown(KEY_SPACE) && !pelota->CheckActive()) {
		forceMag += 250 * GetFrameTime();
		if (forceMag > MAX_FORCE_MAG) forceMag = MAX_FORCE_MAG;
		std::cout << forceMag << std::endl;
		DrawCircle(position.x, position.y, 10, RAYWHITE);
	}
	else if (IsKeyReleased(KEY_SPACE) && !pelota->CheckActive()) {
		mousePos = GetMousePosition();
		force.x = mousePos.x - position.x;
		force.y = mousePos.y - position.y;
		float fmag = sqrt((force.x * force.x) + (force.y * force.y));
		force.x /= fmag; force.y /= fmag;
		force.x *= forceMag; force.y *= forceMag;
		SpawnBall();
		forceMag = 0;
	}
}

Pelota* PelotaSpawner::providePelota()
{
	return pelota;
}
