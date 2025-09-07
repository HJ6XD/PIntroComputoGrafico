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
    bool isPin, isPared;

	Obstacle(Vector2& pos, float bv) : GameObject(pos) 
	{
		bounceValue = bv;
	}
	Vector2 ProvideCenter() {
		return position;
	}

    std::vector<Vector2> getVertices() const {
        std::vector<Vector2> verts;

        // mitad del ancho y alto
        float hw = width * 0.5f;
        float hh = height * 0.5f;

        // vértices en espacio local (respecto al centro)
        std::vector<Vector2> localVerts = {
            {-hw, -hh}, // abajo-izquierda
            { hw, -hh}, // abajo-derecha
            { hw,  hh}, // arriba-derecha
            {-hw,  hh}  // arriba-izquierda
        };

        // precomputar sen y cos
        float rad = currentRotation * (PI / 180.0f);
        float cosR = std::cos(rad);
        float sinR = std::sin(rad);

        // rotar y trasladar
        for (auto& v : localVerts) {
            Vector2 rotated = {
                v.x * cosR - v.y * sinR,
                v.x * sinR + v.y * cosR
            };
            verts.push_back({ rotated.x + position.x, rotated.y + position.y });
        }

        return verts;
    }
};