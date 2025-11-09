#pragma once
#include <vector>
#include "Method.hpp"
#include "Delegate.hpp"
#include "Function.hpp"
#include <memory>

namespace sdlw {

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
		void add(T* obj, method_ptr<T> funcPtr) {
			_add(std::make_shared<method<T>>(obj, funcPtr));
		}
		void add(func_ptr funcPtr) {
			_add(std::make_shared<function>(funcPtr));
		}

		template<typename T>
		void remove(T* obj, method_ptr<T> funcPtr) {
			_remove(std::make_shared<method<T>>(obj, funcPtr));
		}
		void remove(func_ptr funcPtr) {
			_remove(std::make_shared<function>(funcPtr));
		}

		void invoke(Args... args) const {
			for (auto& item : _listeners) {
				item->invoke(args...);
			}
		}

	private: 
		void _add(delegate_ptr target) {
			_listeners.push_back(target);
		}
		void _remove(delegate_ptr target) {

			for (auto& it = _listeners.begin(); it != _listeners.end(); ++it) {

				if (*it == target) {
					_listeners.erase(it);
					break;
				}
			}
		}
	};
}