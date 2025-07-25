#pragma once
#include <raylib.h>
#include <math.h>
class FuncionesDibujoLinea
{
public:
	void DibujarLineaDDA(int x1, int y1, int x2, int y2);
	void DibujarLineaCada10DDA(int X, int Y, int steps);
	void DibujarCirculoDDA(int X, int Y, int rad);
	void DibujarCuadradoDDA(int X, int Y, int W, int H);
	void DibujarTrianguloDDA(int x1, int y1, int x2, int y2, int x3, int y3);

	void DibujarLineaBresenham(int x1, int y1, int x2, int y2);
	void DibujarLineaCada10Bresenham(int X, int Y, int rad);
	void DibujarCirculoBresenham(int X, int Y, int rad);
	void DibujarCuadradoBresenham(int X, int Y, int W, int H);
	void DibujarTrianguloBresenham(int x1, int y1, int x2, int y2, int x3, int y3);


};