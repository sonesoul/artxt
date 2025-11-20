#pragma once
#include "wtypes.h"
#include <memory>

namespace sdlw {
	template<typename T, void(*D)(T*)>
	class SDLHolder {

	protected:
		std::unique_ptr<T, decltype(D)> _item;

		SDLHolder(T* item) : 
			_item(item, D) {
		}

		virtual ~SDLHolder() = default;

		SDLHolder(const SDLHolder&) = delete;
		SDLHolder& operator=(const SDLHolder&) = delete;

	public:
		inline T* raw() const {
			return _item.get();
		}
	};
}