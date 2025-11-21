#include "sdlw/sdlw.h"
#include "sdlw/Time.h"
#include "sdlw/Drawer.h"

class Application {

	static constexpr char* const APP_NAME = "artxt";
	static constexpr SDL_WindowFlags WINDOW_FLAGS = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

	sdlw::Window* _window;
	sdlw::Renderer* _renderer;

	bool _quit;

public:
	Application();

	void Run();
	void Quit();

private:
	
	void OnEvent(const SDL_Event*);
};