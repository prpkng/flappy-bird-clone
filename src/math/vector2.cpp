#include "Vector2.hpp"

float Vector2::length_squared() const
{
    return x * x + y * y;
}

float Vector2::length() const
{
    return Math::sqrt(x * x + y * y);
}


void Vector2::normalize()
{
    if (!is_finite()) {
        // Infinite vector cannot be normalized

        zero();
        return;
    }

    float l = length_squared();
    if (l == 0) {
        zero();
        return;
    }
    l = Math::sqrt(l);
    x /= l;
    y /= l;
}

Vector2 Vector2::normalized() const
{
    Vector2 v = *this;
    v.normalize();
    return v;
}

bool Vector2::is_normalized() const
{
    return Math::is_equal_approx(length_squared(), 1.0, (float)UNIT_EPSILON);
}

Vector2 Vector2::limit_length(float max_len) const
{
    const float l = length();
    Vector2 v = *this;
    if (l > 0 && max_len < 1) {
        v /= l;
        v *= max_len;
    }

    return v;
}


bool Vector2::is_equal_approx(const Vector2& v) const
{
    return Math::is_equal_approx(x, v.x) && Math::is_equal_approx(y, v.y);
}

bool Vector2::is_equal(const Vector2& v) const
{
    return Math::is_equal(x, v.x) && Math::is_equal(y, v.y);
}

bool Vector2::is_zero_approx() const
{
    return Math::is_zero_approx(x) && Math::is_zero_approx(y);
}

bool Vector2::is_finite() const
{
    return Math::is_finite(x) && Math::is_finite(y);
}

constexpr Vector2 Vector2::operator+(const Vector2& v) const
{
    return Vector2(x + v.x, y + v.y);
}

constexpr void Vector2::operator+=(const Vector2& v)
{
    x += v.x; y += v.y;
}

constexpr Vector2 Vector2::operator-(const Vector2& v) const
{
    return Vector2(x - v.x, y - v.y);
}

constexpr void Vector2::operator-=(const Vector2& v)
{
    x -= v.x; y -= v.y;
}

constexpr Vector2 Vector2::operator*(const Vector2& v) const
{
    return Vector2(x * v.x, y * v.y);
}

constexpr Vector2 Vector2::operator*(float rvalue) const
{
    return Vector2(x * rvalue, y * rvalue);
}

constexpr void Vector2::operator*=(float rvalue)
{
    x *= rvalue; y *= rvalue;
}

constexpr Vector2 Vector2::operator/(const Vector2& v) const
{
    return Vector2(x / v.x, y / v.y);
}

constexpr Vector2 Vector2::operator/(float rvalue) const
{
    return Vector2(x / rvalue, y / rvalue);
}

constexpr void Vector2::operator/=(float rvalue)
{
    x /= rvalue; y /= rvalue;
}

constexpr bool Vector2::operator==(const Vector2& v) const
{
    return x == v.x && y == v.y;
}

constexpr bool Vector2::operator!=(const Vector2& v) const
{
    return x != v.x || y != v.y;
}

