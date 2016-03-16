#ifndef ResourceEngineTest_Triangle_H
#define ResourceEngineTest_Triangle_H

// ResourceEngineTest Includes
#include "Mesh.h"

namespace ResourceEngineTest
{
	class Triangle
	{
	private:
		Mesh* m_mesh;

	public:
		Triangle();
		~Triangle();

	public:
		void Draw();
	};
};

#endif // ResourceEngineTest_Triangle_H