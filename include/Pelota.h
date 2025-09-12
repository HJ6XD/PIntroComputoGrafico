#pragma once
#include "GameObject.h"
#include "Score.h"

const float GRAVITY = 9.1;
//const Vector2 MAX_ACCELERATION = {50,20};
//const Vector2 MIN_ACCELERATION = { -50, -20};
const Vector2 MAX_VELOCITY = {250,400};
class Pelota :
    public GameObject
{

public:
    Pelota(Vector2& startPos);
    void Rebotar();
    void Rebotar(Vector2 ndir);
    void Update() override;
    void Draw() override;
    void Accelerate();
    void Move();
    void SetVelocity(Vector2 force);
    void SetActive(bool);
    bool CheckActive();
    void SetPosition(Vector2);
    Vector2 GetVelocity() { return velocity; }
    const int radio = 10;
private:
    Vector2 acceleration, velocity;
    bool isActive;
    Score score;
};

