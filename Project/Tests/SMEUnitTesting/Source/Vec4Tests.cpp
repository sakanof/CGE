#include <SME/Include/Vector.h>

// Google Test Includes
#include <gtest/gtest.h>

#include <math.h>

TEST(SME_Vector4, Addition)
{
	SME::Vec4 v1(+2.235f  , +345.342f  , +872.256f, +2352.545f);
	SME::Vec4 v3(-345.237f, +36234.423f, +912.475f, -3463.623f);

	auto result = v1 + v3;

	EXPECT_FLOAT_EQ(v1.x + v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y + v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z + v3.z, result.z);
	EXPECT_FLOAT_EQ(v1.w + v3.w, result.w);
}

TEST(SME_Vector4, AdditionEquals)
{
	SME::Vec4 v1(-23457.436f, +3244.734f, +235.831f, +452.463f);
	SME::Vec4 v3(+33563.373f, +2357.783f, -68.324f, -24.023f);

	auto result = v1;
	result += v3;

	EXPECT_FLOAT_EQ(v1.x + v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y + v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z + v3.z, result.z);
	EXPECT_FLOAT_EQ(v1.w + v3.w, result.w);
}

TEST(SME_Vector4, Subtraction)
{
	SME::Vec4 v1(-746.354f , +3.751f , -2347.346f, +523.003f);
	SME::Vec4 v3(+5479.718f, +55.871f, -6725.236f, +670.897f);

	auto result = v1 - v3;

	EXPECT_FLOAT_EQ(v1.x - v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y - v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z - v3.z, result.z);
	EXPECT_FLOAT_EQ(v1.w - v3.w, result.w);
}

TEST(SME_Vector4, SubtractionEquals)
{
	SME::Vec4 v1(-3471.004f, +568.001f, -6253.156f, +98.743f);
	SME::Vec4 v3(+5479.718f, +893.028f, +4567.278f, +98.764f);

	auto result = v1;
	result -= v3;

	EXPECT_FLOAT_EQ(v1.x - v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y - v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z - v3.z, result.z);
	EXPECT_FLOAT_EQ(v1.w - v3.w, result.w);
}

TEST(SME_Vector4, ScalarMultiplcation)
{
	SME::Vec4 v1(+98234.665f, -3985.764f, 712.563f, 3453.940f);
	float scalar = 987.546f;

	auto result = v1 * scalar;

	EXPECT_FLOAT_EQ(v1.x * scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y * scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z * scalar, result.z);
	EXPECT_FLOAT_EQ(v1.w * scalar, result.w);
}

TEST(SME_Vector4, ScalarMultiplcationEquals)
{
	SME::Vec4 v1(+384729.834f, -9875.982f, +90843.689f, -3.864f);
	float scalar = 0.901f;

	auto result = v1;
	result      *= scalar;

	EXPECT_FLOAT_EQ(v1.x * scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y * scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z * scalar, result.z);
	EXPECT_FLOAT_EQ(v1.w * scalar, result.w);
}

TEST(SME_Vector4, Multiplication)
{
	SME::Vec4 v1(-857.652f, +983.576f, -82742.876f , +975.043f);
	SME::Vec4 v3(+983.575f, +234.976f, +874827.346f, +974.534f);

	auto result = v1 * v3;

	EXPECT_FLOAT_EQ(v1.x * v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y * v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z * v3.z, result.z);
	EXPECT_FLOAT_EQ(v1.w * v3.w, result.w);
}

TEST(SME_Vector4, MultiplicationEquals)
{
	SME::Vec4 v1(-938.476f, +234.097f   , -29384.764f, -49.258f);
	SME::Vec4 v3(+398.257f, +234897.234f, -2837.645f , +345.702f);

	auto result = v1;
	result      *= v3;

	EXPECT_FLOAT_EQ(v1.x * v3.x, result.x);
	EXPECT_FLOAT_EQ(v1.y * v3.y, result.y);
	EXPECT_FLOAT_EQ(v1.z * v3.z, result.z);
	EXPECT_FLOAT_EQ(v1.w * v3.w, result.w);
}

TEST(SME_Vector4, Divition)
{
	SME::Vec4 v1(+4.076f, +9.003f, -8924.664f, -35.083f);
	float scalar = 386.764f;

	auto result = v1 / scalar;

	EXPECT_FLOAT_EQ(v1.x / scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y / scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z / scalar, result.z);
	EXPECT_FLOAT_EQ(v1.w / scalar, result.w);
}

TEST(SME_Vector4, DivitionEquals)
{
	SME::Vec4 v1(+394.865f, +3408.732f, +9874.647f, -34.874f);
	float scalar = 84.074f;

	auto result = v1;
	result      /= scalar;

	EXPECT_FLOAT_EQ(v1.x / scalar, result.x);
	EXPECT_FLOAT_EQ(v1.y / scalar, result.y);
	EXPECT_FLOAT_EQ(v1.z / scalar, result.z);
	EXPECT_FLOAT_EQ(v1.w / scalar, result.w);
}

TEST(SME_Vector4, EqualsOperator)
{
	SME::Vec4 v1(-8.763f, +2904.836f, -8294.764f, +763.985f);
	SME::Vec4 v2(-8.763f, +2904.836f, -8294.764f, +763.985f);

	EXPECT_TRUE(v1 == v2);
}

TEST(SME_Vector4, DifferentOperator)
{
	SME::Vec4 v1(-28.374f, -62873.487f, +982.476f, +864.073f);
	SME::Vec4 v2(-28.001f, -62873.487f, +982.476f, +37.846f);

	EXPECT_TRUE(v1 != v2);
}

TEST(SME_Vector4, Normalize)
{
	SME::Vec4 v1(-76.547f , +9.897f, +655.975f, +975.356f);
	
	auto result       = v1 * (1.0f / sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z) + (v1.w * v1.w)));
	auto normalizedV1 = v1.Normalize();

	EXPECT_FLOAT_EQ(result.x, normalizedV1.x);
	EXPECT_FLOAT_EQ(result.y, normalizedV1.y);
	EXPECT_FLOAT_EQ(result.z, normalizedV1.z);
	EXPECT_FLOAT_EQ(result.w, normalizedV1.w);
}

TEST(SME_Vector4, Length)
{
	SME::Vec4 v1(-98.724f, +234.235f, +897.346f, -756.530f);
	float length = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z) + (v1.w * v1.w));

	EXPECT_FLOAT_EQ(length, v1.Length());
}
