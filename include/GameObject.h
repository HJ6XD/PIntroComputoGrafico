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
	int width, height;
	int currentRotation;

	Obstacle(Vector2& pos, float bv) : GameObject(pos) 
	{
		bounceValue = bv;
	}
	Vector2 ProvideCenter() {
		return position;
	}

	int ProvideMinX(){
		return (position.x - (width / 2));
	}

	int ProvideMaxX(){
		return (position.x + (width / 2));
	}

	int ProvideMinY(){
		return (position.y - (height / 2));;
	}

	int ProvideMaxY(){
		return (position.y + (height / 2));;
	}
};