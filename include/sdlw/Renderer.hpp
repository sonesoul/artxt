#pragma once 
#include "SDL3/SDL.h"
#include "Event.hpp"
#include "Drawer.h"

namespace sdlw {

	class Renderer {

	private:

		SDL_Renderer* _target;
		int _delayTimeMs;
		sdlw::Event<Drawer&> _event;

	public:
		Renderer(SDL_Window* window);

		void Render();
		void setTargetFPS(int fps);

		inline sdlw::Event<Drawer&>& event() {
			return _event;
		}
		inline SDL_Renderer* target() const {
			return _target;
		}
	};
}