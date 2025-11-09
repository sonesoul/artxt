#pragma once 
#include "Event.hpp"

namespace sdlw {
	class Window;
	struct Drawer;

	class Renderer {

	private:

		SDL_Renderer* _renderer;
		int _delayTimeMs;
		sdlw::Event<Drawer&> _event;

	public:
		Renderer(Window* window);
		~Renderer();

		void Render();
		void setTargetFPS(int fps);

		inline sdlw::Event<Drawer&>& event() {
			return _event;
		}
		inline SDL_Renderer* target() const {
			return _renderer;
		}
	};
}