#pragma once
#include "UniqueResource.hpp"

namespace sdlw {
	class Surface : public UniqueResource<SDL_Surface, SDL_DestroySurface> {

	public:
		Surface(SDL_Surface* surface) : 
			UniqueResource(surface) { 
		}
	};
}