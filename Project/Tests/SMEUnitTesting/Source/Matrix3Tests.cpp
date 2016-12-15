#include <SME/Include/Matrix.h>

// Google Test Includes
#include <gtest/gtest.h>

TEST(SME_Matrix3, Addition)
{
	SME::Mat3 mat1
	(
		51.516f , 351.517f, 1.036f,
		351.384f, 38.517f , 136.031f,
		316.013f, 16.136f , 167.316f
	);

	SME::Mat3 mat3
	(
		2.057f  , 1.009f, 375.518f,
		158.021f, 1.067f, 328.558f,
		136.318f, 1.034f, 178.612f
	);

	auto result = mat1 + mat3;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] + mat3[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] + mat3[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] + mat3[0][2]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] + mat3[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] + mat3[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] + mat3[1][2]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] + mat3[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] + mat3[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] + mat3[2][2]);
}

TEST(SME_Matrix3, AdditionEquals)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);
	SME::Mat3 mat3
	(
		2.057f, 1.009f, 375.518f,
		158.021f, 1.067f, 328.558f,
		136.318f, 1.034f, 178.612f
	);

	auto result = mat1;
	result      += mat3;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] + mat3[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] + mat3[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] + mat3[0][2]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] + mat3[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] + mat3[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] + mat3[1][2]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] + mat3[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] + mat3[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] + mat3[2][2]);
}

TEST(SME_Matrix3, Subtraction)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	SME::Mat3 mat3
	(
		2.057f, 1.009f, 375.518f,
		158.021f, 1.067f, 328.558f,
		136.318f, 1.034f, 178.612f
	);

	auto result = mat1 - mat3;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] - mat3[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] - mat3[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] - mat3[0][2]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] - mat3[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] - mat3[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] - mat3[1][2]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] - mat3[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] - mat3[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] - mat3[2][2]);
}

TEST(SME_Matrix3, SubtractionEquals)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	SME::Mat3 mat3
	(
		2.057f, 1.009f, 375.518f,
		158.021f, 1.067f, 328.558f,
		136.318f, 1.034f, 178.612f
	);

	auto result = mat1;
	result     -= mat3;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] - mat3[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] - mat3[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] - mat3[0][2]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] - mat3[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] - mat3[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] - mat3[1][2]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] - mat3[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] - mat3[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] - mat3[2][2]);
}

TEST(SME_Matrix3, MultiplicationScalar)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);
	
	float scalar = 178.031f;
	
	auto result = mat1 * scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] * scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] * scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] * scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] * scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] * scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] * scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] * scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] * scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] * scalar);
}

TEST(SME_Matrix3, MultiplicationScalarEquals)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	float scalar = 178.031f;

	auto result = mat1;
	result      *= scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] * scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] * scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] * scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] * scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] * scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] * scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] * scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] * scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] * scalar);
}

TEST(SME_Matrix3, MultiplicationVector)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	SME::Vec3 vec(187.021f, 654.038f, 219.156f);

	auto result = mat1 * vec;

	auto x = (vec.x * mat1[0][0]) + (vec.y * mat1[1][0] + vec.z * mat1[2][0]);
	auto y = (vec.x * mat1[0][1]) + (vec.y * mat1[1][1] + vec.z * mat1[2][1]);
	auto z = (vec.x * mat1[0][2]) + (vec.y * mat1[1][2] + vec.z * mat1[2][2]);

	EXPECT_FLOAT_EQ(result.x, x);
	EXPECT_FLOAT_EQ(result.y, y);
	EXPECT_FLOAT_EQ(result.z, z);
}

TEST(SME_Matrix3, Multiplication)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	SME::Mat3 mat3
	(
		2.057f, 1.009f, 375.518f,
		158.021f, 1.067f, 328.558f,
		136.318f, 1.034f, 178.612f
	);

	auto result = mat1 * mat3;

	float c11 = mat1[0][0] * mat3[0][0] + mat1[1][0] * mat3[0][1] + mat1[2][0] * mat3[0][2];
	float c12 = mat1[0][1] * mat3[0][0] + mat1[1][1] * mat3[0][1] + mat1[2][1] * mat3[0][2];
	float c13 = mat1[0][2] * mat3[0][0] + mat1[1][2] * mat3[0][1] + mat1[2][2] * mat3[0][2];

	float c21 = mat1[0][0] * mat3[1][0] + mat1[1][0] * mat3[1][1] + mat1[2][0] * mat3[1][2];
	float c22 = mat1[0][1] * mat3[1][0] + mat1[1][1] * mat3[1][1] + mat1[2][1] * mat3[1][2];
	float c23 = mat1[0][2] * mat3[1][0] + mat1[1][2] * mat3[1][1] + mat1[2][2] * mat3[1][2];
	
	float c31 = mat1[0][0] * mat3[2][0] + mat1[1][0] * mat3[2][1] + mat1[2][0] * mat3[2][2];
	float c32 = mat1[0][1] * mat3[2][0] + mat1[1][1] * mat3[2][1] + mat1[2][1] * mat3[2][2];
	float c33 = mat1[0][2] * mat3[2][0] + mat1[1][2] * mat3[2][1] + mat1[2][2] * mat3[2][2];
	
	EXPECT_FLOAT_EQ(result[0][0], c11);
	EXPECT_FLOAT_EQ(result[0][1], c12);
	EXPECT_FLOAT_EQ(result[0][2], c13);

	EXPECT_FLOAT_EQ(result[1][0], c21);
	EXPECT_FLOAT_EQ(result[1][1], c22);
	EXPECT_FLOAT_EQ(result[1][2], c23);

	EXPECT_FLOAT_EQ(result[2][0], c31);
	EXPECT_FLOAT_EQ(result[2][1], c32);
	EXPECT_FLOAT_EQ(result[2][2], c33);
}

TEST(SME_Matrix3, MultiplicationEquals)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	SME::Mat3 mat3
	(
		2.057f, 1.009f, 375.518f,
		158.021f, 1.067f, 328.558f,
		136.318f, 1.034f, 178.612f
	);

	auto result = mat1;
	result      *= mat3;

	float c11 = mat1[0][0] * mat3[0][0] + mat1[1][0] * mat3[0][1] + mat1[2][0] * mat3[0][2];
	float c12 = mat1[0][1] * mat3[0][0] + mat1[1][1] * mat3[0][1] + mat1[2][1] * mat3[0][2];
	float c13 = mat1[0][2] * mat3[0][0] + mat1[1][2] * mat3[0][1] + mat1[2][2] * mat3[0][2];
	
	float c21 = mat1[0][0] * mat3[1][0] + mat1[1][0] * mat3[1][1] + mat1[2][0] * mat3[1][2];
	float c22 = mat1[0][1] * mat3[1][0] + mat1[1][1] * mat3[1][1] + mat1[2][1] * mat3[1][2];
	float c23 = mat1[0][2] * mat3[1][0] + mat1[1][2] * mat3[1][1] + mat1[2][2] * mat3[1][2];
	
	float c31 = mat1[0][0] * mat3[2][0] + mat1[1][0] * mat3[2][1] + mat1[2][0] * mat3[2][2];
	float c32 = mat1[0][1] * mat3[2][0] + mat1[1][1] * mat3[2][1] + mat1[2][1] * mat3[2][2];
	float c33 = mat1[0][2] * mat3[2][0] + mat1[1][2] * mat3[2][1] + mat1[2][2] * mat3[2][2];

	EXPECT_FLOAT_EQ(result[0][0], c11);
	EXPECT_FLOAT_EQ(result[0][1], c12);
	EXPECT_FLOAT_EQ(result[0][2], c13);

	EXPECT_FLOAT_EQ(result[1][0], c21);
	EXPECT_FLOAT_EQ(result[1][1], c22);
	EXPECT_FLOAT_EQ(result[1][2], c23);

	EXPECT_FLOAT_EQ(result[2][0], c31);
	EXPECT_FLOAT_EQ(result[2][1], c32);
	EXPECT_FLOAT_EQ(result[2][2], c33);
}

TEST(SME_Matrix3, Division)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	float scalar = 178.031f;

	auto result = mat1 / scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] / scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] / scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] / scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] / scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] / scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] / scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] / scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] / scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] / scalar);
}

TEST(SME_Matrix3, DivisionEquals)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	float scalar = 178.031f;

	auto result = mat1;
	result      /= scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] / scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] / scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] / scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] / scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] / scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] / scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] / scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] / scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] / scalar);
}

TEST(SME_Matrix3, Transpose)
{
	SME::Mat3 mat1
	(
		51.516f, 351.517f, 1.036f,
		351.384f, 38.517f, 136.031f,
		316.013f, 16.136f, 167.316f
	);

	auto result = mat1.Transpose();

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[1][0]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[2][0]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[0][1]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[2][1]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[0][2]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[1][2]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2]);
}

TEST(SME_Matrix3, LoadIdentity)
{
	SME::Mat3 mat1;

	auto result = mat1.LoadIdentity();

	EXPECT_FLOAT_EQ(result[0][0], 1.0f);
	EXPECT_FLOAT_EQ(result[0][1], 0.0f);
	EXPECT_FLOAT_EQ(result[0][2], 0.0f);

	EXPECT_FLOAT_EQ(result[1][0], 0.0f);
	EXPECT_FLOAT_EQ(result[1][1], 1.0f);
	EXPECT_FLOAT_EQ(result[1][2], 0.0f);

	EXPECT_FLOAT_EQ(result[2][0], 0.0f);
	EXPECT_FLOAT_EQ(result[2][1], 0.0f);
	EXPECT_FLOAT_EQ(result[2][2], 1.0f);
}
