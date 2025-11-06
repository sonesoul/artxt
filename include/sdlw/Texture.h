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

		inline SDL_Texture* const target() const {
			return _texture;
		}
	};
}