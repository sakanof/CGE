#ifndef SME_Transform_H
#define SME_Transform_H

// SME Inlcudes
#include "Definitions.h"

namespace SME
{
	class SIMPLE_MATH_ENGINE_API Transform
	{
	private:
		Vec3		m_position;
		Quaternion	m_rotation;
		float		m_scale;

	public:
		Transform(const Vec3& position = Vec3(0.0f, 0.0f, 0.0f), const Quaternion& rotation = Quaternion(0.0f, 0.0f, 0.0f, 1.0f), float scale = 1.0f);

		inline Mat4 GetTransformation() const;
		inline void LookAt(const Vec3& point, const Vec3& up);

		inline Quaternion GetLookAtRotation(const Vec3& point, const Vec3& up);

		inline Vec3		  GetPosition() const;
		inline Quaternion GetRotation() const;
		inline float      GetScale()    const;

		inline void SetPosition(float x, float y, float z);
		inline void SetPosition(const Vec3& pos);
		inline void SetRotation(const Quaternion& rot);
		inline void SetScale(float scale);

		inline void Translate(const Vec3& translation);
		inline void Translate(float x, float y, float z);
		inline void Rotate(const Vec3& axis, float angle);
		inline void Rotate(const Quaternion& rotation);
		inline void Scale(float scale);
	};
}; // namespace SME

#include "Transform.inl"

#endif // SME_Transform_H