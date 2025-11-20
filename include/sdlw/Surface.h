#pragma once

namespace sdlw {
	class Surface {

		SDL_Surface* _surface;

	public:
		Surface(SDL_Surface* surface) : 
			_surface(surface) { 
		}

		Surface(Surface&) = delete;
		Surface(Surface&& other) noexcept : 
			_surface(other._surface) {
			other._surface = nullptr;
		}

		Surface& operator=(Surface&) = delete;
		Surface& operator=(Surface&& other) noexcept {
			if (this != &other) {
				SDL_DestroySurface(_surface);
				_surface = other._surface;
				other._surface = nullptr;
			}

			return *this;
		}

		~Surface() {
			SDL_DestroySurface(_surface);
		}

		inline SDL_Surface* raw() {
			return _surface;
		}
	};
}