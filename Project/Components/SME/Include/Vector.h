#ifndef MathEngine_Vector_H
#define MathEngine_Vector_H

#include <vector>
#include <list>
#include <string>

// Math Engine Includes
#include "Definitions.h"

namespace MathEngine
{
	namespace Vector
	{
		class SIMPLE_MATH_ENGINE_API Vec2
		{
		public:
			union
			{
				struct { float x; float y; };
				struct { float r; float g; };
				struct { float s; float t; };
			};
		public:
			Vec2();
			Vec2(float x, float y);
			Vec2(Vec3 v);
			Vec2(Vec4 v);

		public:
			Vec2			operator+(const Vec2& v);
			Vec2			operator-(const Vec2& v);
			Vec2			operator*(const float& scalar);
			Vec2			operator*(Vec2 v2);
			Vec2			operator*(Mat2 m2);
			Vec2			operator/(const float& scalar);

			Vec2&			operator+=(const Vec2& v);
			Vec2&			operator-=(const Vec2& v);
			Vec2&			operator*=(const float& scalar);
			Vec2&			operator*=(Vec2 v2);
			Vec2&			operator*=(Mat2 m2);
			Vec2&			operator/=(const float& scalar);

			Vec2&			operator=(const Vec2& v);

			float&			operator[](size_t i);
			float const&	operator[](size_t i) const;

			bool			operator!=(const Vec2& m2) const;
			bool			operator==(const Vec2& m2) const;

			Vec2			Normalize() const;
			float			Length() const;

			FloatVector		ToVector();
			
			std::string		ToString() const;
		};
		class SIMPLE_MATH_ENGINE_API Vec3
		{
		public:
			union
			{
				struct { float x; float y; float z; };
				struct { float r; float g; float b; };
				struct { float s; float t; float p; };
			};

		public:
			Vec3();
			Vec3(float x, float y, float z);
			Vec3(Vec2 v, float z = 0.0f);
			Vec3(Vec4 v);

		private:
			Vec3&		 operator=(const Vec2& v);
			Vec3&		 operator=(const Vec4& v);

		public:
			Vec3		 operator+(const Vec3& v);
			Vec3		 operator-(const Vec3& v);
			Vec3		 operator*(const float& scalar);
			Vec3		 operator*(const Vec3& v3);
			Vec3		 operator*(const Mat3& m3);
			Vec3		 operator*(const Mat4& m4);
			Vec3		 operator/(const float& scalar);

			Vec3&		 operator+=(const Vec3& v);
			Vec3&		 operator-=(const Vec3& v);
			Vec3&		 operator*=(const float& scalar);
			Vec3&		 operator*=(const Vec3& v3);
			Vec3&		 operator*=(const Mat3& m3);
			Vec3&		 operator*=(const Mat4& m4);
			Vec3&		 operator/=(const float& scalar);

			Vec3&		 operator=(const Vec3& v);

			float&		 operator[](size_t i);
			float const& operator[](size_t i) const;

			bool		 operator!=(const Vec3& m3) const;
			bool		 operator==(const Vec3& m3) const;

			// Return a vector ponting Forward
			Vec3		 Forward() const;
			// Return a vector ponting Backward
			Vec3		 Backward() const;
			// Return a vector ponting Left
			Vec3		 Left() const;
			// Return a vector ponting Right
			Vec3		 Right() const;
			// Return a vector ponting Up
			Vec3		 Up() const;
			// Return a vector ponting Down
			Vec3		 Down() const;

			// Return the component that have the greatest value
			float		 Max() const;
			// Return a vector composed by the greatest values of the two vectors
			Vec3		 Max(const Vec3& r) const;

			float		 DistanceFrom(const Vec3& v) const;
			float		 Dot(Vec3 v3) const;
			float		 Length() const;

			Vec3		 Cross(const Vec3& r) const;
			Vec3		 Reflect(Vec3 normal) const;
			Vec3		 Normalize() const;
			Vec3		 Rotate(const Quaternion& rotation);

			FloatVector	 ToVector();

			std::string	 ToString() const;
		};
		class SIMPLE_MATH_ENGINE_API Vec4
		{
		public:
			union
			{
				struct { float x; float y; float z; float w; };
				struct { float r; float g; float b; float a; };
				struct { float s; float t; float p; float q; };
			};

		public:
			Vec4();
			Vec4(float x, float y, float z, float w);
			Vec4(Vec2 v, float z = 0.0f, float w = 0.0f);
			Vec4(Vec3 v, float w = 0.0f);

		public:
			Vec4		 operator+(const Vec4& v);
			Vec4		 operator-(const Vec4& v);
			Vec4 		 operator*(const float& scalar);
			Vec4		 operator*(Vec4 v4);
			Vec4		 operator*(Mat4 m4);
			Vec4 		 operator/(const float& scalar);

			Vec4&		 operator+=(const Vec4& v);
			Vec4&		 operator-=(const Vec4& v);
			Vec4&		 operator*=(const float& scalar);
			Vec4&		 operator*=(Vec4 v4);
			Vec4&		 operator*=(Mat4 m4);
			Vec4&		 operator/=(const float& scalar);

			Vec4&		 operator=(const Vec4& v);

			float&		 operator[](size_t i);
			float const& operator[](size_t i) const;

			bool		 operator!=(const Vec4& m4) const;
			bool		 operator==(const Vec4& m4) const;

			Vec4		 Normalize() const;
			float		 Length() const;

			FloatVector	 ToVector();

			std::string	 ToString() const;
		};

		inline Vector::Vec3	CalculateNormal(Vec3 v1, Vec3 v2, Vec3 v3) { return ((v2 - v1) * (v3 - v1)) / ((v2 - v1) * (v3 - v1)).Length(); }
	};
};

#endif // MathEngine_Vector_H