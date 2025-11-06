#pragma once
#include <string>
#include "SDL3_ttf/SDL_ttf.h"

namespace sdlw {
	class Font {

		TTF_Font* _font;
		byte _height;
	
	public:
		Font(const std::string& path, byte size);
		~Font();

		Point MeasureString(const std::string& text);

		inline SDL_Surface* RenderGlyph_Solid(const char& c, Color& fg) const {
			return TTF_RenderGlyph_Solid(_font, (int)c, fg);
		}
		inline SDL_Surface* RenderGlyph_Blended(const char& c, Color& fg) const {
			return TTF_RenderGlyph_Blended(_font, (int)c, fg);
		}
		inline SDL_Surface* RenderGlyph_Shaded(const char& c, Color& fg, Color& bg) const {
			return TTF_RenderGlyph_Shaded(_font, (int)c, fg, bg);
		}
		inline SDL_Surface* RenderGlyph_LCD(const char& c, Color& fg, Color& bg) const {
			return TTF_RenderGlyph_LCD(_font, (int)c, fg, bg);
		}
		
		inline TTF_Font* target() const {
			return _font;
		}
		inline byte height() const {
			return _height;
		} 
	};
}