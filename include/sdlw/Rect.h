#pragma once
#include "SDL3/SDL.h"
#include "Point.h"

namespace sdlw {

	struct Rect {

		union {
			struct { int x, y, width, height; };
			SDL_Rect _rect;
		};


		Rect(int x, int y, int width, int height) :
			x(x),
			y(y),
			width(width),
			height(height) {
		}
		Rect(Point position, Point size) :
			Rect(position.X, position.Y, size.X, size.Y) {
		}
		Rect() : Rect(0, 0, 0, 0) {
		}

		operator SDL_Rect*() {
			return &_rect;
		}
	};
}