#pragma once
#include "SDL3/SDL.h"

struct Point {

	union {
		struct { int X, Y; };
		SDL_Point _point;
	};

	Point(int x, int y) :
		X(x),
		Y(y) {
	}
	Point() : Point(0, 0) {
	}

	operator SDL_Point* () {
		return &_point;
	}
};