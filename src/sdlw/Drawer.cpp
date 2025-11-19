#include "sdlw/Drawer.h"
#include "sdlw/Font.hpp"
#include "sdlw/Texture.h"

using namespace sdlw;

void Drawer::RenderText(const Font& font, std::string text, FPoint position, float scale, Color* color) {

	FRect dst = FRect(position, FPoint(0, 0));

	for (auto& c : text) {
		Texture* charTexture = font.GetGlyph(c);
		
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