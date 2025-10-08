#include "sdlw/include/Window.hpp";
#include "sdlw/include/Renderer.hpp"

#include <unordered_map>
#include <vector>
#include <functional>

namespace sdlw {

	Window::Window(int width, int height, const char* title, SDL_WindowFlags flags) {

		_window = SDL_CreateWindow(title, width, height, flags);
		_event = SDL_Event();
	}

	Window::~Window() {
		SDL_DestroyWindow(_window);
	}

	const SDL_Window* Window::getWindow() const {
		return _window;
	}

	Callback* Window::CreateCallback(Uint32 eventType, Callback::fnType function) {
		
		Callback* callback = new Callback(eventType, function);
		_eventMap[eventType].push_back(callback);
		return callback;
	}

	void Window::DeleteCallback(Callback* callback) {
		auto& vec = _eventMap[callback->getEventType()];
		
		for (auto it = vec.begin(); it != vec.end(); it++) {

			if (callback == *it) {
				vec.erase(it);
				delete callback;
				return;
			}
		}
	}

	void Window::PollEvents() {
		while (SDL_PollEvent(&_event)) {
			auto& vec = _eventMap[_event.type];

			for (auto& it : vec) {
				it->Invoke(&_event);
			}
		}
	}
}