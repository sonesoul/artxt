#pragma once
#include "SDL3/SDL.h"

namespace sdlw {

	class Time {

	public:
		static constexpr Uint16 TARGET_FPS = 60;
		static constexpr double TARGET_FRAME_TIME_MS = 1000.0 / TARGET_FPS;
		static constexpr double TARGET_FRAME_TIME_S = 1.0 / TARGET_FPS;

	private:
		static Uint64 _lastTime;
		static Uint64 _frequency;
		static double _deltaTime;

	public:
		Time() = delete;

		static void Update();

		static inline double delta() {
			return _deltaTime;
		}
		
	private:
		static inline double getFrameTime(Uint64 counter) {
			return (double)(counter - _lastTime) / _frequency;
		}

		static inline Uint64 getCounter() {
			return SDL_GetPerformanceCounter();
		}
	};
}