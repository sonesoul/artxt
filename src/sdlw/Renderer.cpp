#include "SDL3/SDL.h"
#include "sdlw/Renderer.hpp"
#include "sdlw/Drawer.h"
#include "sdlw/Window.hpp"
#include "sdlw/Surface.h"
#include "sdlw/Texture.h"

using namespace sdlw;

Renderer::Renderer(Window* window) :
	UniqueResource(SDL_CreateRenderer(window->raw(), nullptr)),
	_drawer(raw()),
	background(Color(0, 0, 0, 0)) {
}

void Renderer::Render() {
	SDL_RenderClear(raw());

	_event.Invoke(_drawer);
	_drawer.SetColor(background);

	SDL_RenderPresent(raw());
}

Texture* Renderer::CreateTexture(Surface* surface) {
	return new Texture(SDL_CreateTextureFromSurface(raw(), surface->raw()));
}