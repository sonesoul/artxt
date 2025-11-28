#include "sdlw/Time.h"

using namespace sdlw;

Uint64 Time::_frequency = SDL_GetPerformanceFrequency();
Uint64 Time::_lastTime = performanceCounter();
double Time::_deltaTime = 0.0;

void Time::Update() {
	Uint64 counter = performanceCounter();
	double frameTime = elapsed(counter);
	
	if (frameTime < TARGET_FRAME_TIME_S) {
		SDL_Delay((TARGET_FRAME_TIME_S - frameTime) * 1000);
	}

	counter = performanceCounter();
	_deltaTime = elapsed(counter);
	_lastTime = counter;
}