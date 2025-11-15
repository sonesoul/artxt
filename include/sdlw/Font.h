#pragma once
#include <string>
#include <unordered_map>

namespace sdlw {
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

		Point MeasureString(const std::string& text);

		inline SDL_Surface* RenderGlyph(const char& c, Color& fg) const {
			return TTF_RenderGlyph_Blended(_font, (int)c, fg);
		}
		inline Texture* GetChar(const char& c) {
			return _charCache[c];
		}

		inline TTF_Font* target() const {
			return _font;
		}
		inline byte height() const {
			return _height;
		} 

		void Preload(Renderer* renderer);
	};
}