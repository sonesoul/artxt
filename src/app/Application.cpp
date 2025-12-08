#include "app/Application.hpp"
#include "sdlw/Time.h"
#include "sdlw/Renderer.hpp"
#include "SDL3_ttf/SDL_ttf.h"

using sdlw::Time;

Application::Application() :
	_window(new sdlw::Window(256, 256, APP_NAME, WINDOW_FLAGS)),
	_renderer(new sdlw::Renderer(_window)),
	_quit(false) {

	TTF_Init();

	_window->event(SDL_EVENT_QUIT).Add(*this, &Application::OnEvent);
	_window->event(SDL_EVENT_KEY_DOWN).Add(*this, &Application::OnEvent);
}

void Application::Run() {
	
	while (!_quit) {

		_window->PollEvents();
		_renderer->Render();

		Time::Update();
	}
}

void Application::Quit() {
	_quit = true;
}

void Application::OnEvent(const SDL_Event& e) { 
	if (e.type == SDL_EVENT_QUIT || e.key.scancode == SDL_SCANCODE_F1)
		Quit();
}