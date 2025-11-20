#pragma once 
#include "wtypes.h"
#include "callable/Event.hpp"
#include "Color.h"
#include "Drawer.h"
#include "SDLHolder.hpp"

namespace sdlw {
	class Window;
	class Surface;
	class Texture;

	class Renderer : public SDLHolder<SDL_Renderer, SDL_DestroyRenderer> {

	private:
		Event<Drawer&> _event;
		Drawer _drawer;

		using SDLHolder::SDLHolder;

	public:
		Color background;

	public:
		Renderer(Window* window);
		
		void Render();
		
		Texture* CreateTexture(Surface* surface);
		
		inline Event<Drawer&>& event() {
			return _event;
		}
	};
}