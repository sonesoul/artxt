#pragma once
#include "Color.h"

namespace sdlw {

	class Font;
	class Texture;

	struct Drawer {
		SDL_Renderer* _renderer;

	public: 
		Drawer(SDL_Renderer* renderer) : 
			_renderer(renderer) { 
		}

		void RenderText(const Font& font, const char* text, FPoint position, float scale, Color* color);
		void RenderTexture(Texture* texture, FRect* src, FRect* dst, Color* color);
		inline void SetColor(const Color& color) {
			SDL_SetRenderDrawColor(_renderer, color.R, color.G, color.B, color.A);
		}

		inline SDL_Renderer* renderer() const {
			return _renderer;
		}
	};
}