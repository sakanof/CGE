#ifndef SME_Matrix_H
#define SME_Matrix_H

#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include <cmath>

// Math Engine Includes
#include "Vector.h"

namespace SME
{
	namespace Matrix
	{
		class SIMPLE_MATH_ENGINE_API Mat2
		{
		public:
			Vec2 m_value[2];

		public:
			Mat2();
			Mat2(float value);
			Mat2(float c11, float c12,
				 float c21, float c22);
			Mat2(Vec2 v1, Vec2 v2);
			Mat2(Mat3 m3);
			Mat2(Mat4 m4);

		public:
			Mat2		operator+(const Mat2& m2);
			Mat2		operator-(const Mat2& m2);
			Mat2		operator*(const float& scalar);
			Vec2		operator*(Vec2 m2);
			Mat2		operator*(Mat2 m2);
			Mat2		operator/(const float& scalar);

			Mat2&		operator+=(const Mat2& m2);
			Mat2&		operator-=(const Mat2& m2);
			Mat2&		operator*=(const float& scalar);
			Mat2&		operator*=(Mat2 m2);
			Mat2&		operator/=(const float& scalar);

			Mat2&		operator=(const Mat2& m2);

			Vec2&		operator[](size_t i);
			Vec2 const&	operator[](size_t i) const;

			bool		operator!=(const Mat2& m2) const;
			bool		operator==(const Mat2& m2) const;

			Mat2		Transpose() const;
			Mat2&		LoadIdentity();

			std::string	ToString() const;
		};
		class SIMPLE_MATH_ENGINE_API Mat3
		{
		public:
			Vec3 m_value[3];

		public:
			Mat3();
			Mat3(float value);
			Mat3(float c11, float c12, float c13,
				 float c21, float c22, float c23,
				 float c31, float c32, float c33);
			Mat3(Vec3 v1, Vec3 v2, Vec3 v3);
			Mat3(Mat2 m2);
			Mat3(Mat4 m3);

		public:
			Mat3		operator+(const Mat3& m3);
			Mat3		operator-(const Mat3& m3);
			Mat3		operator*(const float& scalar);
			Vec3		operator*(Vec3 m3);
			Mat3		operator*(Mat3 m3);
			Mat3		operator/(const float& scalar);

			Mat3&		operator+=(const Mat3& m3);
			Mat3&		operator-=(const Mat3& m3);
			Mat3&		operator*=(const float& scalar);
			Mat3&		operator*=(Mat3 m3);
			Mat3&		operator/=(const float& scalar);

			Mat3&		operator=(const Mat3& m3);

			Vec3&		operator[](size_t i);
			Vec3 const&	operator[](size_t i) const;

			bool		operator!=(const Mat3& m3) const;
			bool		operator==(const Mat3& m3) const;

			Mat3		Transpose() const;
			Mat3&		LoadIdentity();

			std::string	ToString() const;
		};
		class SIMPLE_MATH_ENGINE_API Mat4
		{
		public:
			Vec4 m_value[4];

		public:
			Mat4();
			Mat4(float value);
			Mat4(float c11, float c12, float c13, float c14,
				 float c21, float c22, float c23, float c24,
				 float c31, float c32, float c33, float c34,
				 float c41, float c42, float c43, float c44);
			Mat4(Vec4 v1, Vec4 v2, Vec4 v3, Vec4 v4);
			Mat4(Mat2 m2);
			Mat4(Mat3 m3);

		public:
			Mat4		operator+(const Mat4& m2);
			Mat4		operator-(const Mat4& m2);
			Mat4		operator*(const float& scalar);
			Vec4		operator*(Vec4 v4);
			Mat4		operator*(Mat4 v4);
			Mat4		operator/(const float& scalar);

			Mat4&		operator+=(const Mat4& m2);
			Mat4&		operator-=(const Mat4& m2);
			Mat4&		operator*=(const float& scalar);
			Mat4&		operator*=(Mat4 v4);
			Mat4&		operator/=(const float& scalar);

			Mat4&		operator=(const Mat4& m2);

			Vec4&		operator[](size_t i);
			Vec4 const&	operator[](size_t i) const;

			bool		operator!=(const Mat4& v4) const;
			bool		operator==(const Mat4& v4) const;

			Mat4		Transpose() const;
			Mat4&		LoadIdentity();

			Mat4		Translate(const Vec3& v3) const;
			Mat4		Translate(float x, float y, float z) const;
			Mat4		Translate(float factor) const;

			Mat4		Scale(const Vec3& v3) const;
			Mat4		Scale(float x, float y, float z) const;
			Mat4		Scale(float factor) const;

			Mat4		Rotate(const float& angle, const Vec3& v3);
			Mat4		Rotate(float rotateX, float rotateY, float rotateZ);
			Mat4		RotateFromVectors(const Vec3& n, const Vec3& v, const Vec3& u);
			Mat4		RotateFromDirection(const Vec3& forward, const Vec3& up);

			Mat4		LookAt(const Vec3& eye, const Vec3& center, const Vec3& up);
			Mat4		Perspective(float fov, float aspectRatio, float zNear, float zFar);
			Mat4		Orthographic(float left, float right, float bottom, float top, float near, float far);

			std::string	ToString() const;
		};
	};
};

#endif // SME_Matrix_H
