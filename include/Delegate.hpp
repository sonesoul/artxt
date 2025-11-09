#pragma once

namespace sdlw {
	template<typename R, typename... Args>
	struct Delegate {
		virtual R Invoke(Args... args) const = 0;
		virtual ~Delegate() = default;
		virtual bool operator==(const Delegate<R, Args...>& other) const = 0;
	};
}