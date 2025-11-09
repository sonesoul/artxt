#include "SDL3/SDL.h"
#include "sdlw/Renderer.hpp"
#include "sdlw/Drawer.h"
#include "sdlw/Window.hpp"

using namespace sdlw;

Renderer::Renderer(Window* window) :
	_renderer(SDL_CreateRenderer(window->target(), nullptr)) {
}
Renderer::~Renderer() {
	SDL_DestroyRenderer(_renderer);
}

void Renderer::Render() {
	SDL_RenderClear(_renderer);

	Drawer d(_renderer);
	_event.Invoke(d);

	SDL_RenderPresent(_renderer);
}