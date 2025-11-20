#pragma once
#include "wtypes.h"
#include "SDLHolder.hpp"

namespace sdlw {
	class Surface : public SDLHolder<SDL_Surface, SDL_DestroySurface> {

	public:
		Surface(SDL_Surface* surface) : 
			SDLHolder(surface) { 
		}
	};
}