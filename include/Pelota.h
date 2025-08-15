#pragma once
#include "GameObject.h"
const Vector2 GRAVITY = { 0, 9 };
const Vector2 MAX_ACCELERATION = {50,200};
const Vector2 MAX_SPEED = {120,240};
class Pelota :
    public GameObject
{

public:
    Pelota(Vector2 startPos);
    void Rebotar();
    void Start() override;
    void Update() override;
    void Draw() override;

private:
    Vector2 acceleration, velocity;
    void Accelerate();
    void Move();
    void AddForce(Vector2 force);
};

