#pragma once
#include "SDL3/SDL.h"
#include "wtypes.h"
#include <unordered_map>
#include <string>
#include "functors/Event.hpp"
#include "UniqueResource.hpp"

enum : Uint32 { SDL_EVENT_ANY = SDL_EVENT_USER };

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
		inline Event<const SDL_Event*>& event() {
			return _eventMap[SDL_EVENT_ANY];
		}
	};
}