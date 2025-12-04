#include "structures.h"
#include "sdlw.h"
#include <stdexcept>

using namespace sdlw;

Font::Font(const std::string& path, byte height, Renderer* renderer) :
	UniqueResource(TTF_OpenFont(path.c_str(), height)),
	_height(height) {

	Preload(renderer);
}
Font::~Font() {
	for (auto& it : _charCache) {
		Texture* texture = it.second;
		delete texture;
	}
}

Point Font::MeasureString(const std::string& text) const {
	int width = 0;
	TTF_MeasureString(raw(), text.c_str(), 0, 0, &width, nullptr);
	return Point{ width, _height };
}

void Font::Preload(Renderer* renderer) {

	Color fg = Color(255, 255, 255, 255);

	for (size_t i = 0; i < sizeof(PRELOAD_CHARACTERS); i++) {
		const char& c = PRELOAD_CHARACTERS[i];

		Surface* surface = CreateGlyph(c, fg);
		Texture* texture = renderer->CreateTexture(surface);
		delete surface;

		texture->SetScaleMode(SDL_SCALEMODE_NEAREST);
		_charCache[c] = texture;
	}
}
Texture* Font::GetGlyph(const char& c) const {
	auto& it = _charCache.find(c);
	if (it != _charCache.end()) {
		return (*it).second;
	}

	throw std::runtime_error(std::string("couldn't find glyph texture [") + c + ']');
}

Surface* Font::CreateGlyph(const char& c, Color& fg) const {
	return new Surface(TTF_RenderGlyph_Blended(raw(), (int)c, fg));
} 