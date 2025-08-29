#include "../include/Pin.h"

Pin::Pin(Vector2& p, int r, float bv, Color c) : Obstacle(p, bv){
	radio = r;
	miFigura = new Circulo(position, r, true, c);
}
