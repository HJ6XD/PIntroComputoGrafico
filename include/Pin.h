#pragma once
#include "GameObject.h"
class Pin :
    public GameObject
{
public:
    int radio;
    Pin(Vector2 p, int r, Color c);

};

