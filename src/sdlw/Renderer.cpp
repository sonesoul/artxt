#include "sdlw/Renderer.hpp"

#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "SDL3_ttf/SDL_ttf.h"

using namespace sdlw;

Renderer::Renderer(SDL_Window* window) : 
	_target(SDL_CreateRenderer(window, nullptr)), 
	_delayTimeMs(1) { }

void Renderer::setTargetFPS(int fps) {
	_delayTimeMs = 1000 / fps;
}

void Renderer::Render() {
	SDL_RenderClear(_target);

	Drawer d(_target);
	_event.invoke(d);

	SDL_RenderPresent(_target);
}