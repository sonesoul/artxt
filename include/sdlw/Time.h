#pragma once
#include "SDL3/SDL.h"

static double TARGET_FPS = 60;
static double TARGET_FRAME_TIME = 1000 / TARGET_FPS;

static Uint64 _frameStart = 0;
static Uint64 _lastFrame = 0;

static double _deltaTime = 0;

void FrameTimeStart() {
	Uint64 ms = ticks();

	_deltaTime = 1.0 / ms - _lastFrame;
	_lastFrame = ms;
}
void FrameTimeEnd() {
	Uint64 frameTime = ticks() - _frameStart;

	if (frameTime < TARGET_FRAME_TIME) {
		SDL_Delay(TARGET_FRAME_TIME - frameTime);
	}
}

inline double deltaTime() {
	return _deltaTime;
}

inline Uint64 ticks() {
	return SDL_GetTicks();
}