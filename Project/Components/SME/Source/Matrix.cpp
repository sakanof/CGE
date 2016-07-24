#include "..\include\Matrix.h"


namespace SME
{
	namespace Matrix
	{
		Mat2::Mat2()
		{
			this->m_value[0][0] = 0;
			this->m_value[0][1] = 0;
			this->m_value[1][0] = 0;
			this->m_value[1][1] = 0;
		}
		Mat2::Mat2(float value)
		{
			this->m_value[0][0] = value; this->m_value[0][1] = 0.0f;
			this->m_value[1][0] = 0.0f; this->m_value[1][1] = value;
		}
		Mat2::Mat2(float c11, float c12,
				   float c21, float c22)
		{
			this->m_value[0][0] = c11;
			this->m_value[0][1] = c12;
			this->m_value[1][0] = c21;
			this->m_value[1][1] = c22;
		}
		Mat2::Mat2(Vec2 v1, Vec2 v2)
		{
			this->m_value[0] = v1;
			this->m_value[1] = v2;
		}
		Mat2::Mat2(Mat3 m3)
		{
			this->m_value[0][0] = m3[0][0]; this->m_value[0][1] = m3[0][1];
			this->m_value[1][0] = m3[1][0]; this->m_value[1][1] = m3[1][1];
		}
		Mat2::Mat2(Mat4 m4)
		{
			this->m_value[0][0] = m4[0][0]; this->m_value[0][1] = m4[0][1];
			this->m_value[1][0] = m4[1][0]; this->m_value[1][1] = m4[1][1];
		}

		Mat2		Mat2::operator+(const Mat2& m2)
		{
			Mat2 result;

			result[0] = this->m_value[0] + m2.m_value[0];
			result[1] = this->m_value[1] + m2.m_value[1];

			return result;
		}
		Mat2		Mat2::operator-(const Mat2& m2)
		{
			Mat2 result;

			result[0] = this->m_value[0] - m2.m_value[0];
			result[1] = this->m_value[1] - m2.m_value[1];

			return result;
		}
		Mat2		Mat2::operator*(const float& scalar)
		{
			Mat2 result;

			result[0] = this->m_value[0] * scalar;
			result[1] = this->m_value[1] * scalar;

			return result;
		}
		Vec2		Mat2::operator*(Vec2 v2)
		{
			Vec2 result;

			result[0] = (v2.x * this->m_value[0][0]) + (v2.y * this->m_value[1][0]);
			result[1] = (v2.x * this->m_value[0][1]) + (v2.y * this->m_value[1][1]);

			return result;
		}
		Mat2		Mat2::operator*(Mat2 m2)
		{
			Mat2 result;

			result[0][0] = m2[0][0] * this->m_value[0][0] + m2[0][1] * this->m_value[1][0];
			result[0][1] = m2[0][0] * this->m_value[0][1] + m2[0][1] * this->m_value[1][1];

			result[1][0] = m2[1][0] * this->m_value[0][0] + m2[1][1] * this->m_value[1][0];
			result[1][1] = m2[1][0] * this->m_value[0][1] + m2[1][1] * this->m_value[1][1];

			return result;
		}
		Mat2		Mat2::operator/(const float& scalar)
		{
			Mat2 result;

			result[0] = this->m_value[0] / scalar;
			result[1] = this->m_value[1] / scalar;

			return result;
		}

		Mat2&		Mat2::operator+=(const Mat2& m2)
		{
			this->m_value[0] += m2.m_value[0];
			this->m_value[1] += m2.m_value[1];

			return *this;
		}
		Mat2&		Mat2::operator-=(const Mat2& m2)
		{
			this->m_value[0] -= m2.m_value[0];
			this->m_value[1] -= m2.m_value[1];

			return *this;
		}
		Mat2&		Mat2::operator*=(const float& scalar)
		{
			this->m_value[0] *= scalar;
			this->m_value[1] *= scalar;

			return *this;
		}
		Mat2&		Mat2::operator*=(Mat2 m2)
		{
			Mat2 m(*this);

			this->m_value[0][0] = m2[0][0] * m[0][0] + m2[0][1] * m[1][0];
			this->m_value[0][1] = m2[0][0] * m[0][1] + m2[0][1] * m[1][1];
			this->m_value[1][0] = m2[1][0] * m[0][0] + m2[1][1] * m[1][0];
			this->m_value[1][1] = m2[1][0] * m[0][1] + m2[1][1] * m[1][1];

			return *this;
		}
		Mat2&		Mat2::operator/=(const float& scalar)
		{
			this->m_value[0] /= scalar;
			this->m_value[1] /= scalar;

			return *this;
		}

		Mat2&		Mat2::operator=(const Mat2& m2)
		{
			this->m_value[0] = m2.m_value[0];
			this->m_value[1] = m2.m_value[1];

			return *this;
		}

		Vec2&		Mat2::operator[](size_t i)
		{
			if (i == 0)	return this->m_value[0];
			if (i == 1)	return this->m_value[1];

			throw std::out_of_range("Mat4::operator[](size_t i) out of range...");
		}
		Vec2 const& Mat2::operator[](size_t i) const
		{
			if (i == 0)	return this->m_value[0];
			if (i == 1)	return this->m_value[1];

			throw std::out_of_range("Mat4::operator[](size_t i) out of range...");
		}

		bool		Mat2::operator!=(const Mat2& m2) const
		{
			return this->m_value[0] != m2[0] || this->m_value[1] != m2[1];
		}
		bool		Mat2::operator==(const Mat2& m2) const
		{
			return this->m_value[0] == m2[0] && this->m_value[1] == m2[1];
		}

		Mat2		Mat2::Transpose() const
		{
			Mat2 result;

			result[0][0] = (*this)[0][0];
			result[0][1] = (*this)[1][0];

			result[1][0] = (*this)[0][1];
			result[1][1] = (*this)[1][1];

			return result;
		}

		Mat2&		Mat2::LoadIdentity()
		{
			this->m_value[0][0] = 1.0f; this->m_value[0][1] = 0.0f;
			this->m_value[1][0] = 0.0f; this->m_value[1][1] = 1.0f;

			return *this;
		}

		std::string Mat2::ToString() const
		{
			std::string str = "";

			size_t size = 2;
			for (size_t i = 0; i < size; i++)
			{
				str += this->m_value[i].ToString();

				if (i < size - 1)
					str += "\n";
			}

			return str;
		}


		Mat3::Mat3()
		{
			this->m_value[0][0] = this->m_value[0][1] = this->m_value[0][2] = 0.0f;
			this->m_value[1][0] = this->m_value[1][1] = this->m_value[1][2] = 0.0f;
			this->m_value[2][0] = this->m_value[2][1] = this->m_value[2][2] = 0.0f;
		}
		Mat3::Mat3(float value)
		{
			this->m_value[0][0] = value; this->m_value[0][1] = 0.0f;  this->m_value[0][2] = 0.0f;
			this->m_value[1][0] = 0.0f;  this->m_value[1][1] = value; this->m_value[1][2] = 0.0f;
			this->m_value[2][0] = 0.0f;  this->m_value[2][1] = 0.0f;  this->m_value[2][2] = value;
		}
		Mat3::Mat3(float c11, float c12, float c13,
				   float c21, float c22, float c23,
				   float c31, float c32, float c33)
		{
			this->m_value[0][0] = c11; this->m_value[0][1] = c12; this->m_value[0][2] = c13;
			this->m_value[1][0] = c21; this->m_value[1][1] = c22; this->m_value[1][2] = c23;
			this->m_value[2][0] = c31; this->m_value[2][1] = c32; this->m_value[2][2] = c33;
		}
		Mat3::Mat3(Vec3 v1, Vec3 v2, Vec3 v3)
		{
			this->m_value[0] = v1;
			this->m_value[1] = v2;
			this->m_value[2] = v3;
		}
		Mat3::Mat3(Mat2 m2)
		{
			this->m_value[0][0] = m2[0][0]; this->m_value[0][1] = m2[0][1]; this->m_value[0][2] = 0.0f;
			this->m_value[1][0] = m2[1][0]; this->m_value[1][1] = m2[1][1]; this->m_value[1][2] = 0.0f;
			this->m_value[2][0] = 0.0f; this->m_value[2][1] = 0.0f; this->m_value[2][2] = 0.0f;
		}
		Mat3::Mat3(Mat4 m4)
		{
			this->m_value[0][0] = m4[0][0]; this->m_value[0][1] = m4[0][1]; this->m_value[0][2] = m4[0][2];
			this->m_value[1][0] = m4[1][0]; this->m_value[1][1] = m4[1][1]; this->m_value[1][2] = m4[1][2];
			this->m_value[2][0] = m4[2][0]; this->m_value[2][1] = m4[2][1]; this->m_value[2][2] = m4[2][2];
		}

		Mat3		Mat3::operator+(const Mat3& m3)
		{
			Mat3 result;

			result[0] = this->m_value[0] + m3.m_value[0];
			result[1] = this->m_value[1] + m3.m_value[1];
			result[2] = this->m_value[2] + m3.m_value[2];

			return result;
		}
		Mat3		Mat3::operator-(const Mat3& m3)
		{
			Mat3 result;

			result[0] = this->m_value[0] - m3.m_value[0];
			result[1] = this->m_value[1] - m3.m_value[1];
			result[2] = this->m_value[2] - m3.m_value[2];

			return result;
		}
		Mat3		Mat3::operator*(const float& scalar)
		{
			Mat3 result;

			result[0] = this->m_value[0] * scalar;
			result[1] = this->m_value[1] * scalar;
			result[2] = this->m_value[2] * scalar;

			return result;
		}
		Vec3		Mat3::operator*(Vec3 v3)
		{
			Vec3 result;

			result[0] = (v3.x * this->m_value[0][0]) + (v3.y * this->m_value[1][0] + v3.z * this->m_value[2][0]);
			result[1] = (v3.x * this->m_value[0][1]) + (v3.y * this->m_value[1][1] + v3.z * this->m_value[2][1]);
			result[2] = (v3.x * this->m_value[0][2]) + (v3.y * this->m_value[1][2] + v3.z * this->m_value[2][2]);

			return result;
		}
		Mat3		Mat3::operator*(Mat3 m3)
		{
			Mat3 result;

			result[0][0] = this->m_value[0][0] * m3[0][0] + this->m_value[1][0] * m3[0][1] + this->m_value[2][0] * m3[0][2];
			result[0][1] = this->m_value[0][1] * m3[0][0] + this->m_value[1][1] * m3[0][1] + this->m_value[2][1] * m3[0][2];
			result[0][2] = this->m_value[0][2] * m3[0][0] + this->m_value[1][2] * m3[0][1] + this->m_value[2][2] * m3[0][2];
			result[1][0] = this->m_value[0][0] * m3[1][0] + this->m_value[1][0] * m3[1][1] + this->m_value[2][0] * m3[1][2];
			result[1][1] = this->m_value[0][1] * m3[1][0] + this->m_value[1][1] * m3[1][1] + this->m_value[2][1] * m3[1][2];
			result[1][2] = this->m_value[0][2] * m3[1][0] + this->m_value[1][2] * m3[1][1] + this->m_value[2][2] * m3[1][2];
			result[2][0] = this->m_value[0][0] * m3[2][0] + this->m_value[1][0] * m3[2][1] + this->m_value[2][0] * m3[2][2];
			result[2][1] = this->m_value[0][1] * m3[2][0] + this->m_value[1][1] * m3[2][1] + this->m_value[2][1] * m3[2][2];
			result[2][2] = this->m_value[0][2] * m3[2][0] + this->m_value[1][2] * m3[2][1] + this->m_value[2][2] * m3[2][2];

			return result;
		}
		Mat3		Mat3::operator/(const float& scalar)
		{
			Mat3 result;

			result[0] = this->m_value[0] / scalar;
			result[1] = this->m_value[1] / scalar;
			result[2] = this->m_value[2] / scalar;

			return result;
		}

		Mat3&		Mat3::operator+=(const Mat3& m3)
		{
			this->m_value[0] += m3.m_value[0];
			this->m_value[1] += m3.m_value[1];
			this->m_value[2] += m3.m_value[2];

			return *this;
		}
		Mat3&		Mat3::operator-=(const Mat3& m3)
		{
			this->m_value[0] -= m3.m_value[0];
			this->m_value[1] -= m3.m_value[1];
			this->m_value[2] -= m3.m_value[2];

			return *this;
		}
		Mat3&		Mat3::operator*=(const float& scalar)
		{
			this->m_value[0] *= scalar;
			this->m_value[1] *= scalar;
			this->m_value[2] *= scalar;

			return *this;
		}
		Mat3&		Mat3::operator*=(Mat3 m3)
		{
			Mat3 m(*this);

			this->m_value[0][0] = m[0][0] * m3[0][0] + m[1][0] * m3[0][1] + m[2][0] * m3[0][2];
			this->m_value[0][1] = m[0][1] * m3[0][0] + m[1][1] * m3[0][1] + m[2][1] * m3[0][2];
			this->m_value[0][2] = m[0][2] * m3[0][0] + m[1][2] * m3[0][1] + m[2][2] * m3[0][2];
			this->m_value[1][0] = m[0][0] * m3[1][0] + m[1][0] * m3[1][1] + m[2][0] * m3[1][2];
			this->m_value[1][1] = m[0][1] * m3[1][0] + m[1][1] * m3[1][1] + m[2][1] * m3[1][2];
			this->m_value[1][2] = m[0][2] * m3[1][0] + m[1][2] * m3[1][1] + m[2][2] * m3[1][2];
			this->m_value[2][0] = m[0][0] * m3[2][0] + m[1][0] * m3[2][1] + m[2][0] * m3[2][2];
			this->m_value[2][1] = m[0][1] * m3[2][0] + m[1][1] * m3[2][1] + m[2][1] * m3[2][2];
			this->m_value[2][2] = m[0][2] * m3[2][0] + m[1][2] * m3[2][1] + m[2][2] * m3[2][2];

			return *this;
		}
		Mat3&		Mat3::operator/=(const float& scalar)
		{
			this->m_value[0] /= scalar;
			this->m_value[1] /= scalar;
			this->m_value[2] /= scalar;

			return *this;
		}

		Mat3&		Mat3::operator=(const Mat3& m3)
		{
			this->m_value[0] = m3.m_value[0];
			this->m_value[1] = m3.m_value[1];
			this->m_value[2] = m3.m_value[2];

			return *this;
		}

		Vec3&		Mat3::operator[](size_t i)
		{
			if (i == 0)	return this->m_value[0];
			if (i == 1)	return this->m_value[1];
			if (i == 2)	return this->m_value[2];

			throw std::out_of_range("Mat4::operator[](size_t i) out of range...");
		}
		Vec3 const& Mat3::operator[](size_t i) const
		{
			if (i == 0)	return this->m_value[0];
			if (i == 1)	return this->m_value[1];
			if (i == 2)	return this->m_value[2];

			throw std::out_of_range("Mat4::operator[](size_t i) out of range...");
		}

		bool		Mat3::operator!=(const Mat3& m3) const
		{
			return this->m_value[0] != m3[0] || this->m_value[1] != m3[1] || this->m_value[2] != m3[2];
		}
		bool		Mat3::operator==(const Mat3& m3) const
		{
			return this->m_value[0] == m3[0] && this->m_value[1] == m3[1] && this->m_value[2] == m3[2];
		}

		Mat3		Mat3::Transpose() const
		{
			Mat3 result;

			result[0][0] = (*this)[0][0];
			result[0][1] = (*this)[1][0];
			result[0][2] = (*this)[2][0];

			result[1][0] = (*this)[0][1];
			result[1][1] = (*this)[1][1];
			result[1][2] = (*this)[2][1];

			result[2][0] = (*this)[0][2];
			result[2][1] = (*this)[1][2];
			result[2][2] = (*this)[2][2];

			return result;
		}
		Mat3&		Mat3::LoadIdentity()
		{
			this->m_value[0][0] = 1.0f; this->m_value[0][1] = 0.0f; this->m_value[0][2] = 0.0f;
			this->m_value[1][0] = 0.0f; this->m_value[1][1] = 1.0f; this->m_value[1][2] = 0.0f;
			this->m_value[2][0] = 0.0f; this->m_value[2][1] = 0.0f; this->m_value[2][2] = 1.0f;

			return *this;
		}
		
		std::string Mat3::ToString() const
		{
			std::string str = "";

			size_t size = 3;
			for (size_t i = 0; i < size; i++)
			{
				str += this->m_value[i].ToString();

				if (i < size - 1)
					str += "\n";
			}

			return str;
		}


		Mat4::Mat4()
		{
			this->m_value[0][0] = 1.0f; this->m_value[0][1] = 0.0f; this->m_value[0][2] = 0.0f; this->m_value[0][3] = 0.0f;
			this->m_value[1][0] = 0.0f; this->m_value[1][1] = 1.0f; this->m_value[1][2] = 0.0f; this->m_value[1][3] = 0.0f;
			this->m_value[2][0] = 0.0f; this->m_value[2][1] = 0.0f; this->m_value[2][2] = 1.0f; this->m_value[2][3] = 0.0f;
			this->m_value[3][0] = 0.0f; this->m_value[3][1] = 0.0f; this->m_value[3][2] = 0.0f; this->m_value[3][3] = 1.0f;
		}
		Mat4::Mat4(float value)
		{
			this->m_value[0][0] = value; this->m_value[0][1] = 0.0f;  this->m_value[0][2] = 0.0f;  this->m_value[0][3] = 0.0f;
			this->m_value[1][0] = 0.0f;  this->m_value[1][1] = value; this->m_value[1][2] = 0.0f;  this->m_value[1][3] = 0.0f;
			this->m_value[2][0] = 0.0f;  this->m_value[2][1] = 0.0f;  this->m_value[2][2] = value; this->m_value[2][3] = 0.0f;
			this->m_value[3][0] = 0.0f;  this->m_value[3][1] = 0.0f;  this->m_value[3][2] = 0.0f;  this->m_value[3][3] = value;
		}
		Mat4::Mat4(float c11, float c12, float c13, float c14,
				   float c21, float c22, float c23, float c24,
				   float c31, float c32, float c33, float c34,
				   float c41, float c42, float c43, float c44)
		{
			this->m_value[0][0] = c11; this->m_value[0][1] = c12; this->m_value[0][2] = c13; this->m_value[0][3] = c14;
			this->m_value[1][0] = c21; this->m_value[1][1] = c22; this->m_value[1][2] = c23; this->m_value[1][3] = c24;
			this->m_value[2][0] = c31; this->m_value[2][1] = c32; this->m_value[2][2] = c33; this->m_value[2][3] = c34;
			this->m_value[3][0] = c41; this->m_value[3][1] = c42; this->m_value[3][2] = c43; this->m_value[3][3] = c44;
		}
		Mat4::Mat4(Vec4 v1, Vec4 v2, Vec4 v3, Vec4 v4)
		{
			this->m_value[0] = v1;
			this->m_value[1] = v2;
			this->m_value[2] = v3;
			this->m_value[3] = v4;
		}
		Mat4::Mat4(Mat2 m2)
		{
			this->m_value[0][0] = m2[0][0]; this->m_value[0][1] = m2[0][1]; this->m_value[0][2] = 0.0f; this->m_value[0][3] = 0.0f;
			this->m_value[1][0] = m2[1][0]; this->m_value[1][1] = m2[1][1]; this->m_value[1][2] = 0.0f; this->m_value[1][3] = 0.0f;
			this->m_value[2][0] = 0.0f;     this->m_value[2][1] = 0.0f;     this->m_value[2][2] = 0.0f; this->m_value[2][3] = 0.0f;
			this->m_value[3][0] = 0.0f;     this->m_value[3][1] = 0.0f;     this->m_value[3][2] = 0.0f; this->m_value[3][3] = 0.0f;
		}
		Mat4::Mat4(Mat3 m3)
		{
			this->m_value[0][0] = m3[0][0]; this->m_value[0][1] = m3[0][1]; this->m_value[0][2] = m3[0][2]; this->m_value[0][3] = 0.0f;
			this->m_value[1][0] = m3[1][0]; this->m_value[1][1] = m3[1][1]; this->m_value[1][2] = m3[1][2]; this->m_value[1][3] = 0.0f;
			this->m_value[2][0] = m3[2][0]; this->m_value[2][1] = m3[2][1]; this->m_value[2][2] = m3[2][2]; this->m_value[2][3] = 0.0f;
			this->m_value[3][0] = 0.0f;     this->m_value[3][1] = 0.0f;     this->m_value[3][2] = 0.0f;     this->m_value[3][3] = 0.0f;
		}

		Mat4		Mat4::operator+(const Mat4& m4)
		{
			Mat4 result;

			result[0] = this->m_value[0] + m4.m_value[0];
			result[1] = this->m_value[1] + m4.m_value[1];
			result[2] = this->m_value[2] + m4.m_value[2];
			result[3] = this->m_value[3] + m4.m_value[3];

			return result;
		}
		Mat4		Mat4::operator-(const Mat4& m4)
		{
			Mat4 result;

			result[0] = this->m_value[0] - m4.m_value[0];
			result[1] = this->m_value[1] - m4.m_value[1];
			result[2] = this->m_value[2] - m4.m_value[2];
			result[3] = this->m_value[3] - m4.m_value[3];

			return result;
		}
		Mat4		Mat4::operator*(const float& scalar)
		{
			Mat4 result;

			result[0] = this->m_value[0] * scalar;
			result[1] = this->m_value[1] * scalar;
			result[2] = this->m_value[2] * scalar;
			result[3] = this->m_value[3] * scalar;

			return result;
		}
		Vec4		Mat4::operator*(Vec4 v4)
		{
			Vec4 result;

			result[0] = this->m_value[0][0] * v4.x + this->m_value[1][0] * v4.y + this->m_value[2][0] * v4.z + this->m_value[3][0] * v4.w;
			result[1] = this->m_value[0][1] * v4.x + this->m_value[1][1] * v4.y + this->m_value[2][1] * v4.z + this->m_value[3][1] * v4.w;
			result[2] = this->m_value[0][2] * v4.x + this->m_value[1][2] * v4.y + this->m_value[2][2] * v4.z + this->m_value[3][2] * v4.w;
			result[3] = this->m_value[0][3] * v4.x + this->m_value[1][3] * v4.y + this->m_value[2][3] * v4.z + this->m_value[3][3] * v4.w;

			return result;
		}
		Mat4		Mat4::operator*(Mat4 m4)
		{
			Mat4 result;

			result[0][0] = m4[0][0] * this->m_value[0][0] + m4[0][1] * this->m_value[1][0] + m4[0][2] * this->m_value[2][0] + m4[0][3] * this->m_value[3][0];
			result[0][1] = m4[0][0] * this->m_value[0][1] + m4[0][1] * this->m_value[1][1] + m4[0][2] * this->m_value[2][1] + m4[0][3] * this->m_value[3][1];
			result[0][2] = m4[0][0] * this->m_value[0][2] + m4[0][1] * this->m_value[1][2] + m4[0][2] * this->m_value[2][2] + m4[0][3] * this->m_value[3][2];
			result[0][3] = m4[0][0] * this->m_value[0][3] + m4[0][1] * this->m_value[1][3] + m4[0][2] * this->m_value[2][3] + m4[0][3] * this->m_value[3][3];

			result[1][0] = m4[1][0] * this->m_value[0][0] + m4[1][1] * this->m_value[1][0] + m4[1][2] * this->m_value[2][0] + m4[1][3] * this->m_value[3][0];
			result[1][1] = m4[1][0] * this->m_value[0][1] + m4[1][1] * this->m_value[1][1] + m4[1][2] * this->m_value[2][1] + m4[1][3] * this->m_value[3][1];
			result[1][2] = m4[1][0] * this->m_value[0][2] + m4[1][1] * this->m_value[1][2] + m4[1][2] * this->m_value[2][2] + m4[1][3] * this->m_value[3][2];
			result[1][3] = m4[1][0] * this->m_value[0][3] + m4[1][1] * this->m_value[1][3] + m4[1][2] * this->m_value[2][3] + m4[1][3] * this->m_value[3][3];

			result[2][0] = m4[2][0] * this->m_value[0][0] + m4[2][1] * this->m_value[1][0] + m4[2][2] * this->m_value[2][0] + m4[2][3] * this->m_value[3][0];
			result[2][1] = m4[2][0] * this->m_value[0][1] + m4[2][1] * this->m_value[1][1] + m4[2][2] * this->m_value[2][1] + m4[2][3] * this->m_value[3][1];
			result[2][2] = m4[2][0] * this->m_value[0][2] + m4[2][1] * this->m_value[1][2] + m4[2][2] * this->m_value[2][2] + m4[2][3] * this->m_value[3][2];
			result[2][3] = m4[2][0] * this->m_value[0][3] + m4[2][1] * this->m_value[1][3] + m4[2][2] * this->m_value[2][3] + m4[2][3] * this->m_value[3][3];

			result[3][0] = m4[3][0] * this->m_value[0][0] + m4[3][1] * this->m_value[1][0] + m4[3][2] * this->m_value[2][0] + m4[3][3] * this->m_value[3][0];
			result[3][1] = m4[3][0] * this->m_value[0][1] + m4[3][1] * this->m_value[1][1] + m4[3][2] * this->m_value[2][1] + m4[3][3] * this->m_value[3][1];
			result[3][2] = m4[3][0] * this->m_value[0][2] + m4[3][1] * this->m_value[1][2] + m4[3][2] * this->m_value[2][2] + m4[3][3] * this->m_value[3][2];
			result[3][3] = m4[3][0] * this->m_value[0][3] + m4[3][1] * this->m_value[1][3] + m4[3][2] * this->m_value[2][3] + m4[3][3] * this->m_value[3][3];

			return result;
		}
		Mat4		Mat4::operator/(const float& scalar)
		{
			Mat4 result;

			result[0] = this->m_value[0] / scalar;
			result[1] = this->m_value[1] / scalar;
			result[2] = this->m_value[2] / scalar;
			result[3] = this->m_value[3] / scalar;

			return result;
		}

		Mat4&		Mat4::operator+=(const Mat4& m4)
		{
			this->m_value[0] += m4.m_value[0];
			this->m_value[1] += m4.m_value[1];
			this->m_value[2] += m4.m_value[2];
			this->m_value[3] += m4.m_value[3];

			return *this;
		}
		Mat4&		Mat4::operator-=(const Mat4& m4)
		{
			this->m_value[0] -= m4.m_value[0];
			this->m_value[1] -= m4.m_value[1];
			this->m_value[2] -= m4.m_value[2];
			this->m_value[3] -= m4.m_value[3];

			return *this;
		}
		Mat4&		Mat4::operator*=(const float& scalar)
		{
			this->m_value[0] *= scalar;
			this->m_value[1] *= scalar;
			this->m_value[2] *= scalar;
			this->m_value[3] *= scalar;

			return *this;
		}
		Mat4&		Mat4::operator*=(Mat4 m4)
		{
			Mat4 m(*this);

			this->m_value[0][0] = m4[0][0] * m[0][0] + m4[0][1] * m[1][0] + m4[0][2] * m[2][0] + m4[0][3] * m[3][0];
			this->m_value[0][1] = m4[0][0] * m[0][1] + m4[0][1] * m[1][1] + m4[0][2] * m[2][1] + m4[0][3] * m[3][1];
			this->m_value[0][2] = m4[0][0] * m[0][2] + m4[0][1] * m[1][2] + m4[0][2] * m[2][2] + m4[0][3] * m[3][2];
			this->m_value[0][3] = m4[0][0] * m[0][3] + m4[0][1] * m[1][3] + m4[0][2] * m[2][3] + m4[0][3] * m[3][3];

			this->m_value[1][0] = m4[1][0] * m[0][0] + m4[1][1] * m[1][0] + m4[1][2] * m[2][0] + m4[1][3] * m[3][0];
			this->m_value[1][1] = m4[1][0] * m[0][1] + m4[1][1] * m[1][1] + m4[1][2] * m[2][1] + m4[1][3] * m[3][1];
			this->m_value[1][2] = m4[1][0] * m[0][2] + m4[1][1] * m[1][2] + m4[1][2] * m[2][2] + m4[1][3] * m[3][2];
			this->m_value[1][3] = m4[1][0] * m[0][3] + m4[1][1] * m[1][3] + m4[1][2] * m[2][3] + m4[1][3] * m[3][3];

			this->m_value[2][0] = m4[2][0] * m[0][0] + m4[2][1] * m[1][0] + m4[2][2] * m[2][0] + m4[2][3] * m[3][0];
			this->m_value[2][1] = m4[2][0] * m[0][1] + m4[2][1] * m[1][1] + m4[2][2] * m[2][1] + m4[2][3] * m[3][1];
			this->m_value[2][2] = m4[2][0] * m[0][2] + m4[2][1] * m[1][2] + m4[2][2] * m[2][2] + m4[2][3] * m[3][2];
			this->m_value[2][3] = m4[2][0] * m[0][3] + m4[2][1] * m[1][3] + m4[2][2] * m[2][3] + m4[2][3] * m[3][3];

			this->m_value[3][0] = m4[3][0] * m[0][0] + m4[3][1] * m[1][0] + m4[3][2] * m[2][0] + m4[3][3] * m[3][0];
			this->m_value[3][1] = m4[3][0] * m[0][1] + m4[3][1] * m[1][1] + m4[3][2] * m[2][1] + m4[3][3] * m[3][1];
			this->m_value[3][2] = m4[3][0] * m[0][2] + m4[3][1] * m[1][2] + m4[3][2] * m[2][2] + m4[3][3] * m[3][2];
			this->m_value[3][3] = m4[3][0] * m[0][3] + m4[3][1] * m[1][3] + m4[3][2] * m[2][3] + m4[3][3] * m[3][3];

			return *this;
		}
		Mat4&		Mat4::operator/=(const float& scalar)
		{
			this->m_value[0] /= scalar;
			this->m_value[1] /= scalar;
			this->m_value[2] /= scalar;
			this->m_value[3] /= scalar;

			return *this;
		}

		Mat4&		Mat4::operator=(const Mat4& m4)
		{
			this->m_value[0] = m4.m_value[0];
			this->m_value[1] = m4.m_value[1];
			this->m_value[2] = m4.m_value[2];
			this->m_value[3] = m4.m_value[3];

			return *this;
		}

		Vec4&		Mat4::operator[](size_t i)
		{
			if (i < 4)
				return this->m_value[i];

			throw std::out_of_range("Mat4::operator[](size_t i) out of range...");
		}
		Vec4 const& Mat4::operator[](size_t i) const
		{
			if (i < 4)
				return this->m_value[i];

			throw std::out_of_range("Mat4::operator[](size_t i) out of range...");
		}

		bool		Mat4::operator!=(const Mat4& m4) const { return this->m_value[0] != m4[0] || this->m_value[1] != m4[1] || this->m_value[2] != m4[2] || this->m_value[3] != m4[3]; }
		bool		Mat4::operator==(const Mat4& m4) const { return this->m_value[0] == m4[0] && this->m_value[1] == m4[1] && this->m_value[2] == m4[2] && this->m_value[3] != m4[3]; }

		Mat4		Mat4::Transpose() const
		{
			Mat4 result;

			result[0][0] = (*this)[0][0];
			result[0][1] = (*this)[1][0];
			result[0][2] = (*this)[2][0];
			result[0][3] = (*this)[3][0];

			result[1][0] = (*this)[0][1];
			result[1][1] = (*this)[1][1];
			result[1][2] = (*this)[2][1];
			result[1][3] = (*this)[3][1];

			result[2][0] = (*this)[0][2];
			result[2][1] = (*this)[1][2];
			result[2][2] = (*this)[2][2];
			result[2][3] = (*this)[3][2];

			result[3][0] = (*this)[0][3];
			result[3][1] = (*this)[1][3];
			result[3][2] = (*this)[2][3];
			result[3][3] = (*this)[3][3];

			return result;
		}
		Mat4&		Mat4::LoadIdentity()
		{
			this->m_value[0][0] = 1.0f; this->m_value[0][1] = 0.0f; this->m_value[0][2] = 0.0f; this->m_value[0][3] = 0.0f;
			this->m_value[1][0] = 0.0f; this->m_value[1][1] = 1.0f; this->m_value[1][2] = 0.0f; this->m_value[1][3] = 0.0f;
			this->m_value[2][0] = 0.0f; this->m_value[2][1] = 0.0f; this->m_value[2][2] = 1.0f; this->m_value[2][3] = 0.0f;
			this->m_value[3][0] = 0.0f; this->m_value[3][1] = 0.0f; this->m_value[3][2] = 0.0f; this->m_value[3][3] = 1.0f;

			return *this;
		}

		Mat4		Mat4::Translate(float factor) const { return Translate(Vec3(factor, factor, factor)); }
		Mat4		Mat4::Translate(float x, float y, float z) const { return Translate(Vec3(x, y, z)); }
		Mat4		Mat4::Translate(const Vec3& v3) const
		{
			Mat4 result(*this);

			result[3][0] = result[0][0] * v3.x + result[1][0] * v3.y + result[2][0] * v3.z + result[3][0];
			result[3][1] = result[0][1] * v3.x + result[1][1] * v3.y + result[2][1] * v3.z + result[3][1];
			result[3][2] = result[0][2] * v3.x + result[1][2] * v3.y + result[2][2] * v3.z + result[3][2];
			result[3][3] = result[0][3] * v3.x + result[1][3] * v3.y + result[2][3] * v3.z + result[3][3];

			return result;
		}

		Mat4		Mat4::Scale(float x, float y, float z) const { return Scale(Vec3(x, y, z)); }
		Mat4		Mat4::Scale(float factor) const { return Scale(Vec3(factor, factor, factor)); }
		Mat4		Mat4::Scale(const Vec3& v3) const
		{
			Mat4 result(*this);
			Vec4 const v4(v3);

			result[0][0] = result[0][0] * v4[0];
			result[0][1] = result[0][1] * v4[0];
			result[0][2] = result[0][2] * v4[0];
			result[0][3] = result[0][3] * v4[0];

			result[1][0] = result[1][0] * v4[1];
			result[1][1] = result[1][1] * v4[1];
			result[1][2] = result[1][2] * v4[1];
			result[1][3] = result[1][3] * v4[1];

			result[2][0] = result[2][0] * v4[2];
			result[2][1] = result[2][1] * v4[2];
			result[2][2] = result[2][2] * v4[2];
			result[2][3] = result[2][3] * v4[2];

			return result;
		}
	
		Mat4		Mat4::Rotate(const float& angle, const Vec3& v3)
		{
			Mat4 result(*this);
			Vec4 v4(v3);
			v4 = v4.Normalize();

			float cos = cosf(angle);
			float sin = sinf(angle);
			Vec4 tempV = v4 * (1.0f - cos);
			Mat4 tempM = *this;
			Mat4 rotate;

			rotate[0][0] = cos + tempV[0] * v4[0];
			rotate[0][1] = 0 + tempV[0] * v4[1] + sin * v4[2];
			rotate[0][2] = 0 + tempV[0] * v4[2] - sin * v4[1];

			rotate[1][0] = 0 + tempV[1] * v4[0] - sin * v4[2];
			rotate[1][1] = cos + tempV[1] * v4[1];
			rotate[1][2] = 0 + tempV[1] * v4[2] + sin * v4[0];

			rotate[2][0] = 0 + tempV[2] * v4[0] + sin * v4[1];
			rotate[2][1] = 0 + tempV[2] * v4[1] - sin * v4[0];
			rotate[2][2] = cos + tempV[2] * v4[2];

			result[0] = tempM[0] * rotate[0][0] + tempM[1] * rotate[0][1] + tempM[2] * rotate[0][2];
			result[1] = tempM[0] * rotate[1][0] + tempM[1] * rotate[1][1] + tempM[2] * rotate[1][2];
			result[2] = tempM[0] * rotate[2][0] + tempM[1] * rotate[2][1] + tempM[2] * rotate[2][2];
			result[3] = tempM[3];

			return result;
		}
		Mat4		Mat4::Rotate(float rotateX, float rotateY, float rotateZ)
		{
			Mat4 rx, ry, rz;

			float x = rotateX;
			float y = rotateY;
			float z = rotateZ;

			rx[0][0] = 1.0f;   rx[1][0] = 0.0f;   rx[2][0] = 0.0f;    rx[3][0] = 0.0f;
			rx[0][1] = 0.0f;   rx[1][1] = cos(x); rx[2][1] = -sin(x); rx[3][1] = 0.0f;
			rx[0][2] = 0.0f;   rx[1][2] = sin(x); rx[2][2] = cos(x);  rx[3][2] = 0.0f;
			rx[0][3] = 0.0f;   rx[1][3] = 0.0f;   rx[2][3] = 0.0f;    rx[3][3] = 1.0f;

			ry[0][0] = cos(y); ry[1][0] = 0.0f;   ry[2][0] = -sin(y); ry[3][0] = 0.0f;
			ry[0][1] = 0.0f;   ry[1][1] = 1.0f;   ry[2][1] = 0.0f;    ry[3][1] = 0.0f;
			ry[0][2] = sin(y); ry[1][2] = 0.0f;   ry[2][2] = cos(y);  ry[3][2] = 0.0f;
			ry[0][3] = 0.0f;   ry[1][3] = 0.0f;   ry[2][3] = 0.0f;    ry[3][3] = 1.0f;

			rz[0][0] = cos(z); rz[1][0] = -sin(z); rz[2][0] = 0.0f;   rz[3][0] = 0.0f;
			rz[0][1] = sin(z); rz[1][1] = cos(z);  rz[2][1] = 0.0f;   rz[3][1] = 0.0f;
			rz[0][2] = 0.0f;   rz[1][2] = 0.0f;    rz[2][2] = 1.0f;   rz[3][2] = 0.0f;
			rz[0][3] = 0.0f;   rz[1][3] = 0.0f;    rz[2][3] = 0.0f;   rz[3][3] = 1.0f;

			return rz * ry * rx;
		}
		Mat4		Mat4::RotateFromVectors(const Vec3& n, const Vec3& v, const Vec3& u)
		{
			Mat4 result;

			result[0][0] = u.x;   result[1][0] = u.y;   result[2][0] = u.z;   result[3][0] = 0.0f;
			result[0][1] = v.x;   result[1][1] = v.y;   result[2][1] = v.z;   result[3][1] = 0.0f;
			result[0][2] = n.x;   result[1][2] = n.y;   result[2][2] = n.z;   result[3][2] = 0.0f;
			result[0][3] = 0.0f;  result[1][3] = 0.0f;  result[2][3] = 0.0f;  result[3][3] = 1.0f;

			return result;
		}
		Mat4		Mat4::RotateFromDirection(const Vec3& forward, const Vec3& up)
		{
			Vec3 n = forward.Normalize();
			Vec3 u = Vec3(up.Normalize()).Cross(n);
			Vec3 v = n.Cross(u);

			return RotateFromVectors(n, v, u);
		}

		Mat4		Mat4::LookAt(const Vec3& eye, const Vec3& center, const Vec3& up)
		{
			Mat4 result(1.0f);
			Vec3 f = Vec3(center.x - eye.x, center.y - eye.y, center.z - eye.z).Normalize();
			Vec3 s = (f.Cross(up).Normalize());
			Vec3 u = s.Cross(f);

			result[0][0] = s.x;
			result[1][0] = s.y;
			result[2][0] = s.z;
			result[0][1] = u.x;
			result[1][1] = u.y;
			result[2][1] = u.z;
			result[0][2] = -f.x;
			result[1][2] = -f.y;
			result[2][2] = -f.z;
			result[3][0] = s.Dot(eye) * -1.0f;
			result[3][1] = u.Dot(eye) * -1.0f;
			result[3][2] = f.Dot(eye);

			return result;
		}
		Mat4		Mat4::Perspective(float fov, float aspectRatio, float zNear, float zFar)
		{
			Mat4 result;
			float tanHalfFovy = tan(fov / 2.0f);

			result[0][0] = 1.0f / (aspectRatio * tanHalfFovy);
			result[1][1] = 1.0f / (tanHalfFovy);
			result[2][2] = -(zFar + zNear) / (zFar - zNear);
			result[2][3] = -1.0f;
			result[3][2] = -(2.0f * zFar * zNear) / (zFar - zNear);

			return result;
		}
		Mat4		Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			Mat4  result;
			float width = (right - left);
			float height = (top - bottom);
			float depth = (far - near);

			result[0][0] = 2.0f / width; result[1][0] = 0.0f;          result[2][0] = 0.0f;          result[3][0] = -(right + left) / width;
			result[0][1] = 0.0f;         result[1][1] = 2.0f / height; result[2][1] = 0.0f;          result[3][1] = -(top + bottom) / height;
			result[0][2] = 0.0f;         result[1][2] = 0.0f;          result[2][2] = -2.0f / depth; result[3][2] = -(far + near) / depth;
			result[0][3] = 0.0f;         result[1][3] = 0.0f;          result[2][3] = 0.0f;          result[3][3] = 1.0f;

			return result;
		}

		std::string Mat4::ToString() const
		{
			std::string str = "";

			size_t size = 4;
			for (size_t i = 0; i < size; i++)
			{
				str += this->m_value[i].ToString();

				if (i < size - 1)
					str += "\n";
			}

			return str;
		}
	};
};