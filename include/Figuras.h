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

	virtual void DrawFigure() {}
	virtual void RasterizeFigure() {}
	void Draw();
	virtual void Update() {}
	void InitializeFigure();
	void TranslateFigure(int x, int y);
	void RotateFigure(int deg);
	void ScaleFigure(float W, float H);

protected:
	void DrawLineDDA(Vector2 p1, Vector2 p2);	
	void DrawLineBresenham(Vector2 p1, Vector2 p2);
	bool CheckIfAlredyOnList(Vector2 newpoint);
};

