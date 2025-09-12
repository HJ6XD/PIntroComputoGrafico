#pragma once
#include "GameObject.h"
class Pared :
    public Obstacle
{
public:
    Pared(Vector2 c, int h, int w);
    Pared(Vector2 c, int h, int w, int deg);


    void Start() override;
private:
    
};

