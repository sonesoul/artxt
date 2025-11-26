#pragma once 
#include "wtypes.h"
#include "callable/Event.hpp"
#include "structures/Color.h"
#include "Drawer.h"
#include "UniqueResource.hpp"

namespace sdlw {
	class Window;
	class Surface;
	class Texture;

	class Renderer : public UniqueResource<SDL_Renderer, SDL_DestroyRenderer> {

	private:
		Event<Drawer&> _event;
		Drawer _drawer;

		using UniqueResource::UniqueResource;

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