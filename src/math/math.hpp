#pragma once

#include "math/math_defs.hpp"

#include <cmath>

namespace Math {


	inline float abs(float x) {
		return std::abs(x);
	}

	inline float sqrt(float x) {
		return std::sqrt(x);
	}

	inline float deg_to_rad(float a) {
		return a * (PI / 180.0f);
	}

	inline float rad_to_deg(float a){
		return a * (180.0f / PI);
	}

	inline bool is_nan(float p_val) {
		return std::isnan(p_val);
	}

	
	inline bool is_equal_approx(float lvalue, float rvalue, float tolerance) {
		if (lvalue == rvalue) return true;
		return abs(lvalue - rvalue) < tolerance;
	}

	inline bool is_equal_approx(float lvalue, float rvalue) {
		if (lvalue == rvalue) return true;
		float tolerance = MIN(CMP_EPSILON, CMP_EPSILON * abs(lvalue));
		return abs(lvalue - rvalue) < tolerance;
	}


	inline bool is_zero_approx(float lvalue, float tolerance) {
		if (lvalue == 0) return true;
		return abs(lvalue) < tolerance;
	}

	inline bool is_zero_approx(float lvalue) {
		if (lvalue == 0) return true;
		float tolerance = MIN(CMP_EPSILON, CMP_EPSILON * abs(lvalue));
		return abs(lvalue) < tolerance;
	}


	inline bool is_equal(float left, float right) {
		return (left == right) || (is_nan(left) && is_nan(right));
	}

	inline bool is_finite(float p_val) {
		return std::isfinite(p_val);
	}
}