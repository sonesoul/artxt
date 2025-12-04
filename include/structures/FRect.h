#pragma once
#include "SDL3/SDL.h"
#include "FPoint.h"

struct FRect {

	union {
		struct { float x, y, width, height; };
		SDL_FRect _frect;
	};

	FRect(float x, float y, float width, float height) :
		x(x),
		y(y),
		width(width),
		height(height) {
	}
	FRect(FPoint position, FPoint size) :
		FRect(position.X, position.Y, size.X, size.Y) {
	}
	FRect() : FRect(0, 0, 0, 0) {
	}

	operator SDL_FRect* () {
		return &_frect;
	}
};