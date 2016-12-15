#include "../Include/Quaternion.h"

namespace SME
{
	Quaternion::Quaternion(float x, float y, float z, float w) : Vec4(x, y, z, w) {}
	Quaternion::Quaternion(const Vec4& q) : Vec4(q) {}
	Quaternion::Quaternion(const Vec3& axis, float angle)
	{
		float sinHalfAngle = sinf(angle / 2);
		float cosHalfAngle = cosf(angle / 2);

		(*this)[0] = axis.x * sinHalfAngle;
		(*this)[1] = axis.y * sinHalfAngle;
		(*this)[2] = axis.z * sinHalfAngle;
		(*this)[3] = cosHalfAngle;
	}
	Quaternion::Quaternion(const Mat4& m)
	{
		float trace = m[0][0] + m[1][1] + m[2][2];

		if (trace > 0)
		{
			float s = 0.5f / sqrtf(trace + 1.0f);
			(*this)[3] = 0.25f / s;
			(*this)[0] = (m[1][2] - m[2][1]) * s;
			(*this)[1] = (m[2][0] - m[0][2]) * s;
			(*this)[2] = (m[0][1] - m[1][0]) * s;
		}
		else if (m[0][0] > m[1][1] && m[0][0] > m[2][2])
		{
			float s = 2.0f * sqrtf(1.0f + m[0][0] - m[1][1] - m[2][2]);

			(*this)[3] = (m[1][2] - m[2][1]) / s;
			(*this)[0] = 0.25f * s;
			(*this)[1] = (m[1][0] + m[0][1]) / s;
			(*this)[2] = (m[2][0] + m[0][2]) / s;
		}
		else if (m[1][1] > m[2][2])
		{
			float s = 2.0f * sqrtf(1.0f + m[1][1] - m[0][0] - m[2][2]);

			(*this)[3] = (m[2][0] - m[0][2]) / s;
			(*this)[0] = (m[1][0] + m[0][1]) / s;
			(*this)[1] = 0.25f * s;
			(*this)[2] = (m[2][1] + m[1][2]) / s;
		}
		else
		{
			float s = 2.0f * sqrtf(1.0f + m[2][2] - m[1][1] - m[0][0]);

			(*this)[3] = (m[0][1] - m[1][0]) / s;
			(*this)[0] = (m[2][0] + m[0][2]) / s;
			(*this)[1] = (m[1][2] + m[2][1]) / s;
			(*this)[2] = 0.25f * s;
		}

		float length = Length();
		(*this)[0] = (*this)[0] / length;
		(*this)[1] = (*this)[1] / length;
		(*this)[2] = (*this)[2] / length;
		(*this)[3] = (*this)[3] / length;
	}

	Quaternion	Quaternion::operator+(const Quaternion& q) const { return Quaternion(this->x + q.x, this->y + q.y, this->z + q.z, this->w + q.w); }
	Quaternion	Quaternion::operator-(const Quaternion& q) const { return Quaternion(this->x - q.x, this->y - q.y, this->z - q.z, this->w - q.w); }
	Quaternion	Quaternion::operator*(const Quaternion& q) const
	{
		float _w = (this->w * q.w) - (this->x * q.x) - (this->y * q.y) - (this->z * q.z);
		float _x = (this->x * q.w) + (this->w * q.x) + (this->y * q.z) - (this->z * q.y);
		float _y = (this->y * q.w) + (this->w * q.y) + (this->z * q.x) - (this->x * q.z);
		float _z = (this->z * q.w) + (this->w * q.z) + (this->x * q.y) - (this->y * q.x);

		return Quaternion(_x, _y, _z, _w);
	}
	Quaternion	Quaternion::operator*(const Vec3& v) const
	{
		float _w = -(this->x * v.x) - (this->y * v.y) - (this->z * v.z);
		float _x = (this->w * v.x) + (this->y * v.z) - (this->z * v.y);
		float _y = (this->w * v.y) + (this->z * v.x) - (this->x * v.z);
		float _z = (this->w * v.z) + (this->x * v.y) - (this->y * v.x);

		return Quaternion(_x, _y, _z, _w);
	}
	Quaternion	Quaternion::operator/(const float& f) const{ return Quaternion(this->x - f, this->y - f, this->z - f, this->w - f); }

	Quaternion&	Quaternion::operator+=(const Quaternion& q) { this->x += q.x; this->y += q.y; this->z += q.z; this->w += q.w; return *this; }
	Quaternion&	Quaternion::operator-=(const Quaternion& q) { this->x -= q.x; this->y -= q.y; this->z -= q.z; this->w -= q.w; return *this; }

	float		Quaternion::Dot(const Quaternion& q) const { return (q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w); }
	
	Quaternion	Quaternion::Lerp(const Quaternion& q, float lerpFactor) const { return (Quaternion(q) - Quaternion(*this)) * lerpFactor + Quaternion(*this); }
	Quaternion	Quaternion::NLerp(const Quaternion& q, float lerpFactor, bool shortestPath) const
	{
		Quaternion correctedDest(q);

		if (shortestPath && Dot(q) < 0)
			correctedDest *= -1;

		return Quaternion(Lerp(correctedDest, lerpFactor).Normalize());
	}
	Quaternion	Quaternion::SLerp(const Quaternion& q, float lerpFactor, bool shortestPath) const
	{
		float EPSILON = 1e3;
		float cos = this->Dot(q);
		Quaternion correctedDest(q);

		if (shortestPath && cos < 0)
		{
			cos *= -1;
			correctedDest *= -1;
		}

		if (fabs(cos) >(1 - EPSILON))
			return NLerp(correctedDest, lerpFactor, false);

		float sin = (float)sqrtf(1.0f - cos * cos);
		float angle = atan2(sin, cos);
		float invSin = 1.0f / sin;

		float srcFactor = sinf((1.0f - lerpFactor) * angle) * invSin;
		float destFactor = sinf((lerpFactor)* angle) * invSin;

		return Quaternion((*this) * srcFactor + correctedDest * destFactor);
	}

	Mat4		Quaternion::ToRotationMatrix() const
	{
		Vec3 forward = Vec3(2.0f * (this->x * this->z - this->w * this->y),
			2.0f * (this->y * this->z + this->w * this->x),
			1.0f - 2.0f * (this->x * this->x + this->y * this->y));

		Vec3 up = Vec3(2.0f * (this->x*this->y + this->w*this->z),
			1.0f - 2.0f * (this->x*this->x + this->z*this->z),
			2.0f * (this->y*this->z - this->w*this->x));

		Vec3 right = Vec3(1.0f - 2.0f * (this->y*this->y + this->z*this->z),
			2.0f * (this->x*this->y - this->w*this->z),
			2.0f * (this->x*this->z + this->w*this->y));

		return Mat4(1.0f).RotateFromVectors(forward, up, right);
	}

	Vec3		Quaternion::GetForward() const { return Vec3(+0.0f, +0.0f, +1.0f).Rotate(*this); }
	Vec3		Quaternion::GetBack()    const { return Vec3(+0.0f, +0.0f, -1.0f).Rotate(*this); }
	Vec3		Quaternion::GetUp()      const { return Vec3(+0.0f, +1.0f, +0.0f).Rotate(*this); }
	Vec3		Quaternion::GetDown()    const { return Vec3(+0.0f, -1.0f, +0.0f).Rotate(*this); }
	Vec3		Quaternion::GetRight()   const { return Vec3(+1.0f, +0.0f, +0.0f).Rotate(*this); }
	Vec3		Quaternion::GetLeft()    const { return Vec3(-1.0f, +0.0f, +0.0f).Rotate(*this); }

	Quaternion	Quaternion::Conjugate()  const { return Quaternion(-this->x, -this->y, -this->z, this->w); }
};
