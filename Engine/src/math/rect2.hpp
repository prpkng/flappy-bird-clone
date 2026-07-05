#pragma once

#include "math/vector2.hpp"

struct [[nodiscard]] Rect2 {
	Rect2() : position(Vector2::ZERO), size(Vector2::ZERO) {}
	constexpr Rect2(float x, float y, float width, float height) : position(Vector2(x, y)), size(Vector2(width, height)) {}
	constexpr Rect2(const Vector2& pos, const Vector2& size) : position(pos), size(size) {}

	union {
		struct {
			Vector2 position;
			Vector2 size;
		};

		struct {
			float x;
			float y;
			float width;
			float height;
		};
	};


	inline float area() const { return width * height; }
	inline bool has_area() const { return width > 0.0f && height > 0.0f; }
	inline Vector2 center() const { return position + size/2.0f; }

	inline Vector2 end() const { return position + size; }


	inline Vector2 top_left() const { return position; }
	inline Vector2 top_right() const { return position + Vector2::RIGHT * width; }
	inline Vector2 bottom_left() const { return position + Vector2::DOWN * height; }
	inline Vector2 bottom_right() const { return end(); }

	bool intersects(const Rect2& other, bool include_borders = false) const;
	bool intersects_segment(const Vector2& from, const Vector2& to) const;

	bool encloses(const Rect2& other) const;

	Rect2 intersection(const Rect2& other) const;
	Rect2 merge(const Rect2& other) const;

	bool has_point(const Vector2& point) const;
	
	bool is_equal_approx(const Rect2& other) const;
	bool is_same(const Rect2& other) const;
	bool is_finite() const;
	inline bool is_negative() const { return width < 0 || height < 0; }
	
	constexpr bool operator ==(const Rect2& other) const 
	{
		return position == other.position && size == other.size;
	}

	constexpr bool operator !=(const Rect2& other) const
	{
		return position != other.position || size != other.size;
	}

	Rect2 grown(float amount) const;
	Rect2 grow_side(Side side, float amount) const;
	Rect2 grow_individual(float left, float right, float top, float bottom) const;
	void grow_by(float amount);

	Rect2 expand(const Vector2& point) const;
	void expand_to(const Vector2& point);

	inline Rect2 abs() const { return Rect2(position + size.minf(0.0f), size.abs()); }
	inline Rect2 round() const { return Rect2(position.round(), size.round()); }
	
	std::string to_string() const;
	


};