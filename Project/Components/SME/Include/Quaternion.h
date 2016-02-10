#ifndef MathEngine_Quaternion_H
#define MathEngine_Quaternion_H

#include "Vector.h"
#include "Matrix.h"

namespace SME
{
	class SIMPLE_MATH_ENGINE_API Quaternion : public Vec4
	{
	public:
		Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);
		Quaternion(const Vec4& r);
		Quaternion(const Vec3& axis, float angle);
		Quaternion(const Mat4& m);

		//void operator+(const Quaternion& q) { this->x += q.x; this->y += q.y; this->z += q.z; }

		Quaternion	operator+(const Quaternion& q) const;
		Quaternion	operator-(const Quaternion& q) const;
		Quaternion	operator*(const Quaternion& q) const;
		Quaternion	operator*(const Vec3& v) const;
		Quaternion	operator/(const float& f) const;

		Quaternion&	operator+=(const Quaternion& q);
		Quaternion&	operator-=(const Quaternion& q);

		float		Dot(const Quaternion& q) const;
		
		Quaternion	Lerp(const Quaternion& q, float lerpFactor) const;
		Quaternion	NLerp(const Quaternion& q, float lerpFactor, bool shortestPath) const;
		Quaternion	SLerp(const Quaternion& q, float lerpFactor, bool shortestPath) const;

		Mat4		ToRotationMatrix() const;

		Vec3		GetForward() const;
		Vec3		GetBack() const;
		Vec3		GetUp() const;
		Vec3		GetDown() const;
		Vec3		GetRight() const;
		Vec3		GetLeft() const;

		Quaternion	Conjugate() const;
	};
};

#endif // MathEngine_Quaternion_H