#pragma once

namespace sdlw {
	class Surface {

		SDL_Surface* _surface;

	public:
		Surface(SDL_Surface* surface) : 
			_surface(surface) { 
		}
		~Surface() {
			SDL_DestroySurface(_surface);
		}

		inline SDL_Surface* target() {
			return _surface;
		}
	};
}