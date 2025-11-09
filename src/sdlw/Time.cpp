#include "sdlw/Time.h"

using namespace sdlw;

static inline Uint64 getCounter() {
	return SDL_GetPerformanceCounter();
}

Uint64 Time::_frequency = SDL_GetPerformanceFrequency();
Uint64 Time::_lastTime = getCounter();
double Time::_deltaTime = 0.0;

void Time::Update() {
	Uint64 counter = getCounter();
	double frameTime = (double)(counter - _lastTime) / _frequency;

	const double target = TARGET_FRAME_TIME_MS / 1000.0;

	while (frameTime < target) {
		counter = getCounter();
		frameTime = (double)(counter - _lastTime) / _frequency;
	}

	_lastTime = counter;
	_deltaTime = frameTime;
}