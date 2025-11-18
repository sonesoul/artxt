#pragma once 
#include "callable/Event.hpp"
#include "Color.h"
#include "Drawer.h"

namespace sdlw {
	class Window;
	
	class Renderer {

	private:

		SDL_Renderer* _renderer;
		Event<Drawer&> _event;
		Drawer _drawer;

	public:
		Color background;

	public:
		Renderer(Window* window);
		~Renderer();

		void Render();
		
		inline Event<Drawer&>& event() {
			return _event;
		}
		inline SDL_Renderer* target() const {
			return _renderer;
		}
	};
}