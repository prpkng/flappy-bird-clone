#pragma once

#include "math/math.hpp"
#include "error/assertions.hpp"

struct [[nodiscard]] Vector2
{
	static const Vector2 LEFT;
	static const Vector2 RIGHT;
	static const Vector2 UP;
	static const Vector2 DOWN;
	static const Vector2 ONE;
	static const Vector2 ZERO;

	static constexpr int AXIS_COUNT = 2;
	
	constexpr Vector2() : x(0), y(0) { }
	constexpr Vector2(float x, float y) : x(x), y(y) { }

	enum Axis {
		AXIS_X,
		AXIS_Y
	};

	union {
		struct {
			float x;
			float y;
		};

		struct {
			float width;
			float height;
		};

		float coord[2] = {0};
	};

	inline float& operator[](int axis) {
		DEV_ASSERT((unsigned int)axis < 2)
		return coord[axis];
	}

	inline const float& operator[](int axis) const {
		DEV_ASSERT((unsigned int)axis < 2)
		return coord[axis];
	}

	inline const Vector2::Axis min_axis_index() const {
		return x < y ? Vector2::AXIS_X : Vector2::AXIS_Y;
	}

	inline const Vector2::Axis max_axis_index() const {
		return x > y ? Vector2::AXIS_X : Vector2::AXIS_Y;
	}

	void normalize();
	
	Vector2 normalized() const;
	bool is_normalized() const;

	float length() const;
	float length_squared() const;
	Vector2 limit_length(float max_len = 1.0) const;

	void zero() { x = y = 0.0f; }

	Vector2 min(const Vector2& vec2) const {
		return Vector2(MIN(x, vec2.x), MIN(y, vec2.y));
	}

	Vector2 max(const Vector2& vec2) const {
		return Vector2(MAX(x, vec2.x), MAX(y, vec2.y));
	}

	Vector2 min(float scalar) const {
		return Vector2(MIN(x, scalar), MIN(y, scalar));
	}

	Vector2 max(float scalar) const {
		return Vector2(MAX(x, scalar), MAX(y, scalar));
	}

	// float distance_to(const Vector2& point) const;
	// float distance_squared_to(const Vector2& point) const;
	// float angle_to(const Vector2& point) const;
	// float angle_to_point(const Vector2& point) const;
	// float direction_to(const Vector2& point) const;


	 bool is_equal_approx(const Vector2& v) const;
	 bool is_equal(const Vector2& v) const;
	 bool is_zero_approx() const;
	 bool is_finite() const;


	// === OPERATORS ===
	constexpr Vector2 operator+(const Vector2& v) const;
	constexpr void operator+=(const Vector2& v);
	constexpr Vector2 operator-(const Vector2& v) const;
	constexpr void operator-=(const Vector2& v);
	constexpr Vector2 operator*(const Vector2& v) const;

	constexpr Vector2 operator*(float rvalue) const;
	constexpr void operator*=(float rvalue);
	constexpr void operator*=(const Vector2& rvalue) { *this = *this * rvalue; }

	constexpr Vector2 operator/(const Vector2& v) const;

	constexpr Vector2 operator/(float rvalue) const;

	constexpr void operator/=(float rvalue);
	constexpr void operator/=(const Vector2& rvalue) { *this = *this / rvalue; }

	constexpr Vector2 operator-() const;

	constexpr bool operator==(const Vector2& vec2) const;
	constexpr bool operator!=(const Vector2& vec2) const;

	constexpr bool operator<(const Vector2& vec2) const { return x == vec2.x ? (y < vec2.y) : (x < vec2.x); }
	constexpr bool operator>(const Vector2& vec2) const { return x == vec2.x ? (y > vec2.y) : (x > vec2.x); }
	constexpr bool operator<=(const Vector2& vec2) const { return x == vec2.x ? (y <= vec2.y) : (x < vec2.x); }
	constexpr bool operator>=(const Vector2& vec2) const { return x == vec2.x ? (y >= vec2.y) : (x > vec2.x); }

};

inline constexpr Vector2 Vector2::LEFT = { -1, 0 };
inline constexpr Vector2 Vector2::RIGHT = { 1, 0 };
inline constexpr Vector2 Vector2::UP = { 0, -1 };
inline constexpr Vector2 Vector2::DOWN = { 0, 1 };
inline constexpr Vector2 Vector2::ONE = { 1, 1 };
inline constexpr Vector2 Vector2::ZERO = { 0, 0 };
