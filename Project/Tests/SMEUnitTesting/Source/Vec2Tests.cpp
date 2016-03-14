#include <SME\Include\Vector.h>

// Google Test Includes
#include <gtest\gtest.h>

TEST(SME_Vector2, Addition)
{
	SME::Vec2 v1(+1.838f, +2.687f);
	SME::Vec2 v2(+5.357f, -4.095f);

	auto result = v1 + v2;

	EXPECT_FLOAT_EQ(v1.x + v2.x, result.x);
	EXPECT_FLOAT_EQ(v1.y + v2.y, result.y);
}