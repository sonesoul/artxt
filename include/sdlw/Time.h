#pragma once
#include "SDL3/SDL.h"

namespace sdlw {

	class Time {

		static constexpr Uint16 TARGET_FPS = 60;
		static constexpr double TARGET_FRAME_TIME_MS = 1000.0 / TARGET_FPS;

		static Uint64 _lastTime;
		static Uint64 _frequency;
		static double _deltaTime;

	public:

		Time() = delete;

		static void Update();

		static inline double delta() {
			return _deltaTime;
		}
	};
}