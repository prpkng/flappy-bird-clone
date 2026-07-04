#include "math.hpp"

double Math::snapped(double value, double step)
{
	return step == 0 ? value : (Math::floor(value / step + 0.5) * step);
}

float Math::snappedf(float value, float step)
{
	return step == 0 ? value : (Math::floorf(value / step + 0.5f) * step);
}

float Math::deg_to_rad(float a) {
	return a * (PI / 180.0f);
}

float Math::rad_to_deg(float a) {
	return a * (180.0f / PI);
}

bool Math::is_nan(float p_val) {
	return std::isnan(p_val);
}

bool Math::is_equal_approx(float lvalue, float rvalue, float tolerance) {
	if (lvalue == rvalue) return true;
	return abs(lvalue - rvalue) < tolerance;
}

bool Math::is_equal_approx(float lvalue, float rvalue) {
	if (lvalue == rvalue) return true;
	float tolerance = MIN(CMP_EPSILON, CMP_EPSILON * abs(lvalue));
	return abs(lvalue - rvalue) < tolerance;
}

bool Math::is_zero_approx(float lvalue, float tolerance) {
	if (lvalue == 0) return true;
	return abs(lvalue) < tolerance;
}

bool Math::is_zero_approx(float lvalue) {
	if (lvalue == 0) return true;
	float tolerance = MIN(CMP_EPSILON, CMP_EPSILON * abs(lvalue));
	return abs(lvalue) < tolerance;
}

bool Math::is_equal(float left, float right) {
	return (left == right) || (is_nan(left) && is_nan(right));
}

bool Math::is_finite(float p_val) {
	return std::isfinite(p_val);
}
