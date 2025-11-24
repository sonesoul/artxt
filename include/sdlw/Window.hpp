#pragma once
#include "wtypes.h"
#include <unordered_map>
#include <string>
#include "callable/Event.hpp"
#include "UniqueResource.hpp"

namespace sdlw {
	class Window : public UniqueResource<SDL_Window, SDL_DestroyWindow> {
		
	private:
		SDL_Event _sdlEvent;
		std::unordered_map<Uint32, Event<const SDL_Event*>> _eventMap;

	public:
		Window(int width, int height, const std::string& title, SDL_WindowFlags flags);

		void PollEvents();

		inline Event<const SDL_Event*>& event(Uint32 sdlEventType) {
			return _eventMap[sdlEventType];
		}
	};
}