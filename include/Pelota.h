#pragma once
#include "GameObject.h"
#include <algorithm>
#include <cstdint>
#include <iomanip> 
const Vector2 GRAVITY = { 0, 10 };
const Vector2 MAX_ACCELERATION = {50,20};
const Vector2 MIN_ACCELERATION = { -50, -20};
const Vector2 MAX_VELOCITY = {120,240};
class Pelota :
    public GameObject
{

public:
    Pelota(Vector2 startPos);
    void Rebotar();
    void Start() override;
    void Update() override;
    void Draw() override;
    void Accelerate();
    void Move();
    void AddForce(Vector2 force);

private:
    Vector2 acceleration, velocity;
};

