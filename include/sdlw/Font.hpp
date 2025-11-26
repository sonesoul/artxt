#pragma once
#include <string>
#include <unordered_map>
#include "SDL3_ttf/SDL_ttf.h"
#include "structures/Point.h"
#include "UniqueResource.hpp"

namespace sdlw {
	class Renderer;
	class Surface;

	class Font : public UniqueResource<TTF_Font, TTF_CloseFont> {

		static constexpr const char PRELOAD_CHARACTERS[] =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ" 
			"abcdefghijklmnopqrstuvwxyz" 
			".,:;!?'\"<>()[]{}+-=*/%&@#$^~_|\\";
		
		byte _height;
		std::unordered_map<char, Texture*> _charCache;

	public:
		Font(const std::string& path, byte height, Renderer* renderer);
		~Font();

		Point MeasureString(const std::string& text) const;

		Texture* GetGlyph(const char& c) const;

		inline byte height() const {
			return _height;
		} 

	private:
		Surface* CreateGlyph(const char& c, Color& fg) const; 
		void Preload(Renderer* renderer);
	};
}