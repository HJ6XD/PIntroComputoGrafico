#pragma once
#include <raylib.h>
#include "FuncionesDibujoLinea.h"
#include <vector>

class Figuras
{
public:
	std::vector<Vector2> puntos;
	virtual void DrawFigure() {}
	void Draw();
protected:
	FuncionesDibujoLinea FDL;
	void DrawLineDDA(Vector2 p1, Vector2 p2);

};

