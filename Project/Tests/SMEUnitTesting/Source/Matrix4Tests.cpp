#include <SME/Include/Matrix.h>

// Google Test Includes
#include <gtest/gtest.h>

TEST(SME_Matrix4, Addition)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	SME::Mat4 mat2
	(
		2.057f  , 1.009f, 375.518f, 187.031f,
		158.021f, 1.067f, 328.558f, 187.597f,
		136.318f, 1.034f, 178.612f, 175.641f,
		163.037f, 0.321f, 131.197f, 163.187f
	);

	auto result = mat1 + mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] + mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] + mat2[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] + mat2[0][2]);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] + mat2[0][3]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] + mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] + mat2[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] + mat2[1][2]);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] + mat2[1][3]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] + mat2[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] + mat2[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] + mat2[2][2]);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] + mat2[2][3]);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] + mat2[3][0]);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] + mat2[3][1]);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] + mat2[3][2]);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] + mat2[3][3]);
}

TEST(SME_Matrix4, AdditionEquals)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	SME::Mat4 mat2
	(
		2.057f  , 1.009f, 375.518f, 187.031f,
		158.021f, 1.067f, 328.558f, 187.597f,
		136.318f, 1.034f, 178.612f, 175.641f,
		163.037f, 0.321f, 131.197f, 163.187f
	);

	auto result = mat1;
	result      += mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] + mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] + mat2[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] + mat2[0][2]);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] + mat2[0][3]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] + mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] + mat2[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] + mat2[1][2]);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] + mat2[1][3]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] + mat2[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] + mat2[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] + mat2[2][2]);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] + mat2[2][3]);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] + mat2[3][0]);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] + mat2[3][1]);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] + mat2[3][2]);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] + mat2[3][3]);
}

TEST(SME_Matrix4, Subtraction)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	SME::Mat4 mat2
	(
		2.057f  , 1.009f, 375.518f, 187.031f,
		158.021f, 1.067f, 328.558f, 187.597f,
		136.318f, 1.034f, 178.612f, 175.641f,
		163.037f, 0.321f, 131.197f, 163.187f
	);

	auto result = mat1 - mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] - mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] - mat2[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] - mat2[0][2]);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] - mat2[0][3]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] - mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] - mat2[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] - mat2[1][2]);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] - mat2[1][3]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] - mat2[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] - mat2[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] - mat2[2][2]);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] - mat2[2][3]);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] - mat2[3][0]);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] - mat2[3][1]);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] - mat2[3][2]);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] - mat2[3][3]);
}

TEST(SME_Matrix4, SubtractionEquals)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	SME::Mat4 mat2
	(
		2.057f  , 1.009f, 375.518f, 187.031f,
		158.021f, 1.067f, 328.558f, 187.597f,
		136.318f, 1.034f, 178.612f, 175.641f,
		163.037f, 0.321f, 131.197f, 163.187f
	);

	auto result = mat1;
	result     -= mat2;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] - mat2[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] - mat2[0][1]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] - mat2[0][2]);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] - mat2[0][3]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] - mat2[1][0]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] - mat2[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] - mat2[1][2]);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] - mat2[1][3]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] - mat2[2][0]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] - mat2[2][1]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] - mat2[2][2]);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] - mat2[2][3]);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] - mat2[3][0]);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] - mat2[3][1]);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] - mat2[3][2]);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] - mat2[3][3]);
}

TEST(SME_Matrix4, MultiplicationScalar)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);
	
	float scalar = 178.031f;
	
	auto result = mat1 * scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] * scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] * scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] * scalar);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] * scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] * scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] * scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] * scalar);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] * scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] * scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] * scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] * scalar);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] * scalar);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] * scalar);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] * scalar);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] * scalar);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] * scalar);

}

TEST(SME_Matrix4, MultiplicationScalarEquals)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	float scalar = 178.031f;

	auto result = mat1;
	result      *= scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] * scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] * scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] * scalar);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] * scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] * scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] * scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] * scalar);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] * scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] * scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] * scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] * scalar);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] * scalar);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] * scalar);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] * scalar);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] * scalar);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] * scalar);
}

TEST(SME_Matrix4, MultiplicationVector)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	SME::Vec4 vec(187.021f, 654.038f, 219.156f, 136.028f);

	auto result = mat1 * vec;

	auto x = mat1[0][0] * vec.x + mat1[1][0] * vec.y + mat1[2][0] * vec.z + mat1[3][0] * vec.w;
	auto y = mat1[0][1] * vec.x + mat1[1][1] * vec.y + mat1[2][1] * vec.z + mat1[3][1] * vec.w;
	auto z = mat1[0][2] * vec.x + mat1[1][2] * vec.y + mat1[2][2] * vec.z + mat1[3][2] * vec.w;
	auto w = mat1[0][3] * vec.x + mat1[1][3] * vec.y + mat1[2][3] * vec.z + mat1[3][3] * vec.w;


	EXPECT_FLOAT_EQ(result.x, x);
	EXPECT_FLOAT_EQ(result.y, y);
	EXPECT_FLOAT_EQ(result.z, z);
	EXPECT_FLOAT_EQ(result.w, w);
}

TEST(SME_Matrix4, Multiplication)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	SME::Mat4 mat2
	(
		2.057f  , 1.009f, 375.518f, 187.031f,
		158.021f, 1.067f, 328.558f, 187.597f,
		136.318f, 1.034f, 178.612f, 175.641f,
		163.037f, 0.321f, 131.197f, 163.187f
	);

	auto result = mat1 * mat2;

	float c11 = mat2[0][0] * mat1[0][0] + mat2[0][1] * mat1[1][0] + mat2[0][2] * mat1[2][0] + mat2[0][3] * mat1[3][0];
	float c12 = mat2[0][0] * mat1[0][1] + mat2[0][1] * mat1[1][1] + mat2[0][2] * mat1[2][1] + mat2[0][3] * mat1[3][1];
	float c13 = mat2[0][0] * mat1[0][2] + mat2[0][1] * mat1[1][2] + mat2[0][2] * mat1[2][2] + mat2[0][3] * mat1[3][2];
	float c14 = mat2[0][0] * mat1[0][3] + mat2[0][1] * mat1[1][3] + mat2[0][2] * mat1[2][3] + mat2[0][3] * mat1[3][3];
	
	float c21 = mat2[1][0] * mat1[0][0] + mat2[1][1] * mat1[1][0] + mat2[1][2] * mat1[2][0] + mat2[1][3] * mat1[3][0];
	float c22 = mat2[1][0] * mat1[0][1] + mat2[1][1] * mat1[1][1] + mat2[1][2] * mat1[2][1] + mat2[1][3] * mat1[3][1];
	float c23 = mat2[1][0] * mat1[0][2] + mat2[1][1] * mat1[1][2] + mat2[1][2] * mat1[2][2] + mat2[1][3] * mat1[3][2];
	float c24 = mat2[1][0] * mat1[0][3] + mat2[1][1] * mat1[1][3] + mat2[1][2] * mat1[2][3] + mat2[1][3] * mat1[3][3];
	
	float c31 = mat2[2][0] * mat1[0][0] + mat2[2][1] * mat1[1][0] + mat2[2][2] * mat1[2][0] + mat2[2][3] * mat1[3][0];
	float c32 = mat2[2][0] * mat1[0][1] + mat2[2][1] * mat1[1][1] + mat2[2][2] * mat1[2][1] + mat2[2][3] * mat1[3][1];
	float c33 = mat2[2][0] * mat1[0][2] + mat2[2][1] * mat1[1][2] + mat2[2][2] * mat1[2][2] + mat2[2][3] * mat1[3][2];
	float c34 = mat2[2][0] * mat1[0][3] + mat2[2][1] * mat1[1][3] + mat2[2][2] * mat1[2][3] + mat2[2][3] * mat1[3][3];
	
	float c41 = mat2[3][0] * mat1[0][0] + mat2[3][1] * mat1[1][0] + mat2[3][2] * mat1[2][0] + mat2[3][3] * mat1[3][0];
	float c42 = mat2[3][0] * mat1[0][1] + mat2[3][1] * mat1[1][1] + mat2[3][2] * mat1[2][1] + mat2[3][3] * mat1[3][1];
	float c43 = mat2[3][0] * mat1[0][2] + mat2[3][1] * mat1[1][2] + mat2[3][2] * mat1[2][2] + mat2[3][3] * mat1[3][2];
	float c44 = mat2[3][0] * mat1[0][3] + mat2[3][1] * mat1[1][3] + mat2[3][2] * mat1[2][3] + mat2[3][3] * mat1[3][3];

	EXPECT_FLOAT_EQ(result[0][0], c11);
	EXPECT_FLOAT_EQ(result[0][1], c12);
	EXPECT_FLOAT_EQ(result[0][2], c13);
	EXPECT_FLOAT_EQ(result[0][3], c14);

	EXPECT_FLOAT_EQ(result[1][0], c21);
	EXPECT_FLOAT_EQ(result[1][1], c22);
	EXPECT_FLOAT_EQ(result[1][2], c23);
	EXPECT_FLOAT_EQ(result[1][3], c24);

	EXPECT_FLOAT_EQ(result[2][0], c31);
	EXPECT_FLOAT_EQ(result[2][1], c32);
	EXPECT_FLOAT_EQ(result[2][2], c33);
	EXPECT_FLOAT_EQ(result[2][3], c34);

	EXPECT_FLOAT_EQ(result[3][0], c41);
	EXPECT_FLOAT_EQ(result[3][1], c42);
	EXPECT_FLOAT_EQ(result[3][2], c43);
	EXPECT_FLOAT_EQ(result[3][3], c44);
}

TEST(SME_Matrix4, MultiplicationEquals)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	SME::Mat4 mat2
	(
		2.057f, 1.009f, 375.518f, 187.031f,
		158.021f, 1.067f, 328.558f, 187.597f,
		136.318f, 1.034f, 178.612f, 175.641f,
		163.037f, 0.321f, 131.197f, 163.187f
	);

	auto result = mat1;
	result      *= mat2;

	float c11 = mat2[0][0] * mat1[0][0] + mat2[0][1] * mat1[1][0] + mat2[0][2] * mat1[2][0] + mat2[0][3] * mat1[3][0];
	float c12 = mat2[0][0] * mat1[0][1] + mat2[0][1] * mat1[1][1] + mat2[0][2] * mat1[2][1] + mat2[0][3] * mat1[3][1];
	float c13 = mat2[0][0] * mat1[0][2] + mat2[0][1] * mat1[1][2] + mat2[0][2] * mat1[2][2] + mat2[0][3] * mat1[3][2];
	float c14 = mat2[0][0] * mat1[0][3] + mat2[0][1] * mat1[1][3] + mat2[0][2] * mat1[2][3] + mat2[0][3] * mat1[3][3];

	float c21 = mat2[1][0] * mat1[0][0] + mat2[1][1] * mat1[1][0] + mat2[1][2] * mat1[2][0] + mat2[1][3] * mat1[3][0];
	float c22 = mat2[1][0] * mat1[0][1] + mat2[1][1] * mat1[1][1] + mat2[1][2] * mat1[2][1] + mat2[1][3] * mat1[3][1];
	float c23 = mat2[1][0] * mat1[0][2] + mat2[1][1] * mat1[1][2] + mat2[1][2] * mat1[2][2] + mat2[1][3] * mat1[3][2];
	float c24 = mat2[1][0] * mat1[0][3] + mat2[1][1] * mat1[1][3] + mat2[1][2] * mat1[2][3] + mat2[1][3] * mat1[3][3];

	float c31 = mat2[2][0] * mat1[0][0] + mat2[2][1] * mat1[1][0] + mat2[2][2] * mat1[2][0] + mat2[2][3] * mat1[3][0];
	float c32 = mat2[2][0] * mat1[0][1] + mat2[2][1] * mat1[1][1] + mat2[2][2] * mat1[2][1] + mat2[2][3] * mat1[3][1];
	float c33 = mat2[2][0] * mat1[0][2] + mat2[2][1] * mat1[1][2] + mat2[2][2] * mat1[2][2] + mat2[2][3] * mat1[3][2];
	float c34 = mat2[2][0] * mat1[0][3] + mat2[2][1] * mat1[1][3] + mat2[2][2] * mat1[2][3] + mat2[2][3] * mat1[3][3];

	float c41 = mat2[3][0] * mat1[0][0] + mat2[3][1] * mat1[1][0] + mat2[3][2] * mat1[2][0] + mat2[3][3] * mat1[3][0];
	float c42 = mat2[3][0] * mat1[0][1] + mat2[3][1] * mat1[1][1] + mat2[3][2] * mat1[2][1] + mat2[3][3] * mat1[3][1];
	float c43 = mat2[3][0] * mat1[0][2] + mat2[3][1] * mat1[1][2] + mat2[3][2] * mat1[2][2] + mat2[3][3] * mat1[3][2];
	float c44 = mat2[3][0] * mat1[0][3] + mat2[3][1] * mat1[1][3] + mat2[3][2] * mat1[2][3] + mat2[3][3] * mat1[3][3];

	EXPECT_FLOAT_EQ(result[0][0], c11);
	EXPECT_FLOAT_EQ(result[0][1], c12);
	EXPECT_FLOAT_EQ(result[0][2], c13);
	EXPECT_FLOAT_EQ(result[0][3], c14);

	EXPECT_FLOAT_EQ(result[1][0], c21);
	EXPECT_FLOAT_EQ(result[1][1], c22);
	EXPECT_FLOAT_EQ(result[1][2], c23);
	EXPECT_FLOAT_EQ(result[1][3], c24);

	EXPECT_FLOAT_EQ(result[2][0], c31);
	EXPECT_FLOAT_EQ(result[2][1], c32);
	EXPECT_FLOAT_EQ(result[2][2], c33);
	EXPECT_FLOAT_EQ(result[2][3], c34);

	EXPECT_FLOAT_EQ(result[3][0], c41);
	EXPECT_FLOAT_EQ(result[3][1], c42);
	EXPECT_FLOAT_EQ(result[3][2], c43);
	EXPECT_FLOAT_EQ(result[3][3], c44);
}

TEST(SME_Matrix4, Division)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	float scalar = 178.031f;

	auto result = mat1 / scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] / scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] / scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] / scalar);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] / scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] / scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] / scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] / scalar);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] / scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] / scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] / scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] / scalar);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] / scalar);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] / scalar);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] / scalar);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] / scalar);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] / scalar);
}

TEST(SME_Matrix4, DivisionEquals)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	float scalar = 178.031f;

	auto result = mat1;
	result      /= scalar;

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0] / scalar);
	EXPECT_FLOAT_EQ(result[0][1], mat1[0][1] / scalar);
	EXPECT_FLOAT_EQ(result[0][2], mat1[0][2] / scalar);
	EXPECT_FLOAT_EQ(result[0][3], mat1[0][3] / scalar);

	EXPECT_FLOAT_EQ(result[1][0], mat1[1][0] / scalar);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1] / scalar);
	EXPECT_FLOAT_EQ(result[1][2], mat1[1][2] / scalar);
	EXPECT_FLOAT_EQ(result[1][3], mat1[1][3] / scalar);

	EXPECT_FLOAT_EQ(result[2][0], mat1[2][0] / scalar);
	EXPECT_FLOAT_EQ(result[2][1], mat1[2][1] / scalar);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2] / scalar);
	EXPECT_FLOAT_EQ(result[2][3], mat1[2][3] / scalar);

	EXPECT_FLOAT_EQ(result[3][0], mat1[3][0] / scalar);
	EXPECT_FLOAT_EQ(result[3][1], mat1[3][1] / scalar);
	EXPECT_FLOAT_EQ(result[3][2], mat1[3][2] / scalar);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3] / scalar);
}

TEST(SME_Matrix4, Transpose)
{
	SME::Mat4 mat1
	(
		51.516f , 351.517f, 1.036f  , 0.391f,
		351.384f, 38.517f , 136.031f, 2.301f,
		316.013f, 16.136f , 167.316f, 1.105f,
		135.186f, 15.128f , 138.174f, 1.9651f
	);

	auto result = mat1.Transpose();

	EXPECT_FLOAT_EQ(result[0][0], mat1[0][0]);
	EXPECT_FLOAT_EQ(result[0][1], mat1[1][0]);
	EXPECT_FLOAT_EQ(result[0][2], mat1[2][0]);
	EXPECT_FLOAT_EQ(result[0][3], mat1[3][0]);

	EXPECT_FLOAT_EQ(result[1][0], mat1[0][1]);
	EXPECT_FLOAT_EQ(result[1][1], mat1[1][1]);
	EXPECT_FLOAT_EQ(result[1][2], mat1[2][1]);
	EXPECT_FLOAT_EQ(result[1][3], mat1[3][1]);

	EXPECT_FLOAT_EQ(result[2][0], mat1[0][2]);
	EXPECT_FLOAT_EQ(result[2][1], mat1[1][2]);
	EXPECT_FLOAT_EQ(result[2][2], mat1[2][2]);
	EXPECT_FLOAT_EQ(result[2][3], mat1[3][2]);

	EXPECT_FLOAT_EQ(result[3][0], mat1[0][3]);
	EXPECT_FLOAT_EQ(result[3][1], mat1[1][3]);
	EXPECT_FLOAT_EQ(result[3][2], mat1[2][3]);
	EXPECT_FLOAT_EQ(result[3][3], mat1[3][3]);
}

TEST(SME_Matrix4, LoadIdentity)
{
	SME::Mat4 mat1;

	auto result = mat1.LoadIdentity();

	EXPECT_FLOAT_EQ(result[0][0], 1.0f);
	EXPECT_FLOAT_EQ(result[0][1], 0.0f);
	EXPECT_FLOAT_EQ(result[0][2], 0.0f);
	EXPECT_FLOAT_EQ(result[0][3], 0.0f);

	EXPECT_FLOAT_EQ(result[1][0], 0.0f);
	EXPECT_FLOAT_EQ(result[1][1], 1.0f);
	EXPECT_FLOAT_EQ(result[1][2], 0.0f);
	EXPECT_FLOAT_EQ(result[1][3], 0.0f);

	EXPECT_FLOAT_EQ(result[2][0], 0.0f);
	EXPECT_FLOAT_EQ(result[2][1], 0.0f);
	EXPECT_FLOAT_EQ(result[2][2], 1.0f);
	EXPECT_FLOAT_EQ(result[2][3], 0.0f);

	EXPECT_FLOAT_EQ(result[3][0], 0.0f);
	EXPECT_FLOAT_EQ(result[3][1], 0.0f);
	EXPECT_FLOAT_EQ(result[3][2], 0.0f);
	EXPECT_FLOAT_EQ(result[3][3], 1.0f);
}
