#include "../include/Pelota.h"

Pelota::Pelota(Vector2 startPos) : velocity({0,0}), 
acceleration({ 0,0 })
{
	position = startPos;
	miFigura = new Circulo(position, 10, false, RAYWHITE);
}

void Pelota::Rebotar()
{
}

void Pelota::Start()
{
	miFigura->InitializeFigure();
}

void Pelota::Update()
{
	AddForce(GRAVITY);
	Accelerate();
	Move();
}

void Pelota::Draw()
{
	miFigura->Draw();
}

void Pelota::Accelerate()
{
	velocity.x += acceleration.x;
	if (velocity.x > MAX_SPEED.x)
		velocity.x = MAX_SPEED.x;
	velocity.y += acceleration.y;
	if (velocity.y > MAX_SPEED.y)
		velocity.y = MAX_SPEED.y;
}

void Pelota::Move()
{
	position.x += velocity.x * GetFrameTime();
	position.y += velocity.y * GetFrameTime();
	std::cout << "la pocision es: " << position.x << ", " << position.y << std::endl;
	miFigura->TranslateFigure(velocity.x, velocity.y);
}

void Pelota::AddForce(Vector2 force)
{
	acceleration.x += force.x * GetFrameTime();
	if (acceleration.x > MAX_ACCELERATION.x)
		acceleration.x = MAX_ACCELERATION.x;
	acceleration.y += force.y * GetFrameTime();
	if (acceleration.y > MAX_ACCELERATION.y)
		acceleration.y = MAX_ACCELERATION.y;
	std::cout << "la aceleracion es: " << acceleration.x << ", " << acceleration.y << std::endl;
}
