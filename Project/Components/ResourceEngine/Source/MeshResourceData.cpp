#include "../include/MeshResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		MeshResourceData::MeshResourceData() {}
		MeshResourceData::~MeshResourceData() 
		{
			this->m_vertices.clear();
			this->m_normals.clear();
			this->m_tangents.clear();
			this->m_bitangents.clear();
			this->m_indices.clear();
			this->m_colors.clear();
			this->m_uvs.clear();
		}

		unsigned int MeshResourceData::Size() const
		{
			unsigned int mySize = 0;

			mySize += this->m_vertices.size()   * sizeof(float);
			mySize += this->m_normals.size()    * sizeof(float);
			mySize += this->m_tangents.size()   * sizeof(float);
			mySize += this->m_bitangents.size() * sizeof(float);
			mySize += this->m_indices.size()    * sizeof(unsigned int);
			mySize += sizeof(PrimitiveType);
			mySize += sizeof(this->m_name);
			
			unsigned int index;
			for (index = 0; index < this->m_colors.size(); ++index)
				mySize += this->m_colors[index].size() * sizeof(float);

			for (index = 0; index < this->m_uvs.size(); ++index)
				mySize += this->m_uvs[index].size() * sizeof(float);

			return mySize;
		}
		std::string	 MeshResourceData::Type() const { return std::string("MeshResourceData"); }

		std::string MeshResourceData::GetName() const { return this->m_name; };
		
		PolygonMode MeshResourceData::GetPolygonMode() const { return this->m_polygonMode; }

		PrimitiveType MeshResourceData::GetPrimitiveType(void) const { return this->m_primitiveType; };
		
		FloatVector MeshResourceData::GetVertices(void) const { return this->m_vertices; };
		FloatVector MeshResourceData::GetNormals(void) const { return this->m_normals; };
		FloatVector MeshResourceData::GetTangents(void) const { return this->m_tangents; };
		FloatVector MeshResourceData::GetBitangents(void) const { return this->m_bitangents; };
		
		VectorOfFloatVector MeshResourceData::GetColors() const { return this->m_colors; }
		VectorOfFloatVector MeshResourceData::UVs() const { return this->m_uvs; }
		
		UnsignedIntVector MeshResourceData::GetIndices(void) const { return this->m_indices; };
		
		SharedMaterialResourceData MeshResourceData::GetMaterial(void) const { return this->m_material; }

		void MeshResourceData::SetName(const std::string& name){ this->m_name = name; };
		void MeshResourceData::SetPolygonMode(PolygonMode polygonMode) { this->m_polygonMode = polygonMode; }
		void MeshResourceData::SetPrimitiveType(PrimitiveType primitiveType){ this->m_primitiveType = primitiveType; };
		void MeshResourceData::SetVertices(FloatVector vertices) { this->m_vertices = vertices; };
		void MeshResourceData::SetNormals(FloatVector normals) { this->m_normals = normals; };
		void MeshResourceData::SetTangents(FloatVector tangents) { this->m_tangents = tangents; };
		void MeshResourceData::SetBitangents(FloatVector bitangents) { this->m_bitangents = bitangents; };
		void MeshResourceData::SetColors(VectorOfFloatVector colors) { this->m_colors = colors; };
		void MeshResourceData::AddColors(FloatVector colors) { this->m_colors.push_back(colors); };
		void MeshResourceData::SetUVs(VectorOfFloatVector uvs) { this->m_uvs = uvs; };
		void MeshResourceData::AddUV(FloatVector uv) { this->m_uvs.push_back(uv); };
		void MeshResourceData::SetIndices(UnsignedIntVector indices) { this->m_indices = indices; };
		void MeshResourceData::SetMaterial(SharedMaterialResourceData material) { this->m_material = material; }
	};
};