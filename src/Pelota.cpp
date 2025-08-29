#include "../include/Pelota.h"

Pelota::Pelota(Vector2 startPos) : velocity({0,0}), 
acceleration({ 0,0 })
{
	position = startPos;
	miFigura = new Circulo(startPos, radio, false, RAYWHITE);
}

void Pelota::Rebotar()
{
	if (velocity.y <  GRAVITY && velocity.y > -GRAVITY)
		velocity.y = 0;
	else
	velocity.y *= -1;
	std::cout << velocity.y << std::endl;
}

void Pelota::Rebotar(float bounceVal)
{
	if (velocity.y > 1 || velocity.y < -1)
		velocity.y *= -1;
	else
		velocity.y = 0;
	velocity.y += bounceVal;
	std::cout << velocity.y << std::endl;
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
	std::cout << "la pocision es: " << position.x << ", " << position.y << std::endl;
	miFigura->TranslateFigure(velocity.x * GetFrameTime(), velocity.y * GetFrameTime());
}

void Pelota::AddForce(Vector2 force)
{
	velocity.x += force.x;
	if (velocity.x > MAX_ACCELERATION.x)
		velocity.x = MAX_ACCELERATION.x;
	else if (velocity.x < MIN_ACCELERATION.x)
		velocity.x = MIN_ACCELERATION.x;

	velocity.y += force.y;
	if (velocity.y > MAX_ACCELERATION.y)
		velocity.y = MAX_ACCELERATION.y;
	else if(velocity.y < MIN_ACCELERATION.y)
		velocity.y = MIN_ACCELERATION.y;
}

