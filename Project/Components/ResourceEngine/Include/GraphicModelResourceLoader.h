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
#include <Utilities\Include\BaseException.h>

// GameEngine Includes
#include "Resource.h"
#include "IResourceData.h"
#include "IResourceLoader.h"
#include "GraphicModelResourceData.h"
#include "MaterialResourceData.h"
#include "ImageResourceData.h"
#include "MeshNodeResourceData.h"
#include "ResourceCache.h"

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
				using WeakImageResourceData = ResourceEngine::Data::WeakImageResourceData;
				using SharedMeshResourceData = ResourceEngine::Data::SharedMeshResourceData;
				using SharedMeshNodeResourceData = ResourceEngine::Data::SharedMeshNodeResourceData;
				using WeakGraphicModelResourceDataVector = ResourceEngine::Data::WeakGraphicModelResourceDataVector;
				using WeakMaterialResourceDataVector = ResourceEngine::Data::WeakMaterialResourceDataVector;
				using WeakImageResourceDataVector = ResourceEngine::Data::WeakImageResourceDataVector;
				using WeakMeshResourceDataVector = ResourceEngine::Data::WeakMeshResourceDataVector;
				using WeakMeshNodeResourceDataVector = ResourceEngine::Data::WeakMeshNodeResourceDataVector;
			private:
				std::string m_currentAbsolutePath;

			public:
				GraphicModelResourceLoader(IResourceObserver* resourceObserver);
				~GraphicModelResourceLoader(void);

			private:
				void ProcessoObjects(aiNode* node, const aiScene* assimpScene, unsigned int* index, SharedMeshNodeResourceData myRootNode, WeakMaterialResourceDataVector materialList) const;
				
				void ProcessMaterials(const aiScene* assimpScene, WeakMaterialResourceDataVector materialList) const;
				
				SharedMaterialResourceData ExtractMaterialFrom(aiMaterial* material) const;
				
				SharedMeshResourceData ExtracMesh(aiMesh* assimpMesh, const std::string& name, const aiScene* assimpScene, WeakMaterialResourceDataVector materialList) const;
				
				WeakImageResourceData GetImageResourceData(const std::string& path) const;
				
				WeakImageResourceDataVector ExtractMaterialTextures(aiMaterial* material, aiTextureType textureType) const;

				Mat4 GetAssimNodeTransformation(aiNode* node) const;

			public:
				std::string  Pattern() const;

				bool IsPatternAccepted(const std::string pattern) const;

				__int64 GetRawResourceSize(const Resource& resource) const;

				IResourceData* Load(const Resource& resource) const;
			};
		};
	};
};

#endif // ResourceEngine_Loader_GraphicModelResourceLoader_H