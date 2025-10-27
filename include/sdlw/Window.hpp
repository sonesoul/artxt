#pragma once
#include "SDL3/SDL.h"
#include <unordered_map>
#include "Event.hpp"

namespace sdlw {
	
	class Window {
		
	private:

		SDL_Window* _target;

		SDL_Event _sdlEvent;
		std::unordered_map<Uint32, Event<const SDL_Event*>> _eventMap;

	public:
		Window(int width, int height, const char* title, SDL_WindowFlags flags);
		~Window();
		
		void PollEvents();

		inline Event<const SDL_Event*>& event(Uint32 sdlEventType) {
			return _eventMap[sdlEventType];
		}
		inline SDL_Window* target() const {
			return _target;
		}
	};
}