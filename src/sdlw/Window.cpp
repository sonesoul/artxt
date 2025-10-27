#include "sdlw/Window.hpp"
#include "sdlw/Renderer.hpp"

using namespace sdlw;

Window::Window(int width, int height, const char* title, SDL_WindowFlags flags) :
	_target(SDL_CreateWindow(title, width, height, flags)),
	_sdlEvent(SDL_Event()) { }

Window::~Window() {
	SDL_DestroyWindow(_target);
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