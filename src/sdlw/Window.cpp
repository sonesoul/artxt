#include "SDL3/SDL.h"
#include "sdlw/Window.hpp"
#include "sdlw/Renderer.hpp"

using namespace sdlw;

Window::Window(int width, int height, const std::string& title, SDL_WindowFlags flags) :
	_window(SDL_CreateWindow(title.c_str(), width, height, flags)),
	_sdlEvent(SDL_Event()) {
}

Window::~Window() {
	SDL_DestroyWindow(_window);
}

void Window::PollEvents() {

	SDL_Event* sdlEventPtr = &_sdlEvent;
	while (SDL_PollEvent(sdlEventPtr)) {

		auto it = _eventMap.find(sdlEventPtr->type);

		if (it != _eventMap.end()) {
			it->second.invoke(sdlEventPtr);
		}
	}
}