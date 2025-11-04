#pragma once
#include "Color.h"

namespace sdlw {
	
	struct Drawer {

	private:
		SDL_Renderer* const _renderer;

	public: 

		Drawer(const Drawer&) = delete;

		Drawer(SDL_Renderer* renderer) : 
			_renderer(renderer) { }

		inline void SetColor(const Color& c) const {
			SDL_SetRenderDrawColor(_renderer, c.R, c.G, c.B, c.A);
		}
		inline SDL_Renderer* renderer() const {
			return _renderer;
		}

		Drawer& operator=(const Drawer&) = delete;
	};
}