#pragma once
#include <vector>

#include "Method.hpp"
#include "Delegate.hpp"
#include "Function.hpp"

namespace sdlw {

	//template<typename R, typename... Args>
	//struct Delegate {
	//	virtual R invoke(Args... args) const = 0;
	//	virtual ~Delegate() = default;
	//	virtual bool operator==(const Delegate<R, Args...>& other) const = 0;
	//};

	////class method
	//template<typename T, typename R, typename... Args>
	//struct Method : Delegate<R, Args...> {
	//	
	//public:
	//	using function_ptr = R(T::*)(Args...);

	//private: 
	//	T* _obj;
	//	function_ptr _funcPtr;

	//public:
	//	Method(T* obj, function_ptr _funcPtr) : _obj(obj), _funcPtr(_funcPtr) { }

	//	R invoke(Args... args) const override {
	//		return (_obj->*_funcPtr)(args...);
	//	}

	//	bool operator==(const Delegate<R, Args...>& other) const override {
	//		if (auto o = dynamic_cast<const Method*>(&other)) {
	//			return _obj == o->obj && _funcPtr == o->_funcPtr;
	//		}
	//		return false;
	//	}
	//};

	////static function
	//template<typename R, typename... Args>
	//struct Function : Delegate<R, Args...> {
	//public:
	//	using function_ptr = R(*)(Args...);

	//private:
	//	function_ptr _funcPtr;

	//public:
	//	Function(function_ptr funcPtr) : _funcPtr(funcPtr) {}

	//	R invoke(Args... args) const override {
	//		return _funcPtr(args...);
	//	}

	//	bool operator==(const Delegate<R, Args...>& other) const override {
	//		if (auto o = dynamic_cast<const Function*>(&other)) {
	//			return _funcPtr == o->_funcPtr;
	//		}
	//		return false;
	//	}

	//	bool operator==(const Function& other) const {
	//		return _funcPtr == other._funcPtr;
	//	}
	//	bool operator==(function_ptr& other) {
	//		return _funcPtr == other;
	//	}
	//};

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