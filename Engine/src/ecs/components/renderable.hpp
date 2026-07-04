#pragma once

#include "math/color.hpp"

struct Renderable {
	int z_order = 0;
	Color modulation = Color::WHITE;
};