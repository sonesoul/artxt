#include "SDL3/SDL.h"
#include "sdlw/Renderer.hpp"
#include "sdlw/Drawer.h"
#include "sdlw/Window.hpp"

using namespace sdlw;

Renderer::Renderer(Window* window) :
	_renderer(SDL_CreateRenderer(window->target(), nullptr)),
	_delayTimeMs(1) {
}
Renderer::~Renderer() {
	SDL_DestroyRenderer(_renderer);
}

void Renderer::setTargetFPS(int fps) {
	_delayTimeMs = 1000 / fps;
}

void Renderer::Render() {
	SDL_RenderClear(_renderer);

	Drawer d(_renderer);
	_event.invoke(d);

	SDL_RenderPresent(_renderer);
}