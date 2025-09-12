#include "../include/Pelota.h"

Pelota::Pelota(Vector2& startPos) : GameObject(startPos)
{
	velocity = { 0,0 };
	acceleration = { 0,0 };
	miFigura = new Circulo(position, radio, false, RAYWHITE);
	isActive = true;
}

void Pelota::Rebotar()
{
	if (velocity.y <  GRAVITY && velocity.y > -GRAVITY)
		velocity.y = 0;
	else
	velocity.y *= -1;
	std::cout << velocity.y << std::endl;
}

void Pelota::Rebotar(Vector2 ndir)
{
	float speed = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	speed /= 5;
	ndir.x *= speed;
	ndir.y *= speed;
	SetVelocity(ndir);
}

void Pelota::Update()
{
	if (isActive) {
		Accelerate();
		Move();
	}
}

void Pelota::Draw()
{
	if (isActive)
		miFigura->Draw();
}

void Pelota::Accelerate()
{
	velocity.y += GRAVITY;
	if (velocity.y > MAX_VELOCITY.y)
		velocity.y = MAX_VELOCITY.y;
}

void Pelota::Move()
{
	position.x += velocity.x * GetFrameTime();
	position.y += velocity.y * GetFrameTime();
	miFigura->TranslateTo(position);
	std::cout << "Pelota pos: " << position.x << ", " << position.y << std::endl;
	if (position.y > GetScreenHeight() || position.x > GetScreenWidth()
		|| position.y < 0 || position.x < 0)
		SetActive(false);
	
}

void Pelota::SetVelocity(Vector2 force)
{
	velocity.x = force.x;
	if (velocity.x > MAX_VELOCITY.x)
		velocity.x = MAX_VELOCITY.x;
	else if(velocity.x < -MAX_VELOCITY.x)
		velocity.x = -MAX_VELOCITY.x;
	velocity.y = force.y;
	if (velocity.y > MAX_VELOCITY.y)
		velocity.y = MAX_VELOCITY.y;
	else if(velocity.y < -MAX_VELOCITY.y)
		velocity.y = -MAX_VELOCITY.y;
}

void Pelota::SetActive(bool active)
{
	isActive = active;
}

bool Pelota::CheckActive()
{
	return isActive;
}

void Pelota::SetPosition(Vector2 npos)
{
	position = npos;
	miFigura->TranslateTo(npos);
}

