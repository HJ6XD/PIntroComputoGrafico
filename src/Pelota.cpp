#include "../include/Pelota.h"

Pelota::Pelota(Vector2& startPos) : GameObject(startPos)
{
	velocity = { 0,0 };
	acceleration = { 0,0 };
	miFigura = new Circulo(position, radio, false, RAYWHITE);
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
	float vmag = (velocity.x * velocity.x) + (velocity.y * velocity.y);
	vmag = sqrt(vmag);
	ndir.x *= vmag;
	ndir.y *= vmag;
	AddForce(ndir);
}

void Pelota::Update()
{
	Accelerate();
	Move();
}

void Pelota::Accelerate()
{
	velocity.y += GRAVITY;
	if (velocity.y > MAX_VELOCITY.y)
		velocity.y = MAX_VELOCITY.y;
}

void Pelota::Move()
{
	miFigura->TranslateFigure(velocity.x * GetFrameTime(), velocity.y * GetFrameTime());
	//position.x = miFigura->center.x + velocity.x * GetFrameTime();
	//position.y = miFigura->center.y + velocity.y * GetFrameTime();

}

void Pelota::AddForce(Vector2 force)
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

