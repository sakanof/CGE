#ifndef ResourceEngine_Loader_GraphicModelResourceLoader_H
#define ResourceEngine_Loader_GraphicModelResourceLoader_H

// Standard Includes
#include <vector>
#include <memory>

// Third party Includes
#include <assimp/cimport.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// Util Includes
#include <Utilities/Include/File.h>
#include <Utilities/Include/BaseException.h>

// GameEngine Includes
#include "Resource.h"
#include "IResourceData.h"
#include "IResourceLoader.h"
#include "GraphicModelResourceData.h"
#include "MaterialResourceData.h"
#include "ImageResourceData.h"
#include "MeshNodeResourceData.h"
#include "SimpleResourceCache.h"

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
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
			using WeakMaterialResourceData = ResourceEngine::Data::WeakMaterialResourceData;
			using WeakImageResourceData = ResourceEngine::Data::WeakImageResourceData;
			using SharedMeshResourceData = ResourceEngine::Data::SharedMeshResourceData;
			using SharedMeshNodeResourceData = ResourceEngine::Data::SharedMeshNodeResourceData;
			using WeakGraphicModelResourceDataVector = ResourceEngine::Data::WeakGraphicModelResourceDataVector;
			using SharedMaterialResourceDataVector = ResourceEngine::Data::SharedMaterialResourceDataVector;
			using WeakImageResourceDataVector = ResourceEngine::Data::WeakImageResourceDataVector;
			using WeakMeshResourceDataVector = ResourceEngine::Data::WeakMeshResourceDataVector;
			using WeakMeshNodeResourceDataVector = ResourceEngine::Data::WeakMeshNodeResourceDataVector;
			class RESOURCE_ENGINE_API GraphicModelResourceLoader : public IResourceLoader
			{
			private:
				IResourceCache::Ptr				 m_resourceCache;
				SharedMaterialResourceDataVector m_materialList;
				SharedMeshNodeResourceData       m_rootNode;

			public:
				GraphicModelResourceLoader(IResourceObserver* resourceObserver, IResourceCache::Ptr cache);
				~GraphicModelResourceLoader(void);

			private:
				void ProcessoObjects(aiNode* node, const aiScene* assimpScene, unsigned int* index);
				
				void ProcessMaterials(const aiScene* assimpScene);
				
				MaterialResourceData* ExtractMaterialFrom(aiMaterial* material);
				
				MeshResourceData* ExtracMesh(aiMesh* assimpMesh, const std::string& name, const aiScene* assimpScene);
				
				WeakImageResourceData GetImageResourceData(const std::string& path);
				
				WeakImageResourceDataVector ExtractMaterialTextures(aiMaterial* material, aiTextureType textureType);

				Mat4 GetAssimNodeTransformation(aiNode* node) const;

			public:
				std::string  Pattern() const;

				bool IsPatternAccepted(const std::string pattern) const;

				int64_t GetRawResourceSize(const Resource& resource) const;

				IResourceData* Load(const Resource& resource);
			};
		};
	};
};

#endif // ResourceEngine_Loader_GraphicModelResourceLoader_H
