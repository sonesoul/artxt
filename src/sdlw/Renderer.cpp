#include "SDL3/SDL.h"
#include "sdlw/Renderer.hpp"
#include "sdlw/Drawer.h"
#include "sdlw/Window.hpp"

using namespace sdlw;

Renderer::Renderer(Window* window) :
	_renderer(SDL_CreateRenderer(window->target(), nullptr)), 
	_drawer(Drawer(_renderer)), 
	background(sdlw::Color(0, 0, 0, 0)) { 
}
Renderer::~Renderer() {
	SDL_DestroyRenderer(_renderer);
}

void Renderer::Render() {
	SDL_RenderClear(_renderer);

	_event.Invoke(_drawer);

	_drawer.SetColor(background);
	SDL_RenderPresent(_renderer);
}