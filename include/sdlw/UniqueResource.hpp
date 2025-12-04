#pragma once
#include <memory>

namespace sdlw {
	template<typename T, void(*D)(T*)>
	class UniqueResource {

	protected:
		std::unique_ptr<T, decltype(D)> _item;

		UniqueResource(T* item) : 
			_item(item, D) {
		}

		virtual ~UniqueResource() = default;

		UniqueResource(const UniqueResource&) = delete;
		UniqueResource& operator=(const UniqueResource&) = delete;

	public:
		inline T* raw() const {
			return _item.get();
		}
	};
}