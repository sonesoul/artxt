#pragma once
#include <string>
#include <unordered_map>
#include "SDL3_ttf/SDL_ttf.h"
#include "Point.h"

namespace sdlw {
	class Renderer;

	class Font {

		static constexpr const char PRELOAD_CHARACTERS[] =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ" 
			"abcdefghijklmnopqrstuvwxyz" 
			".,:;!?'\"<>()[]{}+-=*/%&@#$^~_|\\";
		
		TTF_Font* _font;
		byte _height;
		std::unordered_map<char, Texture*> _charCache;

	public:
		Font(const std::string& path, byte height, Renderer* renderer);
		~Font();

		Point MeasureString(const std::string& text) const;

		Texture* GetGlyph(const char& c) const;

		inline TTF_Font* raw() const {
			return _font;
		}
		inline byte height() const {
			return _height;
		} 

	private:
		inline SDL_Surface* RenderGlyph(const char& c, Color& fg) const {
			return TTF_RenderGlyph_Blended(_font, (int)c, fg);
		}
		void Preload(Renderer* renderer);
	};
}