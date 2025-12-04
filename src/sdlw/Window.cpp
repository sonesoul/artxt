#include "SDL3/SDL.h"
#include "sdlw/Window.hpp"
#include "sdlw/Renderer.hpp"

using namespace sdlw;

Window::Window(int width, int height, const std::string& title, SDL_WindowFlags flags) :
	UniqueResource(SDL_CreateWindow(title.c_str(), width, height, flags)),
	_sdlEvent(SDL_Event()) {
}

void Window::PollEvents() {

	SDL_Event* sdlEventPtr = &_sdlEvent;
	while (SDL_PollEvent(sdlEventPtr)) {
		
		auto it = _eventMap.find(sdlEventPtr->type);

		if (it != _eventMap.end()) {
			it->second.Invoke(sdlEventPtr);
		}

		_eventMap[SDL_EVENT_ANY].Invoke(sdlEventPtr);
	}
}