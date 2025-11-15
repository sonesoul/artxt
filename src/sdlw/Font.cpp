#include "sdlw/sdlw.h"
#include "sdlw/Font.h"
#include <iostream>

using namespace sdlw;

Font::Font(const std::string& path, byte height, Renderer* renderer) : 
	_font(TTF_OpenFont(path.c_str(), height)),
	_height(height) {

	Preload(renderer);
}
Font::~Font() {
	TTF_CloseFont(_font);
	for (auto& it : _charCache) {
		Texture* texture = it.second;

		delete texture;
	}
}

Point Font::MeasureString(const std::string& text) {
	int width = 0;
	TTF_MeasureString(_font, text.c_str(), 0, 0, &width, nullptr);
	return Point{ width, _height };
}

void Font::Preload(Renderer* renderer) {

	Color fg = Color(255, 255, 255, 255);

	for (size_t i = 0; i < sizeof(PRELOAD_CHARACTERS); i++) {
		const char& c = PRELOAD_CHARACTERS[i];

		SDL_Surface* surface = RenderGlyph(c, fg);
		Texture* texture = new Texture(renderer->target(), surface);
		texture->SetScaleMode(SDL_SCALEMODE_NEAREST);
		_charCache[c] = texture;
	}
}