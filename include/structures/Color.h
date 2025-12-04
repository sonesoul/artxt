#pragma once
#include "SDL3/SDL.h"

using byte = unsigned char;

struct Color {
	byte R, G, B, A;

	Color(byte r, byte g, byte b, byte a) :
		R(r), G(g), B(b), A(a) {
	}
	Color(byte r, byte g, byte b) :
		Color(r, g, b, 255) {
	}
	Color() :
		Color(0, 0, 0, 0) {
	}

	inline operator SDL_Color() const {
		return SDL_Color{ R, G, B, A };
	}
};