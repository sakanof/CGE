#ifndef ResourceEngine_Data_MeshResourceData_H
#define ResourceEngine_Data_MeshResourceData_H

// Standard Includes
#include <string>
#include <memory>

// GameEngine Includes
#include "MaterialResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		enum class PolygonMode
		{
			Solid,
			Wireframe,
			Points
		};

		enum class PrimitiveType
		{
			Points,
			LineStrip,
			LineLoop,
			Lines,
			LineStripAdjacency,
			LinesAdjacency,
			TriangleStrip,
			TriangleFan,
			Triangles,
			TriangleStripAdjacency,
			TrianglesAdjacency
		};

		class RESOURCE_ENGINE_API MeshResourceData : public IResourceData
		{
		public:
			typedef std::weak_ptr<MeshResourceData> WeakPointer;
			typedef std::shared_ptr<MeshResourceData> StrongPointer;

		private:
			std::string					m_name;

			PolygonMode					m_polygonMode;

			PrimitiveType				m_primitiveType;
			
			FloatVector					m_vertices;
			FloatVector					m_normals;
			FloatVector					m_tangents;
			FloatVector					m_bitangents;
			
			VectorOfFloatVector			m_colors;
			VectorOfFloatVector			m_uvs;
			
			UnsignedIntVector			m_indices;
			
			WeakMaterialResourceData	m_material;

		public:
			MeshResourceData(IResourceObserver* observer);
			~MeshResourceData();

		public:
			unsigned int Size() const;
			std::string	 Type() const;

			std::string GetName() const;
			
			PolygonMode GetPolygonMode() const;

			PrimitiveType GetPrimitiveType(void) const;
			
			FloatVector GetVertices(void) const;
			FloatVector GetNormals(void) const;
			FloatVector GetTangents(void) const;
			FloatVector GetBitangents(void) const;
			
			VectorOfFloatVector GetColors() const;
			VectorOfFloatVector UVs() const;
			
			UnsignedIntVector GetIndices(void) const;
			
			WeakMaterialResourceData GetMaterial(void) const;

			void SetName(const std::string& name);
			void SetPolygonMode(PolygonMode polygonMode);
			void SetPrimitiveType(PrimitiveType primitiveType);
			void SetVertices(FloatVector vertices);
			void SetNormals(FloatVector normals);
			void SetTangents(FloatVector tangents);
			void SetBitangents(FloatVector bitangents);
			void SetColors(VectorOfFloatVector colors);
			void AddColors(FloatVector colors);
			void SetUVs(VectorOfFloatVector uvs);
			void AddUV(FloatVector uv);
			void SetIndices(UnsignedIntVector indices);
			void SetMaterial(WeakMaterialResourceData material);
		};
		ExplicitExportDataContainers(MeshResourceData)

		using SharedMeshResourceData       = MeshResourceData::StrongPointer;
		using WeakMeshResourceData         = MeshResourceData::WeakPointer;
		using SharedMeshResourceDataVector = std::vector < SharedMeshResourceData >;
		using WeakMeshResourceDataVector   = std::vector < WeakMeshResourceData >;
		using SharedMeshResourceDataList   = std::list < SharedMeshResourceData >;
		using WeakMeshResourceDataList     = std::list < WeakMeshResourceData >;
	};
};

#endif // ResourceEngine_Data_MeshResourceData_H