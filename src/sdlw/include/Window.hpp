#pragma once
#include "SDL3/SDL.h"
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>

namespace sdlw {

	
	class Renderer;

	//function that handles SDL event 
	class Callback {
	public:
		using fnType = std::function<void(const SDL_Event*)>;

	private:

		fnType _function;
		Uint32 _eventType;

	public:
		Callback(Uint32 type, fnType func) : _eventType(type), _function(func) {}

		inline void Invoke(const SDL_Event* event) {
			_function(event);
		}

		inline Uint32 getEventType() const {
			return _eventType;
		}
		inline fnType getFunction() const {
			return _function;
		}
	};

	class Window {

	private:

		SDL_Window* _window;
		SDL_Event _event;
		std::unordered_map<Uint32, std::vector<Callback*>> _eventMap;

	public:
		Window(int width, int height, const char* title, SDL_WindowFlags flags);
		~Window();
		
		Callback* CreateCallback(Uint32 eventType, Callback::fnType func);
		void DeleteCallback(Callback* callback);
		void PollEvents();

		const SDL_Window* getWindow() const;
	};
}