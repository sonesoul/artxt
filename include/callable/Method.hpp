#pragma once
#include "Delegate.hpp"

template<typename T, typename R, typename... Args>
struct Method : Delegate<R, Args...> {
public:
	using function_ptr = R(T::*)(Args...);

private:
	T& _obj;
	function_ptr _funcPtr;

public:
	Method(T& obj, function_ptr _funcPtr) : _obj(obj), _funcPtr(_funcPtr) {}

	R Invoke(Args... args) const override {
		return (_obj.*_funcPtr)(args...);
	}

	bool operator==(const Delegate<R, Args...>& other) const override {
		if (auto o = dynamic_cast<const Method*>(&other)) {
			return *this == *o;
		}
		return false;
	}
	bool operator==(const Method& other) const {
		return &_obj == &other._obj && _funcPtr == other._funcPtr;
	}
};