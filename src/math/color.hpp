#pragma once

#include <string>

enum class ColorHexFormat {
	ThreeDigit,
	FourDigitAlpha,
	SixDigit,
	EightDigitAlpha
};

struct Color {


	Color() : r(1.0), g(1.0), b(1.0), a(1.0) { }
	Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a) {	}

	Color(const std::string& hex);
	Color(unsigned int hex, ColorHexFormat format = ColorHexFormat::EightDigitAlpha);


	std::string to_string() const;

	union {
		struct {
			float r, g, b, a;
		};

		float attr[4];
	};

};

