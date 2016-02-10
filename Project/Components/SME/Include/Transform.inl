#include "Transform.hpp"
#include "Vector.h"
#include "Matrix.h"
#include "Quaternion.h"

namespace SME
{
	Transform::Transform(const Vec3& position, const Quaternion& rotation, float scale)
		: m_position(position),
		  m_rotation(rotation),
		  m_scale(scale) {}

	inline Mat4 Transform::GetTransformation() const
	{
		Mat4 translationMatrix(1.0f);
		Mat4 scaleMatrix(1.0f);

		translationMatrix = translationMatrix.Translate(this->m_position);

		if (this->m_scale != 1.0f)
			scaleMatrix = scaleMatrix.Scale(this->m_scale);

		Mat4 result = translationMatrix * this->m_rotation.ToRotationMatrix() * scaleMatrix;

		return result;
	}
	inline void Transform::LookAt(const Vec3& point, const Vec3& up) { this->m_rotation = GetLookAtRotation(point, up); }

	inline Quaternion Transform::GetLookAtRotation(const Vec3& point, const Vec3& up)
	{
		return Quaternion(Mat4().RotateFromDirection(Vec3(point.x - m_position.x, point.y - m_position.y, point.z - m_position.z).Normalize(), up));
	}

	inline Vec3		  Transform::GetPosition() const { return this->m_position; }
	inline Quaternion Transform::GetRotation() const { return this->m_rotation; }
	inline float      Transform::GetScale()    const { return this->m_scale; }

	inline void Transform::SetPosition(float x, float y, float z) { this->m_position = Vec3(x, y, z); }
	inline void Transform::SetPosition(const Vec3& pos)			  { this->m_position = pos; }
	inline void Transform::SetRotation(const Quaternion& rot)	  { this->m_rotation = rot; }
	inline void Transform::SetScale(float scale)			      { this->m_scale = scale; }

	inline void Transform::Translate(const Vec3& translation)	 { this->m_position += translation; }
	inline void Transform::Translate(float x, float y, float z)	 { this->m_position += Vec3(x, y, z); }
	inline void Transform::Rotate(const Vec3& axis, float angle) { Rotate(Quaternion(axis, angle)); }
	inline void Transform::Rotate(const Quaternion& rotation)	 { this->m_rotation = Quaternion((rotation * this->m_rotation).Normalize()); }
	inline void Transform::Scale(float scale)					 { this->m_scale += scale; }
}; // namespace MathEngine