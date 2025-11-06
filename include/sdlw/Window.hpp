#pragma once
#include <unordered_map>
#include <string>
#include "Event.hpp"

namespace sdlw {
	class Window {
		
	private:

		SDL_Window* _window;

		SDL_Event _sdlEvent;
		std::unordered_map<Uint32, Event<const SDL_Event*>> _eventMap;

	public:
		Window(int width, int height, const std::string& title, SDL_WindowFlags flags);
		~Window();
		
		void PollEvents();

		inline Event<const SDL_Event*>& event(Uint32 sdlEventType) {
			return _eventMap[sdlEventType];
		}
		inline SDL_Window* target() const {
			return _window;
		}
	};
}