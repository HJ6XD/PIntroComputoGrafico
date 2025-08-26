#include "../include/Pin.h"

Pin::Pin(Vector2 p, int r, Color c) : radio(r) {
	position = p;
	miFigura = new Circulo(position, r, true, c);
}
