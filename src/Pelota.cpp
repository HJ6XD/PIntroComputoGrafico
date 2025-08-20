#include "../include/Pelota.h"

Pelota::Pelota(Vector2 startPos) : velocity({0,0}), 
acceleration({ 0,0 })
{
	position = startPos;
	miFigura = new Circulo(position, 10, false, RAYWHITE);
}

void Pelota::Rebotar()
{
	velocity.x *= -1;
	velocity.y *= -1;
}

void Pelota::Start()
{
	miFigura->InitializeFigure();
}

void Pelota::Update()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		Rebotar();
	}
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
	if (velocity.x > MAX_VELOCITY.x)
		velocity.x = MAX_VELOCITY.x;
	velocity.y += acceleration.y + GRAVITY.y;
	if (velocity.y > MAX_VELOCITY.y)
		velocity.y = MAX_VELOCITY.y;
}

void Pelota::Move()
{
	position.x += velocity.x * GetFrameTime();
	position.y += velocity.y * GetFrameTime();
	std::cout << "la aceleracion es: " << acceleration.x << ", " << acceleration.y << std::endl;

	std::cout << "la pocision es: " << position.x << ", " << position.y << std::endl;
	miFigura->TranslateFigure(velocity.x, velocity.y);
}

void Pelota::AddForce(Vector2 force)
{
	acceleration.x += force.x;	
	if (acceleration.x > MAX_ACCELERATION.x)
		acceleration.x = MAX_ACCELERATION.x;
	else if (acceleration.x < MIN_ACCELERATION.x)
		acceleration.x = MIN_ACCELERATION.x;

	acceleration.y += force.y;
	if (acceleration.y > MAX_ACCELERATION.y)
		acceleration.y = MAX_ACCELERATION.y;
	else if(acceleration.y < MIN_ACCELERATION.y) 
		acceleration.y = MIN_ACCELERATION.y;	
}

