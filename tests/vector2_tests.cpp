#include <gtest/gtest.h>

#include "math/vector2.hpp"

class MathVector2Test : public ::testing::Test
{
protected:
    static constexpr float EPSILON = 1e-6f;
};

// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, DefaultConstructor)
{
    Vector2 v;
    EXPECT_FLOAT_EQ(v.x, 0.0f);
    EXPECT_FLOAT_EQ(v.y, 0.0f);
}

TEST_F(MathVector2Test, ScalarConstructor)
{
    Vector2 v(5.5f);

    EXPECT_FLOAT_EQ(v.x, 5.5f);
    EXPECT_FLOAT_EQ(v.y, 5.5f);
}

TEST_F(MathVector2Test, XYConstructor)
{
    Vector2 v(2.0f, -3.0f);

    EXPECT_FLOAT_EQ(v.x, 2.0f);
    EXPECT_FLOAT_EQ(v.y, -3.0f);
}

// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, StaticConstants)
{
    EXPECT_EQ(Vector2::ZERO, Vector2(0.0f, 0.0f));
    EXPECT_EQ(Vector2::ONE, Vector2(1.0f, 1.0f));
    EXPECT_EQ(Vector2::LEFT, Vector2(-1.0f, 0.0f));
    EXPECT_EQ(Vector2::RIGHT, Vector2(1.0f, 0.0f));
    EXPECT_EQ(Vector2::UP, Vector2(0.0f, -1.0f));
    EXPECT_EQ(Vector2::DOWN, Vector2(0.0f, 1.0f));
}

// -----------------------------------------------------------------------------
// Indexing
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, IndexOperatorRead)
{
    Vector2 v(3.0f, 4.0f);

    EXPECT_FLOAT_EQ(v[0], 3.0f);
    EXPECT_FLOAT_EQ(v[1], 4.0f);
}

TEST_F(MathVector2Test, IndexOperatorWrite)
{
    Vector2 v;

    v[0] = 8.0f;
    v[1] = -2.0f;

    EXPECT_FLOAT_EQ(v.x, 8.0f);
    EXPECT_FLOAT_EQ(v.y, -2.0f);
}

// -----------------------------------------------------------------------------
// Axis helpers
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, MinAxisIndex)
{
    EXPECT_EQ(Vector2(1.0f, 5.0f).min_axis_index(), Vector2::AXIS_X);
    EXPECT_EQ(Vector2(8.0f, 2.0f).min_axis_index(), Vector2::AXIS_Y);

    // Equal values return Y
    EXPECT_EQ(Vector2(3.0f, 3.0f).min_axis_index(), Vector2::AXIS_Y);
}

TEST_F(MathVector2Test, MaxAxisIndex)
{
    EXPECT_EQ(Vector2(7.0f, 2.0f).max_axis_index(), Vector2::AXIS_X);
    EXPECT_EQ(Vector2(1.0f, 9.0f).max_axis_index(), Vector2::AXIS_Y);

    // Equal values return Y
    EXPECT_EQ(Vector2(4.0f, 4.0f).max_axis_index(), Vector2::AXIS_Y);
}

// -----------------------------------------------------------------------------
// Utility functions
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, Zero)
{
    Vector2 v(4.0f, -9.0f);

    v.zero();

    EXPECT_EQ(v, Vector2::ZERO);
}

TEST_F(MathVector2Test, MinVector)
{
    Vector2 a(2.0f, 8.0f);
    Vector2 b(5.0f, 3.0f);

    EXPECT_EQ(a.min(b), Vector2(2.0f, 3.0f));
}

TEST_F(MathVector2Test, MaxVector)
{
    Vector2 a(2.0f, 8.0f);
    Vector2 b(5.0f, 3.0f);

    EXPECT_EQ(a.max(b), Vector2(5.0f, 8.0f));
}

TEST_F(MathVector2Test, MinScalar)
{
    Vector2 v(5.0f, 2.0f);

    EXPECT_EQ(v.minf(3.0f), Vector2(3.0f, 2.0f));
}

TEST_F(MathVector2Test, MaxScalar)
{
    Vector2 v(5.0f, 2.0f);

    EXPECT_EQ(v.maxf(3.0f), Vector2(5.0f, 3.0f));
}

TEST_F(MathVector2Test, Abs)
{
    Vector2 v(-5.0f, 2.0f);

    EXPECT_EQ(v.abs(), Vector2(5.0f, 2.0f));
}

TEST_F(MathVector2Test, Aspect)
{
    Vector2 v(8.0f, 2.0f);

    EXPECT_FLOAT_EQ(v.aspect(), 4.0f);
}

// -----------------------------------------------------------------------------
// Arithmetic
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, Addition)
{
    Vector2 a(1.0f, 2.0f);
    Vector2 b(3.0f, 4.0f);

    EXPECT_EQ(a + b, Vector2(4.0f, 6.0f));
}

TEST_F(MathVector2Test, AdditionAssignment)
{
    Vector2 a(1.0f, 2.0f);

    a += Vector2(3.0f, 4.0f);

    EXPECT_EQ(a, Vector2(4.0f, 6.0f));
}

TEST_F(MathVector2Test, Subtraction)
{
    Vector2 a(8.0f, 5.0f);
    Vector2 b(3.0f, 1.0f);

    EXPECT_EQ(a - b, Vector2(5.0f, 4.0f));
}

TEST_F(MathVector2Test, SubtractionAssignment)
{
    Vector2 a(8.0f, 5.0f);

    a -= Vector2(3.0f, 1.0f);

    EXPECT_EQ(a, Vector2(5.0f, 4.0f));
}

TEST_F(MathVector2Test, ComponentMultiplication)
{
    Vector2 a(2.0f, 3.0f);
    Vector2 b(4.0f, -2.0f);

    EXPECT_EQ(a * b, Vector2(8.0f, -6.0f));
}

TEST_F(MathVector2Test, ScalarMultiplication)
{
    Vector2 v(2.0f, -3.0f);

    EXPECT_EQ(v * 2.5f, Vector2(5.0f, -7.5f));
}

TEST_F(MathVector2Test, ScalarMultiplicationAssignment)
{
    Vector2 v(2.0f, -3.0f);

    v *= 2.0f;

    EXPECT_EQ(v, Vector2(4.0f, -6.0f));
}

TEST_F(MathVector2Test, ComponentDivision)
{
    Vector2 a(8.0f, 12.0f);
    Vector2 b(2.0f, 3.0f);

    EXPECT_EQ(a / b, Vector2(4.0f, 4.0f));
}

TEST_F(MathVector2Test, ScalarDivision)
{
    Vector2 v(8.0f, 12.0f);

    EXPECT_EQ(v / 4.0f, Vector2(2.0f, 3.0f));
}

TEST_F(MathVector2Test, ScalarDivisionAssignment)
{
    Vector2 v(8.0f, 12.0f);

    v /= 4.0f;

    EXPECT_EQ(v, Vector2(2.0f, 3.0f));
}

// -----------------------------------------------------------------------------
// Comparisons
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, Equality)
{
    EXPECT_TRUE(Vector2(1.0f, 2.0f) == Vector2(1.0f, 2.0f));
    EXPECT_FALSE(Vector2(1.0f, 2.0f) == Vector2(2.0f, 1.0f));
}

TEST_F(MathVector2Test, Inequality)
{
    EXPECT_TRUE(Vector2(1.0f, 2.0f) != Vector2(2.0f, 1.0f));
    EXPECT_FALSE(Vector2(1.0f, 2.0f) != Vector2(1.0f, 2.0f));
}

TEST_F(MathVector2Test, LexicographicalComparison)
{
    EXPECT_LT(Vector2(1.0f, 2.0f), Vector2(2.0f, 0.0f));
    EXPECT_LT(Vector2(1.0f, 2.0f), Vector2(1.0f, 3.0f));

    EXPECT_GT(Vector2(3.0f, 0.0f), Vector2(2.0f, 100.0f));
    EXPECT_GT(Vector2(2.0f, 5.0f), Vector2(2.0f, 4.0f));

    EXPECT_LE(Vector2(1.0f, 2.0f), Vector2(1.0f, 2.0f));
    EXPECT_GE(Vector2(1.0f, 2.0f), Vector2(1.0f, 2.0f));
}

// -----------------------------------------------------------------------------
// Length
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, LengthSquared)
{
    Vector2 v(3.0f, 4.0f);

    EXPECT_FLOAT_EQ(v.length_squared(), 25.0f);
}

TEST_F(MathVector2Test, Length)
{
    Vector2 v(3.0f, 4.0f);

    EXPECT_FLOAT_EQ(v.length(), 5.0f);
}

TEST_F(MathVector2Test, ZeroVectorHasZeroLength)
{
    Vector2 v;

    EXPECT_FLOAT_EQ(v.length(), 0.0f);
    EXPECT_FLOAT_EQ(v.length_squared(), 0.0f);
}

// -----------------------------------------------------------------------------
// Normalize
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, Normalize)
{
    Vector2 v(3.0f, 4.0f);

    v.normalize();

    EXPECT_NEAR(v.x, 0.6f, EPSILON);
    EXPECT_NEAR(v.y, 0.8f, EPSILON);
    EXPECT_TRUE(v.is_normalized());
}

TEST_F(MathVector2Test, NormalizedReturnsNewVector)
{
    Vector2 original(3.0f, 4.0f);

    Vector2 normalized = original.normalized();

    EXPECT_EQ(original, Vector2(3.0f, 4.0f));

    EXPECT_NEAR(normalized.x, 0.6f, EPSILON);
    EXPECT_NEAR(normalized.y, 0.8f, EPSILON);
}

TEST_F(MathVector2Test, NormalizeZeroVector)
{
    Vector2 v;

    v.normalize();

    EXPECT_EQ(v, Vector2::ZERO);
}

TEST_F(MathVector2Test, IsNormalized)
{
    EXPECT_TRUE(Vector2(1.0f, 0.0f).is_normalized());
    EXPECT_TRUE(Vector2(0.0f, -1.0f).is_normalized());

    EXPECT_FALSE(Vector2(3.0f, 4.0f).is_normalized());
}

// -----------------------------------------------------------------------------
// LimitLength
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, LimitLengthNoChange)
{
    Vector2 v(1.0f, 2.0f);

    EXPECT_EQ(v.limit_length(5.0f), v);
}

TEST_F(MathVector2Test, LimitLengthScalesVector)
{
    Vector2 v(6.0f, 8.0f);

    Vector2 limited = v.limit_length(5.0f);

    EXPECT_NEAR(limited.length(), 5.0f, EPSILON);
    EXPECT_NEAR(limited.x, 3.0f, EPSILON);
    EXPECT_NEAR(limited.y, 4.0f, EPSILON);
}

TEST_F(MathVector2Test, LimitLengthZeroVector)
{
    EXPECT_EQ(Vector2::ZERO.limit_length(2.0f), Vector2::ZERO);
}

// -----------------------------------------------------------------------------
// Equality helpers
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, IsEqual)
{
    EXPECT_TRUE(Vector2(1.0f, 2.0f).is_equal(Vector2(1.0f, 2.0f)));
    EXPECT_FALSE(Vector2(1.0f, 2.0f).is_equal(Vector2(2.0f, 1.0f)));
}

TEST_F(MathVector2Test, IsEqualApprox)
{
    Vector2 a(1.0f, 2.0f);
    Vector2 b(1.0f + 1e-7f, 2.0f - 1e-7f);

    EXPECT_TRUE(a.is_equal_approx(b));
}

TEST_F(MathVector2Test, IsZeroApprox)
{
    EXPECT_TRUE(Vector2(0.0f, 0.0f).is_zero_approx());

    EXPECT_FALSE(Vector2(0.001f, 0.0f).is_zero_approx());
}

// -----------------------------------------------------------------------------
// Finite
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, IsFinite)
{
    EXPECT_TRUE(Vector2(1.0f, 2.0f).is_finite());

    EXPECT_FALSE(Vector2(
        std::numeric_limits<float>::infinity(),
        0.0f).is_finite());

    EXPECT_FALSE(Vector2(
        0.0f,
        std::numeric_limits<float>::quiet_NaN()).is_finite());
}

// -----------------------------------------------------------------------------
// Sign
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, Sign)
{
    EXPECT_EQ(
        Vector2(-5.0f, 3.0f).sign(),
        Vector2(-1.0f, 1.0f));
}

// -----------------------------------------------------------------------------
// Floor / Ceil / Round
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, Floor)
{
    EXPECT_EQ(
        Vector2(1.8f, -1.2f).floor(),
        Vector2(1.0f, -2.0f));
}

TEST_F(MathVector2Test, Ceil)
{
    EXPECT_EQ(
        Vector2(1.2f, -1.8f).ceil(),
        Vector2(2.0f, -1.0f));
}

TEST_F(MathVector2Test, Round)
{
    EXPECT_EQ(
        Vector2(1.4f, 1.6f).round(),
        Vector2(1.0f, 2.0f));
}

// -----------------------------------------------------------------------------
// Clamp
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, ClampVector)
{
    Vector2 v(-5.0f, 10.0f);

    EXPECT_EQ(
        v.clamp(Vector2(0, 2), Vector2(5, 8)),
        Vector2(0, 8));
}

TEST_F(MathVector2Test, ClampScalar)
{
    Vector2 v(-5.0f, 10.0f);

    EXPECT_EQ(
        v.clampf(0.0f, 5.0f),
        Vector2(0.0f, 5.0f));
}

// -----------------------------------------------------------------------------
// Snapped
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, SnappedScalar)
{
    EXPECT_EQ(
        Vector2(5.2f, 8.8f).snappedf(1.0f),
        Vector2(5.0f, 9.0f));
}

TEST_F(MathVector2Test, SnappedVector)
{
    EXPECT_EQ(
        Vector2(5.2f, 8.8f).snapped(Vector2(1.0f, 2.0f)),
        Vector2(5.0f, 8.0f));
}

// -----------------------------------------------------------------------------
// String conversion
// -----------------------------------------------------------------------------

TEST_F(MathVector2Test, ToString)
{
    Vector2 v(3.5f, -2.0f);

    EXPECT_EQ(v.to_string(), "(3.5, -2)");
}