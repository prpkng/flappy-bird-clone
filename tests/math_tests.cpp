#include "pch.h"
#include "CppUnitTest.h"

#include <math/rect2.hpp>
#include <math/color.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTests
{
	TEST_CLASS(RectangleTests)
	{
	public:

		TEST_METHOD(TestBasic)
		{
			Rect2 rect(10, 10, 100, 100);

			// Test union struct
			Assert::AreEqual(rect.x, rect.position.x);
			Assert::AreEqual(rect.y, rect.position.y);
			Assert::AreEqual(rect.width, rect.size.x);
			Assert::AreEqual(rect.height, rect.size.y);
		}
	};


	TEST_CLASS(ColorTests) {

		TEST_METHOD(TestBasic) {
			Color color(0.5f, 0.75f, 0.25f, 0.66f);

			Assert::AreEqual(color.r, color.attr[0]);
			Assert::AreEqual(color.g, color.attr[1]);
			Assert::AreEqual(color.b, color.attr[2]);
			Assert::AreEqual(color.a, color.attr[3]);
		}

		TEST_METHOD(TestHex) {
			auto str = std::string("#ff0000ff");
			Color color(0xff0000ff);

			Assert::AreEqual(color.r, 1.0f);
			Assert::AreEqual(color.g, 0.0f);
			Assert::AreEqual(color.b, 0.0f);
			Assert::AreEqual(color.a, 1.0f);
		}
	};
}
