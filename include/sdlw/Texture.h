#pragma once

namespace sdlw {
	class Texture {

		SDL_Texture* _texture;

		float _w;
		float _h;

		SDL_ScaleMode _scaleMode;
		SDL_BlendMode _blendMode;

	public:
		Texture(SDL_Texture* texture) :
			_texture(texture) {

			SDL_GetTextureSize(_texture, &_w, &_h);
			SDL_GetTextureScaleMode(_texture, &_scaleMode);
			SDL_GetTextureBlendMode(_texture, &_blendMode);
		}
		Texture(SDL_Renderer* renderer, SDL_Surface* surface) : 
			Texture(SDL_CreateTextureFromSurface(renderer, surface)) {	
		}

		~Texture() {
			SDL_DestroyTexture(_texture);
		}

		inline void SetColor(const Color& color) { 
			SDL_SetTextureColorMod(_texture, color.R, color.G, color.B);
			SDL_SetTextureAlphaMod(_texture, color.A);
		}
		inline void SetScaleMode(SDL_ScaleMode scaleMode) {
			SDL_SetTextureScaleMode(_texture, scaleMode);
		}
		inline void SetBlendMode(SDL_BlendMode& blendMode) {
			SDL_GetTextureBlendMode(_texture, &blendMode);
		}

		inline FPoint size() const {
			return FPoint{ _w, _h };
		}
		inline float width() const {
			return _w;
		}
		inline float height() const {
			return _h;
		}

		inline SDL_ScaleMode scaleMode() const {
			return _scaleMode;
		}
		inline SDL_BlendMode blendMode() const {
			return _blendMode;
		}

		inline SDL_Texture* raw() {
			return _texture;
		}
	};
}