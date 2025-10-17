#pragma once
#include <vector>

#include "Method.hpp"
#include "Delegate.hpp"
#include "Function.hpp"

namespace sdlw {

	template<typename... Args>
	class Event {

	private:

		using delegate = Delegate<void, Args...>;

		using function = Function<void, Args...>;
		using func_ptr = typename function::function_ptr;
		
		template<typename T>
		using method = typename Method<T, void, Args...>;

		template<typename T>
		using method_ptr = typename method<T>::function_ptr;

		std::vector<delegate*> _listeners;

	public:
		
		Event() {
			_listeners = std::vector<delegate*>();
		}
		~Event() {
			for (auto* d : _listeners)
				delete d;
			_listeners.clear();
		}

		template<typename T> 
		void add(T* obj, method_ptr<T> funcPtr) {
			_add(new method(obj, funcPtr));
		}
		void add(func_ptr funcPtr) {
			_add(new function(funcPtr));
		}

		template<typename T>
		void remove(T* obj, method_ptr<T> funcPtr) {
			auto m = method(obj, funcPtr);
			_remove(&m);
		}
		void remove(func_ptr funcPtr) {
			auto f = function(funcPtr);
			_remove(&f);
		}

		void invoke(Args... args) {
			for (auto& item : _listeners) {
				item->invoke(args...);
			}
		}

	private: 
		void _add(delegate* target) {
			_listeners.push_back(target);
		}
		void _remove(delegate* target) {
			for (auto it = _listeners.begin(); it != _listeners.end(); ++it) {

				auto item = *it;

				if (*item == *target) {
					_listeners.erase(it);
					delete item;
					break;
				}
			}
		}
	};
}