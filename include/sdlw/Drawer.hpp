#pragma once
#include "Color.hpp"

namespace sdlw {
	
	struct Drawer {

	private:
		SDL_Renderer* const _renderer;

	public: 

		Drawer(const Drawer&) = delete;

		inline Drawer(SDL_Renderer* renderer) : 
			_renderer(renderer) { }

		inline void setColor(const Color& c) const {
			SDL_SetRenderDrawColor(_renderer, c.R, c.G, c.B, c.A);
		}
		inline SDL_Renderer* getRenderer() const {
			return _renderer;
		}

		Drawer& operator=(const Drawer&) = delete;
	};
}