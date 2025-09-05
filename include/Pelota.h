#pragma once
#include "GameObject.h"

const float GRAVITY = 9.1;
//const Vector2 MAX_ACCELERATION = {50,20};
//const Vector2 MIN_ACCELERATION = { -50, -20};
const Vector2 MAX_VELOCITY = {300,500};
class Pelota :
    public GameObject
{

public:
    Pelota(Vector2& startPos);
    void Rebotar();
    void Rebotar(Vector2 ndir);
    void Update() override;
    void Accelerate();
    void Move();
    void AddForce(Vector2 force);

    Vector2 GetVelocity() { return velocity; }
    const int radio = 10;
private:
    Vector2 acceleration, velocity;
};

