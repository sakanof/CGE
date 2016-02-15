#ifndef ResourceEngine_Loader_GraphicModelResourceLoader_H
#define ResourceEngine_Loader_GraphicModelResourceLoader_H

// Standard Includes
#include <vector>
#include <memory>

// Third party Includes
#include <AssimpSDK\Include\cimport.h>
#include <AssimpSDK\Include\Importer.hpp>
#include <AssimpSDK\Include\scene.h>
#include <AssimpSDK\Include\postprocess.h>

// Util Includes
#include <Utilities\include\File.h>

// GameEngine Includes
#include "Resource.h"
#include "IResourceData.h"
#include "IResourceLoader.h"
#include "GraphicModelResourceData.h"
#include "MaterialResourceData.h"
#include "ImageResourceData.h"
#include "MeshNodeResourceData.h"

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
		{
			class RESOURCE_ENGINE_API GraphicModelResourceLoader : public IResourceLoader
			{
				using Color3 = SME::Color3;
				using Mat4 = SME::Mat4;

				using IResourceData = ResourceEngine::Data::IResourceData;
				using SharedResourceData = ResourceEngine::Data::SharedResourceData;
				using GraphicModelResourceData = ResourceEngine::Data::GraphicModelResourceData;
				using MaterialResourceData = ResourceEngine::Data::MaterialResourceData;
				using ImageResourceData = ResourceEngine::Data::ImageResourceData;
				using MeshResourceData = ResourceEngine::Data::MeshResourceData;
				using MeshNodeResourceData = ResourceEngine::Data::MeshNodeResourceData;
				using SharedGraphicModelResourceData = ResourceEngine::Data::SharedGraphicModelResourceData;
				using SharedMaterialResourceData = ResourceEngine::Data::SharedMaterialResourceData;
				using SharedImageResourceData = ResourceEngine::Data::SharedImageResourceData;
				using SharedMeshResourceData = ResourceEngine::Data::SharedMeshResourceData;
				using SharedMeshNodeResourceData = ResourceEngine::Data::SharedMeshNodeResourceData;
				using GraphicModelResourceDataVector = ResourceEngine::Data::GraphicModelResourceDataVector;
				using MaterialResourceDataVector = ResourceEngine::Data::MaterialResourceDataVector;
				using ImageResourceDataVector = ResourceEngine::Data::ImageResourceDataVector;
				using MeshResourceDataVector = ResourceEngine::Data::MeshResourceDataVector;
				using MeshNodeResourceDataVector = ResourceEngine::Data::MeshNodeResourceDataVector;
			private:
				std::string m_currentAbsolutePath;

			public:
				GraphicModelResourceLoader(void);
				~GraphicModelResourceLoader(void);

			private:
				void ProcessoObjects(aiNode* node, const aiScene* assimpScene, unsigned int* index, SharedMeshNodeResourceData myRootNode, MaterialResourceDataVector materialList) const;
				
				void ProcessMaterials(const aiScene* assimpScene, MaterialResourceDataVector materialList) const;
				
				SharedMaterialResourceData ExtractMaterialFrom(aiMaterial* material) const;
				
				SharedMeshResourceData ExtracMesh(aiMesh* assimpMesh, const std::string& name, const aiScene* assimpScene, MaterialResourceDataVector materialList) const;
				
				SharedImageResourceData GetImageResourceData(const std::string& path) const;
				
				ImageResourceDataVector ExtractMaterialTextures(aiMaterial* material, aiTextureType textureType) const;

				Mat4 GetAssimNodeTransformation(aiNode* node) const;

			public:
				std::string  Pattern() const = 0;

				bool IsPatternAccepted(const std::string pattern) const;

				__int64 GetRawResourceSize(const Resource& resource) const;

				IResourceData* Load(const Resource& resource) const;
			};
		};
	};
};

#endif // ResourceEngine_Loader_GraphicModelResourceLoader_H