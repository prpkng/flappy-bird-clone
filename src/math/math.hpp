#pragma once

#include "math/math_defs.hpp"

#include <cmath>

namespace Math {


	inline float abs(float x) {
		return std::abs(x);
	}

	inline double floor(double x) {
		return std::floor(x);
	}

	inline double ceil(double x) {
		return std::ceil(x);
	}

	inline double round(double x) {
		return std::round(x);
	}

	inline float floorf(float x) {
		return std::floorf(x);
	}

	inline float ceilf(float x) {
		return std::ceilf(x);
	}

	inline float roundf(float x) {
		return std::roundf(x);
	}

	inline int floori(float x) {
		return static_cast<int>(std::floor(x));
	}

	inline int ceili(float x) {
		return static_cast<int>(std::ceil(x));
	}

	inline int roundi(float x) {
		return static_cast<int>(std::round(x));
	}


	inline float sqrt(float x) {
		return std::sqrt(x);
	}

	double snapped(double value, double step);
	float snappedf(float value, float step);

	float deg_to_rad(float a);
	float rad_to_deg(float a);
	bool is_nan(float p_val);

	
	bool is_equal_approx(float lvalue, float rvalue, float tolerance);
	bool is_equal_approx(float lvalue, float rvalue);

	bool is_zero_approx(float lvalue, float tolerance);
	bool is_zero_approx(float lvalue);

	bool is_equal(float left, float right);
	bool is_finite(float p_val);
}