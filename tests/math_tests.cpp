#include <gtest/gtest.h>

#include <math/rect2.hpp>
#include <math/color.hpp>

TEST(MathTests, RectangleBasic)
{
	Rect2 rect(10, 10, 100, 100);

	// Test union struct
	EXPECT_EQ(rect.x, rect.position.x);
	EXPECT_EQ(rect.y, rect.position.y);
	EXPECT_EQ(rect.width, rect.size.x);
	EXPECT_EQ(rect.height, rect.size.y);
};


TEST(MathTests, ColorBasic) {
	Color color(0.5f, 0.75f, 0.25f, 0.66f);

	EXPECT_EQ(color.r, color.attr[0]);
	EXPECT_EQ(color.g, color.attr[1]);
	EXPECT_EQ(color.b, color.attr[2]);
	EXPECT_EQ(color.a, color.attr[3]);
}

TEST(MathTest, ColorHex) {
	auto str = std::string("#ff0000ff");
	Color color(0xff0000ff);

	EXPECT_EQ(color.r, 1.0f);
	EXPECT_EQ(color.g, 0.0f);
	EXPECT_EQ(color.b, 0.0f);
	EXPECT_EQ(color.a, 1.0f);

	EXPECT_EQ(color, Color("#ff0000"));
	EXPECT_EQ(color, Color("#f00f"));
	EXPECT_EQ(color, Color("#f00"));
}
