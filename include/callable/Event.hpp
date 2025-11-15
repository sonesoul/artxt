#pragma once
#include <vector>
#include <memory>
#include "Method.hpp"
#include "Delegate.hpp"
#include "Function.hpp"

template<typename... Args>
class Event {

private:

	using delegate_ptr = std::shared_ptr<Delegate<void, Args...>>;

	using function = Function<void, Args...>;
	using func_ptr = typename function::function_ptr;

	template<typename T>
	using method = typename Method<T, void, Args...>;

	template<typename T>
	using method_ptr = typename method<T>::function_ptr;

	std::vector<delegate_ptr> _listeners;

public:

	Event() {
		_listeners = std::vector<delegate_ptr>();
	}
	~Event() {
		_listeners.clear();
	}

	template<typename T>
	void Add(T& obj, method_ptr<T> funcPtr) {
		AddListener(std::make_shared<method<T>>(obj, funcPtr));
	}
	void Add(func_ptr funcPtr) {
		AddListener(std::make_shared<function>(funcPtr));
	}

	template<typename T>
	void Remove(T& obj, method_ptr<T> funcPtr) {
		RemoveListener(std::make_shared<method<T>>(obj, funcPtr));
	}
	void Remove(func_ptr funcPtr) {
		RemoveListener(std::make_shared<function>(funcPtr));
	}

	void Invoke(Args... args) const {
		for (auto& item : _listeners) {
			item->Invoke(args...);
		}
	}

private:
	void AddListener(const delegate_ptr& targetPtr) {
		_listeners.push_back(targetPtr);
	}
	void RemoveListener(const delegate_ptr& targetPtr) {

		auto& target = *targetPtr;

		for (auto& it = _listeners.begin(); it != _listeners.end(); ++it) {
			delegate_ptr& delegatePtr = *it;
			auto& current = *delegatePtr;

			if (current == target) {
				_listeners.erase(it);
				break;
			}
		}
	}
};