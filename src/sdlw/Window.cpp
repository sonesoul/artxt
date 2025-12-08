#include "SDL3/SDL.h"
#include "sdlw/Window.hpp"
#include "sdlw/Renderer.hpp"

using namespace sdlw;

Window::Window(int width, int height, const std::string& title, SDL_WindowFlags flags) :
	UniqueResource(SDL_CreateWindow(title.c_str(), width, height, flags)),
	_sdlEvent(SDL_Event()) {
}

void Window::PollEvents() {

	SDL_Event* eventPtr = &_sdlEvent;

	while (SDL_PollEvent(eventPtr)) {
		auto it = _eventMap.find(_sdlEvent.type);

		if (it != _eventMap.end()) {
			it->second.Invoke(_sdlEvent);
		}

		_eventMap[SDL_EVENT_ANY].Invoke(_sdlEvent);
	}
}