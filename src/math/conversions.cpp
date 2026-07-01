#include "conversions.hpp"

#include "math/math.hpp"

SDL_Color Conversions::to_sdl_color(const Color& color)
{
    return SDL_Color(
        Math::roundi(color.r * 255.0),
        Math::roundi(color.g * 255.0),
        Math::roundi(color.b * 255.0),
        Math::roundi(color.a * 255.0)
    );
}

Color Conversions::from_sdl_color(const SDL_Color& color)
{
    return Color(
        color.r / 255.0f,
        color.g / 255.0f,
        color.b / 255.0f,
        color.a / 255.0f
    );
}
