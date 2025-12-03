#pragma once
#include <memory>
#include "sdlw/structures/Point.h"

namespace editor {

	class CharBuffer {

		uint8_t _width, _height;
		uint16_t _length;
		std::unique_ptr<char[]> _buffer;
	
	public: 
		CharBuffer(uint8_t w, uint8_t h) :
			_width(w),
			_height(h),
			_length(uint16_t(w)* h),
			_buffer(std::make_unique<char[]>(_length)) {
			Fill(' ');
		}

		inline void Fill(char c) {
			std::memset(_buffer.get(), c, _length);
		}

		inline char& at(uint8_t x, uint8_t y) {
			return _buffer[size_t(y) * _width + x];
		}

		inline sdlw::Point size() {
			return sdlw::Point(_width, _height);
		}
		inline uint16_t length() const {
			return _length;
		}	
	};
}