#pragma once
#include <raylib.h>
#include "FuncionesDibujoLinea.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
class Figuras
{
public:
	std::vector<Vector2> puntos;
	std::vector<Vector2>::iterator it;
	virtual void DrawFigure() {}
	virtual void RasterizeFigure() {}
	void Draw();
protected:
	void DrawLineDDA(Vector2 p1, Vector2 p2);	
	void DrawLineBresenham(Vector2 p1, Vector2 p2);

};

