#pragma once

#include "math/rect2.hpp"
#include "math/color.hpp"

struct SDL_Color;
struct SDL_FRect;

namespace Conversions {

	SDL_Color to_sdl_color(const Color& color);
	Color from_sdl_color(const SDL_Color& color);

	SDL_FRect to_sdl_rect(const Rect2& rect);
	Rect2 from_sdl_rect(const SDL_FRect& rect);
}