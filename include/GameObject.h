#pragma once
#include <raylib.h>
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include <math.h>
#include <iostream>

class GameObject
{
public: 
	Vector2& position;
	Figuras* miFigura;
	GameObject(Vector2& pos) : position(pos){}

	virtual void Start();
	virtual void Update(){}
	virtual void Draw();

protected:
	float GetMagnitud(Vector2 vector);
};

class Obstacle : public GameObject {
public:
	float bounceValue;
	Obstacle(Vector2& pos, float bv) : GameObject(pos) 
	{
		bounceValue = bv;
	}
};