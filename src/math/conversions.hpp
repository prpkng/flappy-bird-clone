#pragma once

#include <SDL3/SDL_pixels.h>
#include "math/color.hpp"

namespace Conversions {

	SDL_Color to_sdl_color(const Color& color);
	Color from_sdl_color(const SDL_Color& color);


}