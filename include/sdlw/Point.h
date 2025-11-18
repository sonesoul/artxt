#pragma once
#include "SDL3/SDL.h"

namespace sdlw {
	
	struct Point {

		union {
			struct { int X, Y; };
			SDL_Point _point;
		};
		
		Point(int x, int y) : 
			X(x), 
			Y(y) {
		}

		operator SDL_Point*() {
			return &_point;
		}
	};
}