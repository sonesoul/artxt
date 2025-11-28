#pragma once
#include "wtypes.h"
#include "UniqueResource.hpp"

namespace sdlw {
	class Texture : public UniqueResource<SDL_Texture, SDL_DestroyTexture>{

		float _w;
		float _h;

		SDL_ScaleMode _scaleMode;
		SDL_BlendMode _blendMode;

	public:
		Texture(SDL_Texture* texture) :
			UniqueResource(texture) {

			SDL_Texture* tex = raw();
			SDL_GetTextureSize(tex, &_w, &_h);
			SDL_GetTextureScaleMode(tex, &_scaleMode);
			SDL_GetTextureBlendMode(tex, &_blendMode);
		}

		inline void SetColor(const Color& color) { 
			SDL_Texture* tex = raw();
			SDL_SetTextureColorMod(tex, color.R, color.G, color.B);
			SDL_SetTextureAlphaMod(tex, color.A);
		}
		inline void SetScaleMode(SDL_ScaleMode scaleMode) {
			SDL_SetTextureScaleMode(raw(), scaleMode);
		}
		inline void SetBlendMode(SDL_BlendMode& blendMode) {
			SDL_SetTextureBlendMode(raw(), blendMode);
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
	};
}