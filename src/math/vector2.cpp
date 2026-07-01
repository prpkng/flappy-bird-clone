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
    if (l > 0 && max_len < l) {
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




Vector2 Vector2::sign() const {
    return Vector2(SIGN(x), SIGN(y));
}

Vector2 Vector2::floor() const {
    return Vector2(Math::floorf(x), Math::floorf(y));
}

Vector2 Vector2::ceil() const {
    return Vector2(Math::ceilf(x), Math::ceilf(y));
}

Vector2 Vector2::round() const {
    return Vector2(Math::roundf(x), Math::roundf(y));
}

Vector2 Vector2::snapped(const Vector2& by) const {
    return Vector2(Math::snapped(x, by.x), Math::snapped(y, by.y));
}

Vector2 Vector2::snappedf(float by) const {
    return Vector2(Math::snapped(x, by), Math::snapped(y, by));
}

Vector2 Vector2::clamp(const Vector2& min, const Vector2& max) const {
    return Vector2(
        CLAMP(x, min.x, max.x),
        CLAMP(y, min.y, max.y)
    );
}

Vector2 Vector2::clampf(float min, float max) const {
    return Vector2(
        CLAMP(x, min, max),
        CLAMP(y, min, max)
    );
    
}



