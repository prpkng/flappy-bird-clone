#pragma once

#include "math/rect2.hpp"
#include "math/color.hpp"

struct PhysicsObject {
	unsigned int layers = 0b0001;
	unsigned int mask = 0b0001;
	Vector2 velocity;
};

struct CollisionShape {
	Rect2 bounding_box;
	Color debug_color;
};