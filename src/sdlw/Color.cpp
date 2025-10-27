#include "sdlw/Color.h"
#include "SDL3/SDL.h"

using namespace sdlw;

Color::Color(byte r, byte g, byte b, byte a) :
	R(r), G(g), B(b), A(a) { 
}
Color::Color(byte r, byte g, byte b) : 
	Color(r, g, b, 255) { 
}
Color::Color() : 
	Color(0, 0, 0, 0) {
}