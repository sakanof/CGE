#include <SME\Include\Vector.h>

// Google Test Includes
#include <gtest\gtest.h>

TEST(SME_Vector3, Addition)
{
	SME::Vec3 v1(+2.235f  , +345.342f  , +872.256f);
	SME::Vec3 v3(-345.237f, +36234.423f, +912.475f);

	auto result = v1 + v3;

	EXPECT_FLOAT_EQ(v1.x + v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y + v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z + v3.z, result.z);
}

TEST(SME_Vector3, AdditionEquals)
{
	SME::Vec3 v1(-23457.436f, +3244.734f, +235.831f);
	SME::Vec3 v3(+33563.373f, +2357.783f, -68.324f);

	auto result = v1;
	result += v3;

	EXPECT_FLOAT_EQ(v1.x + v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y + v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z + v3.z, result.z);
}

TEST(SME_Vector3, Subtraction)
{
	SME::Vec3 v1(-746.354f , +3.751f , -2347.346f);
	SME::Vec3 v3(+5479.718f, +55.871f, -6725.236f);

	auto result = v1 - v3;

	EXPECT_FLOAT_EQ(v1.x - v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y - v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z - v3.z, result.z);
}

TEST(SME_Vector3, SubtractionEquals)
{
	SME::Vec3 v1(-3471.004f, +568.001f, -6253.156f);
	SME::Vec3 v3(+5479.718f, +893.028f, +4567.278f);

	auto result = v1;
	result -= v3;

	EXPECT_FLOAT_EQ(v1.x - v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y - v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z - v3.z, result.z);
}

TEST(SME_Vector3, ScalarMultiplcation)
{
	SME::Vec3 v1(+98234.665f, -3985.764f, 893712.563f);
	float scalar = 987.546f;

	auto result = v1 * scalar;

	EXPECT_FLOAT_EQ(v1.x * scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y * scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z * scalar, result.z);
}

TEST(SME_Vector3, ScalarMultiplcationEquals)
{
	SME::Vec3 v1(+384729.834f, -9875.982f, +90843.689f);
	float scalar = 0.4873f;

	auto result = v1;
	result      *= scalar;

	EXPECT_FLOAT_EQ(v1.x * scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y * scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z * scalar, result.z);
}

TEST(SME_Vector3, Multiplication)
{
	SME::Vec3 v1(-857.652f, +983.576f, -82742.876f);
	SME::Vec3 v3(+983.575f, +234.976f, +874827.346f);

	auto result = v1 * v3;

	EXPECT_FLOAT_EQ(v1.x * v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y * v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z * v3.z, result.z);
}

TEST(SME_Vector3, MultiplicationEquals)
{
	SME::Vec3 v1(-938.476f, +234.097f   , -29384.764f);
	SME::Vec3 v3(+398.257f, +234897.234f, -2837.645f);

	auto result = v1;
	result      *= v3;

	EXPECT_FLOAT_EQ(v1.x * v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y * v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z * v3.z, result.z);
}

TEST(SME_Vector3, Divition)
{
	SME::Vec3 v1(+4.076f, +9.003f, -8924.664f);
	float scalar = 92834.764f;

	auto result = v1 / scalar;

	EXPECT_FLOAT_EQ(v1.x / scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y / scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z / scalar, result.z);
}

TEST(SME_Vector3, DivitionEquals)
{
	SME::Vec3 v1(+394.865f, +3408.732f, +9874.647f);
	float scalar = 230.476f;

	auto result = v1;
	result      /= scalar;

	EXPECT_FLOAT_EQ(v1.x / scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y / scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z / scalar, result.z);
}

TEST(SME_Vector3, EqualsOperator)
{
	SME::Vec3 v1(-8.763f, +2904.836f, -8294.764f);
	SME::Vec3 v2(-8.763f, +2904.836f, -8294.764f);

	EXPECT_TRUE(v1 == v2);
}

TEST(SME_Vector3, DifferentOperator)
{
	SME::Vec3 v1(-28.374f, -62873.487f, +982.476f);
	SME::Vec3 v2(-28.001f, -62873.487f, +982.476f);

	EXPECT_TRUE(v1 != v2);
}

TEST(SME_Vector3, Normalize)
{
	SME::Vec3 v1(-76.547f , +9.897f, +655.975f);
	
	auto result       = v1 * (1.0f / sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z)));
	auto normalizedV1 = v1.Normalize();

	EXPECT_FLOAT_EQ(result.x, normalizedV1.x);
	EXPECT_FLOAT_EQ(result.y, normalizedV1.y);
	EXPECT_FLOAT_EQ(result.z, normalizedV1.z);
}

TEST(SME_Vector3, Length)
{
	SME::Vec3 v1(-98.724f, +234.235f, +897.346f);
	float length = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));

	EXPECT_FLOAT_EQ(length, v1.Length());
}