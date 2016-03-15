#include "../include/Vector.h"
#include "../include/Matrix.h"
#include "../include/Quaternion.h"

namespace SME
{
	namespace Vector
	{
		Vec2::Vec2() : x(0.0f), y(0.0f) {}
		Vec2::Vec2(float x, float y) : x(x), y(y) {}
		Vec2::Vec2(Vec3 v) : x(v.x), y(v.y) {}
		Vec2::Vec2(Vec4 v) : x(v.x), y(v.y) {}

		Vec2		 Vec2::operator+(const Vec2& v) { return Vec2(this->x + v.x, this->y + v.y); }
		Vec2		 Vec2::operator-(const Vec2& v) { return Vec2(this->x - v.x, this->y - v.y); }
		Vec2		 Vec2::operator*(const float& scalar)
		{
			Vec2 result;

			result[0] = this->x * scalar;
			result[1] = this->y * scalar;

			return result;
		}
		Vec2		 Vec2::operator*(Mat2 m2)
		{
			Vec2 result;

			result[0] = (m2[0][0] * this->x) + (m2[0][1] * this->y);
			result[1] = (m2[1][0] * this->x) + (m2[1][1] * this->y);

			return result;
		}
		Vec2		 Vec2::operator*(Vec2 v2)
		{
			Vec2 result;

			result[0] = (v2.x * this->x);
			result[1] = (v2.y * this->y);

			return result;
		}
		Vec2		 Vec2::operator/(const float& scalar)
		{
			Vec2 result;

			result[0] = this->x / scalar;
			result[1] = this->y / scalar;

			return result;
		}

		Vec2&		 Vec2::operator+=(const Vec2& v) 
		{ 
			(*this) = (*this) + v; 
			
			return *this; 
		}
		Vec2&		 Vec2::operator-=(const Vec2& v) 
		{ 
			(*this) = (*this) - v; 
			
			return *this; 
		}
		Vec2&		 Vec2::operator*=(const float& scalar)
		{
			(*this) = (*this) * scalar;

			return *this;
		}
		Vec2&		 Vec2::operator*=(Mat2 m2)
		{
			this->x = (m2[0][0] * this->x) + (m2[0][1] * this->y);
			this->y = (m2[1][0] * this->x) + (m2[1][1] * this->y);

			return *this;
		}
		Vec2&		 Vec2::operator*=(Vec2 v2)
		{
			this->x = (v2.x * this->x);
			this->y = (v2.y * this->y);

			return *this;
		}
		Vec2&		 Vec2::operator/=(const float& scalar)
		{
			(*this) = (*this) / scalar;

			return *this;
		}

		Vec2&		 Vec2::operator=(const Vec2& v)
		{
			this->x = v.x;
			this->y = v.y;

			return *this;
		}

		float const& Vec2::operator[](size_t i) const
		{
			if (i == 0)	return this->x;
			if (i == 1)	return this->y;

			throw std::out_of_range("Vec2::operator[](size_t i) out of range...");
		}
		float&		 Vec2::operator[](size_t i)
		{
			if (i == 0)	return this->x;
			if (i == 1)	return this->y;

			throw std::out_of_range("Vec2::operator[](size_t i) out of range...");
		}

		bool		 Vec2::operator!=(const Vec2& v2) const
		{
			return this->x != v2.x || this->y != v2.y;
		}
		bool		 Vec2::operator==(const Vec2& v2) const
		{
			return this->x == v2.x && this->y == v2.y;
		}

		Vec2		 Vec2::Normalize() const
		{
			Vec2 result(*this);
			float sqr = 1.0f / result.Length();

			result.x *= sqr;
			result.y *= sqr;

			return result;
		}
		float		 Vec2::Length() const
		{
			return sqrt(((*this)[0] * (*this)[0]) + ((*this)[1] * (*this)[1]));
		}

		FloatVector	 Vec2::ToVector()
		{
			FloatVector array;
			array.push_back(this->x);
			array.push_back(this->y);

			return array;
		}

		std::string	 Vec2::ToString() const
		{
			std::string str = "| ";
			str += std::to_string(this->x);
			str += ", ";
			str += std::to_string(this->y);
			str += " |";

			return str;
		}


		Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
		Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		Vec3::Vec3(Vec2 v, float z) : x(v.x), y(v.y), z(z) {}
		Vec3::Vec3(Vec4 v) : x(v.x), y(v.y), z(v.z) {}

		Vec3		 Vec3::operator+(const Vec3& v) { return Vec3(this->x + v.x, this->y + v.y, this->z + v.z); }
		Vec3		 Vec3::operator-(const Vec3& v) { return Vec3(this->x - v.x, this->y - v.y, this->z - v.z); }
		Vec3		 Vec3::operator*(const float& scalar)
		{
			Vec3 result;

			result[0] = this->x * scalar;
			result[1] = this->y * scalar;
			result[2] = this->z * scalar;

			return result;
		}
		Vec3		 Vec3::operator*(const Mat3& m3)
		{
			Vec3 result;

			result[0] = (m3[0][0] * this->x) + (m3[0][1] * this->y) + (m3[0][2] * this->z);
			result[1] = (m3[1][0] * this->x) + (m3[1][1] * this->y) + (m3[1][2] * this->z);
			result[2] = (m3[2][0] * this->x) + (m3[2][1] * this->y) + (m3[2][2] * this->z);

			return result;
		}
		Vec3		 Vec3::operator*(const Mat4& m4)
		{
			return Vec3(Vec4(*this, 1.0f)*m4);
		}
		Vec3		 Vec3::operator/(const float& scalar)
		{
			Vec3 result;

			result[0] = this->x / scalar;
			result[1] = this->y / scalar;
			result[2] = this->z / scalar;

			return result;
		}

		Vec3&		 Vec3::operator+=(const Vec3& v) { this->x += v.x; this->y += v.y; this->z += v.z; return *this; }
		Vec3&		 Vec3::operator-=(const Vec3& v) { this->x -= v.x; this->y -= v.y; this->z -= v.z; return *this; }
		Vec3&		 Vec3::operator*=(const float& scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;

			return *this;
		}
		Vec3&		 Vec3::operator*=(const Mat3& m3)
		{
			this->x = (m3[0][0] * this->x) + (m3[0][1] * this->y) + (m3[0][2] * this->z);
			this->y = (m3[1][0] * this->x) + (m3[1][1] * this->y) + (m3[1][2] * this->z);
			this->z = (m3[2][0] * this->x) + (m3[2][1] * this->y) + (m3[2][2] * this->z);

			return *this;
		}
		Vec3&		 Vec3::operator*=(const Mat4& m4)
		{
			Vec3 result = Vec3(Vec4(*this, 1.0f)*m4);

			this->x = result.x;
			this->y = result.y;
			this->z = result.z;

			return *this;
		}
		Vec3		 Vec3::operator*(const Vec3& v3)
		{
			Vec3 result;

			result[0] = (v3.x * this->x);
			result[1] = (v3.y * this->y);
			result[2] = (v3.z * this->z);

			return result;
		}
		Vec3&		 Vec3::operator*=(const Vec3& v3)
		{
			this->x = (v3.x * this->x);
			this->y = (v3.y * this->y);
			this->z = (v3.z * this->z);

			return *this;
		}
		Vec3&		 Vec3::operator/=(const float& scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;

			return *this;
		}

		Vec3&		 Vec3::operator=(const Vec3& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;

			return *this;
		}

		float const& Vec3::operator[](size_t i) const
		{
			if (i == 0)	return this->x;
			if (i == 1)	return this->y;
			if (i == 2)	return this->z;

			throw std::out_of_range("      Vec3::operator[](size_t i) out of range...");
		}
		float&		 Vec3::operator[](size_t i)
		{
			if (i == 0)	return this->x;
			if (i == 1)	return this->y;
			if (i == 2)	return this->z;

			throw std::out_of_range("      Vec3::operator[](size_t i) out of range...");
		}

		bool		 Vec3::operator!=(const Vec3& v3) const
		{
			return this->x != v3.x || this->y != v3.y || this->z != v3.z;
		}
		bool		 Vec3::operator==(const Vec3& v3) const
		{
			return this->x == v3.x && this->y == v3.y && this->z == v3.z;
		}

		Vec3		 Vec3::Forward()  const { return Vec3(+0.0f, +0.0f, -1.0f); }
		Vec3		 Vec3::Backward() const { return Vec3(+0.0f, +0.0f, +1.0f); }
		Vec3		 Vec3::Left()     const { return Vec3(-1.0f, +0.0f, +0.0f); }
		Vec3		 Vec3::Right()    const { return Vec3(+1.0f, +0.0f, +0.0f); }
		Vec3		 Vec3::Up()       const { return Vec3(+0.0f, +1.0f, +0.0f); }
		Vec3		 Vec3::Down()     const { return Vec3(+0.0f, -1.0f, +0.0f); }

		float		 Vec3::Max() const
		{
			float maxValue = this->x;
			if (this->y > maxValue)
				maxValue = this->y;
			if (this->z > maxValue)
				maxValue = this->z;

			return maxValue;
		}
		Vec3		 Vec3::Max(const Vec3& r) const
		{
			float x = (this->x > r.x) ? this->x : r.x;
			float y = (this->y > r.y) ? this->y : r.y;
			float z = (this->z > r.z) ? this->z : r.z;

			return Vec3(x, y, z);
		}

		float		 Vec3::DistanceFrom(const Vec3& v) const
		{
			return (Vec3(*this) - v).Length();
		}
		float		 Vec3::Dot(Vec3 v3) const
		{
			return this->x * v3.x + this->y * v3.y + this->z * v3.z;
		}
		float		 Vec3::Length() const { return sqrt(((*this)[0] * (*this)[0]) + ((*this)[1] * (*this)[1]) + ((*this)[2] * (*this)[2])); }

		Vec3		 Vec3::Cross(const Vec3& r) const
		{
			float x = (*this)[1] * r[2] - (*this)[2] * r[1];
			float y = (*this)[2] * r[0] - (*this)[0] * r[2];
			float z = (*this)[0] * r[1] - (*this)[1] * r[0];

			return Vec3(x, y, z);
		}
		Vec3	 	 Vec3::Reflect(Vec3 normal) const
		{
			auto result = *this;
			result -= (normal * (Dot(normal)*2.0f));

			return result;
		}
		Vec3		 Vec3::Normalize() const
		{
			Vec3 result(*this);
			float lenght = Length();

			result.x /= lenght;
			result.y /= lenght;
			result.z /= lenght;

			return result;
		}
		Vec3		 Vec3::Rotate(const Quaternion& rotation)
		{
			Quaternion conjugateQ = rotation.Conjugate();
			Quaternion q = rotation * (*this) * conjugateQ;

			Vec3 ret(q.x, q.y, q.z);

			return ret;
		}

		FloatVector  Vec3::ToVector()
		{
			FloatVector array;
			array.push_back(this->x);
			array.push_back(this->y);
			array.push_back(this->z);

			return array;
		}

		std::string	 Vec3::ToString() const
		{
			std::string str = "| ";
			str += std::to_string(this->x);
			str += ", ";
			str += std::to_string(this->y);
			str += ", ";
			str += std::to_string(this->z);
			str += " |";

			return str;
		}


		Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		Vec4::Vec4(Vec2 v, float z, float w) : x(v.x), y(v.y), z(z), w(w) {}
		Vec4::Vec4(Vec3 v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}

		Vec4		 Vec4::operator+(const Vec4& v) { return Vec4(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w); }
		Vec4		 Vec4::operator-(const Vec4& v) { return Vec4(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w); }
		Vec4		 Vec4::operator*(const float& scalar)
		{
			Vec4 result;

			result[0] = this->x * scalar;
			result[1] = this->y * scalar;
			result[2] = this->z * scalar;
			result[3] = this->w * scalar;

			return result;
		}
		Vec4		 Vec4::operator*(Vec4 v4)
		{
			Vec4 result;

			result[0] = (v4.x * this->x);
			result[1] = (v4.y * this->y);
			result[2] = (v4.z * this->z);
			result[3] = (v4.w * this->w);

			return result;
		}
		Vec4		 Vec4::operator*(Mat4 m4)
		{
			Vec4 result;

			result[0] = m4[0][0] * this->x + m4[0][1] * this->y + m4[0][2] * this->z + m4[0][3] * this->w;
			result[1] = m4[1][0] * this->x + m4[1][1] * this->y + m4[1][2] * this->z + m4[1][3] * this->w;
			result[2] = m4[2][0] * this->x + m4[2][1] * this->y + m4[2][2] * this->z + m4[2][3] * this->w;
			result[3] = m4[3][0] * this->x + m4[3][1] * this->y + m4[3][2] * this->z + m4[3][3] * this->w;

			return result;
		}
		Vec4		 Vec4::operator/(const float& scalar)
		{
			Vec4 result;

			result[0] = this->x / scalar;
			result[1] = this->y / scalar;
			result[2] = this->z / scalar;
			result[3] = this->w / scalar;

			return result;
		}

		Vec4&		 Vec4::operator+=(const Vec4& v) { this->x += v.x; this->y += v.y; this->z += v.z; this->w += v.w; return *this; }
		Vec4&		 Vec4::operator-=(const Vec4& v) { this->x -= v.x; this->y -= v.y; this->z -= v.z; this->w -= v.w; return *this; }
		Vec4&		 Vec4::operator*=(const float& scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;

			return *this;
		}
		Vec4&		 Vec4::operator*=(Mat4 m4)
		{
			this->x = m4[0][0] * this->x + m4[0][1] * this->y + m4[0][2] * this->z + m4[0][3] * this->w;
			this->y = m4[1][0] * this->x + m4[1][1] * this->y + m4[1][2] * this->z + m4[1][3] * this->w;
			this->z = m4[2][0] * this->x + m4[2][1] * this->y + m4[2][2] * this->z + m4[2][3] * this->w;
			this->w = m4[3][0] * this->x + m4[3][1] * this->y + m4[3][2] * this->z + m4[3][3] * this->w;

			return *this;
		}
		Vec4&		 Vec4::operator*=(Vec4 v4)
		{
			this->x = (v4.x * this->x);
			this->y = (v4.y * this->y);
			this->z = (v4.z * this->z);
			this->w = (v4.w * this->w);

			return *this;
		}
		Vec4&		 Vec4::operator/=(const float& scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			this->w /= scalar;

			return *this;
		}

		Vec4&		 Vec4::operator=(const Vec4& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;

			return *this;
		}

		float const& Vec4::operator[](size_t i) const
		{
			if (i == 0)	return this->x;
			if (i == 1)	return this->y;
			if (i == 2)	return this->z;
			if (i == 3)	return this->w;

			throw std::out_of_range("Vec3::operator[](size_t i) out of range...");
		}
		float&		 Vec4::operator[](size_t i)
		{
			if (i == 0)	return this->x;
			if (i == 1)	return this->y;
			if (i == 2)	return this->z;
			if (i == 3)	return this->w;

			throw std::out_of_range("Vec3::operator[](size_t i) out of range...");
		}

		bool		 Vec4::operator!=(const Vec4& v4) const
		{
			return this->x != v4.x || this->y != v4.y || this->z != v4.z || this->w != v4.w;
		}
		bool		 Vec4::operator==(const Vec4& v4) const
		{
			return this->x == v4.x && this->y == v4.y && this->z == v4.z && this->w == v4.w;
		}

		Vec4		 Vec4::Normalize() const
		{
			Vec4 result(*this);
			float tempV = result.x * result.x +
				result.y * result.y +
				result.z * result.z +
				result.w * result.w;
			float sqr = 1.0f / sqrt(tempV);

			result.x *= sqr;
			result.y *= sqr;
			result.z *= sqr;
			result.w *= sqr;


			return result;
		}
		float		 Vec4::Length() const
		{
			return sqrt(((*this)[0] * (*this)[0]) + ((*this)[1] * (*this)[1]) + ((*this)[2] * (*this)[2]) + ((*this)[3] * (*this)[3]));
		}

		FloatVector	 Vec4::ToVector()
		{
			FloatVector array;
			array.push_back(this->x);
			array.push_back(this->y);
			array.push_back(this->z);
			array.push_back(this->w);

			return array;
		}

		std::string  Vec4::ToString() const
		{
			std::string str = "| ";
			str += std::to_string(this->x);
			str += ", ";
			str += std::to_string(this->y);
			str += ", ";
			str += std::to_string(this->z);
			str += ", ";
			str += std::to_string(this->w);
			str += " |";

			return str;
		}
	};
}; // namespace SME
