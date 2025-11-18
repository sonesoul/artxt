#pragma once

namespace sdlw {
	class Texture {

		SDL_Texture* _texture;

	public:
		Texture(SDL_Texture* texture) :
			_texture(texture) {
		}
		Texture(SDL_Renderer* renderer, SDL_Surface* surface) : 
			Texture(SDL_CreateTextureFromSurface(renderer, surface)) {	
		}

		~Texture() {
			SDL_DestroyTexture(_texture);
		}

		inline void SetScaleMode(SDL_ScaleMode scaleMode) {
			SDL_SetTextureScaleMode(_texture, scaleMode);
		}
		inline void SetColor(const Color& color) { 
			SDL_SetTextureColorMod(_texture, color.R, color.G, color.B);
			SDL_SetTextureAlphaMod(_texture, color.A);
		}

		inline SDL_Texture* const target() const {
			return _texture;
		}
	};
}