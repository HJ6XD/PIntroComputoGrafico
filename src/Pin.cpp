#include "../include/Pin.h"

Pin::Pin(Vector2 p, int r, float bv, Color c) : Obstacle(p, bv){
	width = r; height = r;
	miFigura = new Circulo(position, r, true, c);
	isPin = false; isPared = true;

}
