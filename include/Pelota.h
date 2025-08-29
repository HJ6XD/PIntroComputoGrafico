#pragma once
#include "GameObject.h"

const float GRAVITY = 9.1;
const Vector2 MAX_ACCELERATION = {50,20};
const Vector2 MIN_ACCELERATION = { -50, -20};
const Vector2 MAX_VELOCITY = {120,240};
class Pelota :
    public GameObject
{

public:
    Pelota(Vector2& startPos);
    void Rebotar();
    void Rebotar(float bounceVal);
    void Update() override;
    void Accelerate();
    void Move();
    void AddForce(Vector2 force);

    const int radio = 10;
private:
    Vector2 acceleration, velocity;
};

