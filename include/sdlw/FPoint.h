#pragma once
#include "SDL3/SDL.h"

namespace sdlw {
	
	struct FPoint {

		union {
			struct { float X, Y; };
			SDL_FPoint _fpoint;
		};

		FPoint(float x, float y) :
			X(x),
			Y(y) {
		}

		operator SDL_FPoint* () {
			return &_fpoint;
		}
	};
}