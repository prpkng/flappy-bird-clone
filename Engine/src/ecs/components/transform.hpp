#pragma once

#include "math/vector2.hpp"

struct Transform {
	Vector2 position{};
	Vector2 scale{1, 1};
	float rotation{};

	void set_rotation_degrees(float deg) {
		rotation = Math::deg_to_rad(deg);
	}

	[[nodiscard]] float get_rotation_degrees() const {
		return Math::rad_to_deg(rotation);
	}
};