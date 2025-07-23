#pragma once
#include <raylib.h>
#include <math.h>
class FuncionesDibujoLinea
{
public:
	void DibujarLineaDDA(int x1, int y1, int x2, int y2);
	void DibujarLineaCada10DDA(int X, int Y, int steps);
	void DibujarCirculoDDA(int rad);

	void DibujarLineaBresenham(int x1, int y1, int x2, int y2);
	void DibujarLineaCada10Bresenham(int X, int Y, int rad);
};