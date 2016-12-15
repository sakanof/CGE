#include <SME/Include/Matrix.h>

// Google Test Includes
#include <gtest/gtest.h>

TEST(SME_Matrix2, Addition)
{
	SME::Mat2 mat1
	(
		51.516f , 351.517f,
		351.384f, 38.517f
	);

	SME::Mat2 mat2
	(
		2.057f, 1.009f,
		158.021f, 1.067f
	);

	auto result = mat1 + mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] + mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] + mat2[0][1]);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] + mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] + mat2[1][1]);
}

TEST(SME_Matrix2, AdditionEquals)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	SME::Mat2 mat2
	(
		2.057f, 1.009f,
		158.021f, 1.067f
	);

	auto result = mat1;
	result      += mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] + mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] + mat2[0][1]);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] + mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] + mat2[1][1]);
}

TEST(SME_Matrix2, Subtraction)
{
	SME::Mat2 mat1
	(
		51.516f , 351.517f,
		351.384f, 38.517f
	);

	SME::Mat2 mat2
	(
		2.057f  , 1.009f,
		158.021f, 1.067f
	);

	auto result = mat1 - mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] - mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] - mat2[0][1]);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] - mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] - mat2[1][1]);
}

TEST(SME_Matrix2, SubtractionEquals)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	SME::Mat2 mat2
	(
		2.057f, 1.009f,
		158.021f, 1.067f
	);

	auto result = mat1;
	result     -= mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] - mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] - mat2[0][1]);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] - mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] - mat2[1][1]);
}

TEST(SME_Matrix2, MultiplicationScalar)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);
	
	float scalar = 178.031f;
	
	auto result = mat1 * scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] * scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] * scalar);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] * scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] * scalar);
}

TEST(SME_Matrix2, MultiplicationScalarEquals)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	float scalar = 178.031f;

	auto result = mat1;
	result      *= scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] * scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] * scalar);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] * scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] * scalar);
}

TEST(SME_Matrix2, MultiplicationVector)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	SME::Vec2 vec(187.021f, 654.038f);

	auto result = mat1 * vec;

	auto x = (mat1[0][0] * vec.x) + (mat1[1][0] * vec.y);
	auto y = (mat1[0][1] * vec.x) + (mat1[1][1] * vec.y);

	EXPECT_FLOAT_EQ(result.x, x);
	EXPECT_FLOAT_EQ(result.y, y);
}

TEST(SME_Matrix2, Multiplication)
{
	SME::Mat2 mat1
	(
		51.516f , 351.517f,
		351.384f, 38.517f
	);

	SME::Mat2 mat2
	(
		2.057f  , 1.009f,
		158.021f, 1.067f
	);

	auto result = mat1 * mat2;

	float c11 = (mat1[0][0] * mat2[0][0]) + (mat1[1][0] * mat2[0][1]);
	float c12 = (mat1[0][1] * mat2[0][0]) + (mat1[1][1] * mat2[0][1]);
	float c21 = (mat1[0][0] * mat2[1][0]) + (mat1[1][0] * mat2[1][1]);
	float c22 = (mat1[0][1] * mat2[1][0]) + (mat1[1][1] * mat2[1][1]);
	
	EXPECT_FLOAT_EQ(result[0][0], c11);
	EXPECT_FLOAT_EQ(result[0][1], c12);
	EXPECT_FLOAT_EQ(result[1][0], c21);
	EXPECT_FLOAT_EQ(result[1][1], c22);
}

TEST(SME_Matrix2, MultiplicationEquals)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	SME::Mat2 mat2
	(
		2.057f, 1.009f,
		158.021f, 1.067f
	);

	auto result = mat1;
	result      *= mat2;

	float c11 = (mat1[0][0] * mat2[0][0]) + (mat1[1][0] * mat2[0][1]);
	float c12 = (mat1[0][1] * mat2[0][0]) + (mat1[1][1] * mat2[0][1]);
	float c21 = (mat1[0][0] * mat2[1][0]) + (mat1[1][0] * mat2[1][1]);
	float c22 = (mat1[0][1] * mat2[1][0]) + (mat1[1][1] * mat2[1][1]);

	EXPECT_FLOAT_EQ(result[0][0], c11);
	EXPECT_FLOAT_EQ(result[0][1], c12);
	EXPECT_FLOAT_EQ(result[1][0], c21);
	EXPECT_FLOAT_EQ(result[1][1], c22);
}

TEST(SME_Matrix2, Division)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	float scalar = 178.031f;

	auto result = mat1 / scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] / scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] / scalar);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] / scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] / scalar);
}

TEST(SME_Matrix2, DivisionEquals)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	float scalar = 178.031f;

	auto result = mat1;
	result      /= scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] / scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] / scalar);
	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] / scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] / scalar);
}

TEST(SME_Matrix2, Transpose)
{
	SME::Mat2 mat1
	(
		51.516f, 351.517f,
		351.384f, 38.517f
	);

	auto result = mat1.Transpose();

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[1][0]);
	EXPECT_FLOAT_EQ(result[1][0], mat1[0][1]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1]);
}

TEST(SME_Matrix2, LoadIdentity)
{
	SME::Mat2 mat1;

	auto result = mat1.LoadIdentity();

	EXPECT_FLOAT_EQ(result[0][0], 1.0f);
	EXPECT_FLOAT_EQ(result[0][1], 0.0f);
	EXPECT_FLOAT_EQ(result[1][0], 0.0f);
	EXPECT_FLOAT_EQ(result[1][1], 1.0f);
}
