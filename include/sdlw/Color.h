#pragma once
#include "SDL3/SDL.h"
#include "wtypes.h"

namespace sdlw {

	struct Color {
		byte R, G, B, A;

		Color(byte r, byte g, byte b, byte a);
		Color(byte r, byte g, byte b);
		Color();

		operator SDL_Color() const;
	};
}