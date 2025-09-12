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
	Color color;
	Vector2 center;
	bool isDDA, isBresenham;

	
	Figuras(Vector2 c) : center(c){ }

	virtual void DrawFigure() {}
	virtual void RasterizeFigure() {}
	void Draw();
	void InitializeFigure();
	void TranslateFigure(int x, int y);
	void RotateFigure(int deg);
	void ScaleFigure(float W, float H);
	void TranslateTo(Vector2);
	virtual void MoveCenter(Vector2) {}

protected:
	void DrawLineDDA(Vector2 p1, Vector2 p2);	
	void DrawLineBresenham(Vector2 p1, Vector2 p2);
	bool CheckIfAlredyOnList(Vector2 newpoint);
};

