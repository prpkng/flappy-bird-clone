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

Rect2 Rect2::grown(float amount) const
{
	Rect2 other = *this;
	other.grow_by(amount);
	return other;
}

Rect2 Rect2::grow_side(Side side, float amount) const
{
	Rect2 other = *this;
	switch (side) {
	case Side::Left:
		other.x -= amount;
		other.width += amount;
		break;
	case Side::Right:
		other.width += amount;
		break;
	case Side::Top:
		other.y -= amount;
		other.height += amount;
		break;
	case Side::Bottom:
		other.height += amount;
		break;
	}
	return other;
}

Rect2 Rect2::grow_individual(float left, float right, float top, float bottom) const
{
	Rect2 other = *this;
	other.x -= left;
	other.width += left + right; 
	other.y -= top; 
	other.height += top + bottom; 
	return other;
}

void Rect2::grow_by(float amount)
{
	position -= Vector2::ONE*amount;
	size += Vector2::ONE*2*amount;
}
