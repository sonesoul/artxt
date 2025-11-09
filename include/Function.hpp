#pragma once
#include "Delegate.hpp"

namespace sdlw {
	template<typename R, typename... Args>
	struct Function : Delegate<R, Args...> {
	public:
		using function_ptr = R(*)(Args...);

	private:
		function_ptr _funcPtr;

	public:
		Function(function_ptr funcPtr) : _funcPtr(funcPtr) {}

		R Invoke(Args... args) const override {
			return _funcPtr(args...);
		}

		bool operator==(const Delegate<R, Args...>& other) const override {
			if (auto o = dynamic_cast<const Function*>(&other)) {
				return *this == *o;
			}
			return false;
		}

		bool operator==(const Function& other) const {
			return _funcPtr == other._funcPtr;
		}
		bool operator==(function_ptr& other) {
			return _funcPtr == other;
		}
	};

}