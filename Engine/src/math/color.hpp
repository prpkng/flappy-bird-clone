#pragma once

#include "core/defines.hpp"
#include <string>

// Undefine windgi.h TRANSPARENT macro to make room for our transparent color
#ifdef TRANSPARENT
#undef TRANSPARENT
#endif

enum class ColorHexFormat {
	ThreeDigit,
	FourDigitAlpha,
	SixDigit,
	EightDigitAlpha
};

struct Color {
	static const Color RED;
	static const Color GREEN;
	static const Color BLUE;
	static const Color WHITE;
	static const Color BLACK;
	static const Color TRANSPARENT;

	constexpr Color() : r(1.0), g(1.0), b(1.0), a(1.0) { }
	constexpr Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a) {	}

	Color(const std::string& hex);
	Color(unsigned int hex, ColorHexFormat format = ColorHexFormat::EightDigitAlpha);


	std::string to_string() const;

	union {
		struct {
			float r, g, b, a;
		};

		float attr[4];
	};

	_FORCE_INLINE_ bool operator==(const Color& rhs) const {
		return rhs.r == r && rhs.g == g && rhs.b == b && rhs.a == a;
	}

	_FORCE_INLINE_ bool operator!=(const Color& rhs) const {
		return rhs.r != r || rhs.g != g || rhs.b != b || rhs.a != a;
	}

};

inline constexpr Color Color::RED = { 1.0f, 0.0f, 0.0f, 1.0f };
inline constexpr Color Color::GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
inline constexpr Color Color::BLUE = { 0.0f, 0.0f, 1.0f, 1.0f };
inline constexpr Color Color::WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };
inline constexpr Color Color::BLACK = { 0.0f, 0.0f, 0.0f, 1.0f };
inline constexpr Color Color::TRANSPARENT = { 0.0f, 0.0f, 0.0f, 0.0f };
