#include "rect2.hpp"

bool Rect2::intersects(const Rect2& other, bool include_borders) const
{
	if (is_negative() || other.is_negative()) {
		LOG_ERROR("Cannot check intersection between negative rects!");
		return false;
	}

	if (position.x > (other.position.x + other.size.width)
		|| (position.x + size.width) < other.position.x
		|| position.y > (other.position.y + other.size.height)
		|| (position.y + size.height) < other.position.y) {
		return false;
	}

	return true;
}

bool Rect2::intersects_segment(const Vector2& from, const Vector2& to) const
{
    return false;
}

bool Rect2::encloses(const Rect2& other) const
{
    return false;
}

Rect2 Rect2::intersection(const Rect2& other) const
{
	return Rect2();
}

Rect2 Rect2::merge(const Rect2& other) const
{
	return Rect2();
}

bool Rect2::has_point(const Vector2& point) const
{
    return false;
}

bool Rect2::is_equal_approx(const Rect2& other) const
{
    return false;
}

bool Rect2::is_same(const Rect2& other) const
{
    return false;
}
