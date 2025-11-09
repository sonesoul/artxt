#pragma once 
#include "callable/Event.hpp"

namespace sdlw {
	class Window;
	struct Drawer;

	class Renderer {

	private:

		SDL_Renderer* _renderer;
		sdlw::Event<Drawer&> _event;

	public:
		Renderer(Window* window);
		~Renderer();

		void Render();
		
		inline sdlw::Event<Drawer&>& event() {
			return _event;
		}
		inline SDL_Renderer* target() const {
			return _renderer;
		}
	};
}