#include "sdlw/Drawer.h"
#include "sdlw/Font.hpp"
#include "sdlw/Texture.h"

using namespace sdlw;

void Drawer::RenderText(const Font& font, const char* text, FPoint position, float scale, Color* color) {

	size_t length = strlen(text);

	FRect dst = FRect(position, FPoint(0, 0));

	for (size_t i = 0; i < length; ++i) {
		Texture* charTexture = font.GetGlyph(text[i]);
		
		dst.width = charTexture->width() * scale;
		dst.height = charTexture->height() * scale;

		RenderTexture(charTexture, nullptr, &dst, color);

		dst.x += dst.width;
	}
}

void Drawer::RenderTexture(Texture* texture, FRect* src, FRect* dst, Color* color) {
	if (color != nullptr)
		texture->SetColor(*color);

	SDL_RenderTexture(_renderer, texture->raw(), *src, *dst);
}