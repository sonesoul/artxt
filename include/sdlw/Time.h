#pragma once
#include "SDL3/SDL.h"

static double TARGET_FPS = 60;
static Uint64 TARGET_FRAME_TIME = 1000 / TARGET_FPS;

static Uint64 _frameStart = 0;

static double _deltaTime = 0;

void Time_FrameStart() {
	Uint64 ms = SDL_GetTicks();

	_deltaTime = (ms - _frameStart) / 1000.0;
	_frameStart = ms;
}
void Time_FrameEnd() {
	Uint64 frameTime = SDL_GetTicks() - _frameStart;

	if (frameTime < TARGET_FRAME_TIME) {
		SDL_Delay(TARGET_FRAME_TIME - frameTime);
	}
}

inline double Time_delta() {
	return _deltaTime;
}