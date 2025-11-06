#include "sdlw/sdlw.h"
#include "sdlw/Font.h"

using namespace sdlw;

Font::Font(const std::string& path, byte height) : 
	_height(height),
	_font(TTF_OpenFont(path.c_str(), _height)) {
}
Font::~Font() {
	TTF_CloseFont(_font);
}

Point Font::MeasureString(const std::string& text) {
	int width = 0;
	TTF_MeasureString(_font, text.c_str(), 0, 0, &width, nullptr);
	return Point{ width, _height };
}