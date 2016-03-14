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

TEST(SME_Vector2, AdditionEquals)
{
	SME::Vec2 v1(+1.838f, +2.687f);
	SME::Vec2 v2(+5.357f, -4.095f);

	auto result = v1;
	result += v2;

	EXPECT_FLOAT_EQ(v1.x + v2.x, result.x);
	EXPECT_FLOAT_EQ(v1.y + v2.y, result.y);
}

TEST(SME_Vector2, Subtraction)
{
	SME::Vec2 v1(-746.354f, +2.751f);
	SME::Vec2 v2(+5479.718f, +55.871f);

	auto result = v1 - v2;

	EXPECT_FLOAT_EQ(v1.x - v2.x, result.x);
	EXPECT_FLOAT_EQ(v1.y - v2.y, result.y);
}

TEST(SME_Vector2, SubtractionEquals)
{
	SME::Vec2 v1(-746.354f, +2.751f);
	SME::Vec2 v2(+5479.718f, +55.871f);

	auto result = v1;
	result -= v2;

	EXPECT_FLOAT_EQ(v1.x - v2.x, result.x);
	EXPECT_FLOAT_EQ(v1.y - v2.y, result.y);
}

TEST(SME_Vector2, ScalarMultiplcation)
{
	SME::Vec2 v1(+138.947f, -3517.648f);
	float scalar = 16.178f;

	auto result = v1 * scalar;

	EXPECT_FLOAT_EQ(v1.x * scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y * scalar, result.y);
}

TEST(SME_Vector2, ScalarMultiplcationEquals)
{
	SME::Vec2 v1(+138.947f, -3517.648f);
	float scalar = 16.178f;

	auto result = v1;
	result      *= scalar;

	EXPECT_FLOAT_EQ(v1.x * scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y * scalar, result.y);
}

TEST(SME_Vector2, Multiplication)
{
	SME::Vec2 v1(-746.354f, +2.751f);
	SME::Vec2 v2(+5479.718f, +55.871f);

	auto result = v1 * v2;

	EXPECT_FLOAT_EQ(v1.x * v2.x, result.x);
	EXPECT_FLOAT_EQ(v1.y * v2.y, result.y);
}

TEST(SME_Vector2, MultiplicationEquals)
{
	SME::Vec2 v1(-746.354f, +2.751f);
	SME::Vec2 v2(+5479.718f, +55.871f);

	auto result = v1;
	result      *= v2;

	EXPECT_FLOAT_EQ(v1.x * v2.x, result.x);
	EXPECT_FLOAT_EQ(v1.y * v2.y, result.y);
}

TEST(SME_Vector2, Divition)
{
	SME::Vec2 v1(+5479.718f, +55.871f);
	float scalar = 16.178f;

	auto result = v1 / scalar;

	EXPECT_FLOAT_EQ(v1.x / scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y / scalar, result.y);
}

TEST(SME_Vector2, DivitionEquals)
{
	SME::Vec2 v1(+5479.718f, +55.871f);
	float scalar = 16.178f;

	auto result = v1;
	result      /= scalar;

	EXPECT_FLOAT_EQ(v1.x / scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y / scalar, result.y);
}

TEST(SME_Vector2, EqualsOperator)
{
	SME::Vec2 v1(-746.351f, +2.735f);
	SME::Vec2 v2(-746.351f, +2.735f);

	EXPECT_TRUE(v1 == v2);
}

TEST(SME_Vector2, DifferentOperator)
{
	SME::Vec2 v1(-746.351f, +2.735f);
	SME::Vec2 v2(-846.351f, +2.735f);

	EXPECT_TRUE(v1 != v2);
}

TEST(SME_Vector2, Normalize)
{
	SME::Vec2 v1(-746.351f, +2.735f);
	
	auto result       = v1 * (1.0f / sqrt((v1.x * v1.x) + (v1.y * v1.y)));
	auto normalizedV1 = v1.Normalize();

	EXPECT_FLOAT_EQ(result.x, normalizedV1.x);
	EXPECT_FLOAT_EQ(result.y, normalizedV1.y);
}

TEST(SME_Vector2, Length)
{
	SME::Vec2 v1(-746.351f, +2.735f);
	float length = sqrt((v1.x * v1.x) + (v1.y * v1.y));

	EXPECT_FLOAT_EQ(length, v1.Length());
}