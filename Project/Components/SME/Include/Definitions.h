#ifndef MathEngine_Definitions_H
#define MathEngine_Definitions_H

#include <vector>
#include <list>

// MathEngine Includes
#include "SimpleMathEngineSetup.h"

namespace MathEngine
{
	using FloatVector	= std::vector<float>;
	using FloatList		= std::list<float>;

	namespace Vector
	{
		class SIMPLE_MATH_ENGINE_API Vec2;
		class SIMPLE_MATH_ENGINE_API Vec3;
		class SIMPLE_MATH_ENGINE_API Vec4;
	};
	using Vec2 = MathEngine::Vector::Vec2;
	using Vec3 = MathEngine::Vector::Vec3;
	using Vec4 = MathEngine::Vector::Vec4;

	using Point2	= Vector::Vec2;
	using Point3	= Vector::Vec3;
	using Color3	= Vector::Vec3;
	using Color4	= Vector::Vec4;
	using ColorRGB	= Vector::Vec3;
	using ColorRGBA	= Vector::Vec4;

	namespace Matrix
	{
		class SIMPLE_MATH_ENGINE_API Mat2;
		class SIMPLE_MATH_ENGINE_API Mat3;
		class SIMPLE_MATH_ENGINE_API Mat4;
	};
	using Mat2 = MathEngine::Matrix::Mat2;
	using Mat3 = MathEngine::Matrix::Mat3;
	using Mat4 = MathEngine::Matrix::Mat4;

	class SIMPLE_MATH_ENGINE_API Quaternion;
	class SIMPLE_MATH_ENGINE_API Transform;
}

#endif // MathEngine_Definitions_H