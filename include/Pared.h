#pragma once
#include "GameObject.h"
class Pared :
    public Obstacle
{
public:
    Pared(Vector2 c, int h, int w);
    Pared(Vector2 c, int h, int w, int deg);

    Vector2 ProvideCenter();
    int ProvideMinX();
    int ProvideMaxX();
    int ProvideMinY();
    int ProvideMaxY();
    int provideCurAngle();

    void Start() override;
private:
    int width, height;
    int currentRotation;
};

