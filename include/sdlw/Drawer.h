#pragma once
#include "Color.h"
#include "Texture.h"

namespace sdlw {
	struct Drawer {

	private:
		SDL_Renderer* const _renderer;

	public: 
		Drawer(SDL_Renderer* renderer) : 
			_renderer(renderer) { 
		}

		inline void SetColor(const Color& c) {
			SDL_SetRenderDrawColor(_renderer, c.R, c.G, c.B, c.A);
		}

		inline void RenderTexture(Texture* texture, FRect* src, FRect* dst)  {
			SDL_RenderTexture(_renderer, texture->target(), src, dst);
		}

		inline SDL_Renderer* renderer() const {
			return _renderer;
		}
	};
}