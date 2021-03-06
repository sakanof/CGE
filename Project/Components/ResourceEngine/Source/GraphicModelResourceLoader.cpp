#include "../Include/GraphicModelResourceLoader.h"

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
		{
			GraphicModelResourceLoader::GraphicModelResourceLoader(IResourceObserver* resourceObserver, IResourceCache::Ptr cache)
				: IResourceLoader(resourceObserver),
				  m_resourceCache(cache) {}
			GraphicModelResourceLoader::~GraphicModelResourceLoader(void) {}

			void GraphicModelResourceLoader::ProcessoObjects(aiNode* node, const aiScene* assimpScene, unsigned int* index)
			{
				SharedMeshNodeResourceData myNode = std::make_shared<MeshNodeResourceData>(this->m_resourceObserver);

				myNode->SetTransformation(GetAssimNodeTransformation(node));

				unsigned int meshIndex;
				for (meshIndex = 0; meshIndex < node->mNumMeshes; meshIndex++)
				{
					auto myMesh = std::shared_ptr<MeshResourceData>(ExtracMesh(assimpScene->mMeshes[*index + meshIndex], node->mName.C_Str(), assimpScene));
					myNode->AddMesh(myMesh);
				}
				if (meshIndex > 0)
				{
					myNode->SetParent(this->m_rootNode);
					this->m_rootNode->AddChild(myNode);
				}

				*index += meshIndex;
				for (unsigned int childIndex = 0; childIndex < node->mNumChildren; childIndex++)
					ProcessoObjects(node->mChildren[childIndex], assimpScene, index);
			}
			
			void GraphicModelResourceLoader::ProcessMaterials(const aiScene* assimpScene)
			{
				unsigned int materialIndex;
				for (materialIndex = 0; materialIndex < assimpScene->mNumMaterials; ++materialIndex)
				{
					auto myMaterial = std::shared_ptr<MaterialResourceData>(ExtractMaterialFrom(assimpScene->mMaterials[materialIndex]));
					this->m_materialList.push_back(myMaterial);
				}
			} 
			
			MeshResourceData* GraphicModelResourceLoader::ExtracMesh(aiMesh* assimpMesh, const std::string& name, const aiScene* assimpScene)
			{
				try
				{
					MeshResourceData* myMesh = new MeshResourceData(this->m_resourceObserver);
					
					std::vector<float>				vertices;
					std::vector<float>				normals;
					std::vector<float>				tangents;
					std::vector<float>				bitangents;
					std::vector<std::vector<float>>	colors;
					std::vector<std::vector<float>>	uvs;
					std::vector<unsigned int>		indices;

					unsigned int index;
					for (index = 0; index < assimpMesh->mNumVertices; ++index)
					{
						// Vertices
						vertices.push_back(assimpMesh->mVertices[index].x);
						vertices.push_back(assimpMesh->mVertices[index].y);
						vertices.push_back(assimpMesh->mVertices[index].z);
					}

					// Colors
					for (unsigned int colorsIndex = 0; colorsIndex < AI_MAX_NUMBER_OF_COLOR_SETS; ++colorsIndex)
					{
						if (assimpMesh->HasVertexColors(colorsIndex))
						{
							colors.push_back(std::vector<float>());
							for (index = 0; index < assimpMesh->mNumVertices; index++)
							{
								colors[colorsIndex].push_back(assimpMesh->mColors[colorsIndex][index].r);
								colors[colorsIndex].push_back(assimpMesh->mColors[colorsIndex][index].g);
								colors[colorsIndex].push_back(assimpMesh->mColors[colorsIndex][index].b);
							}
						}
					}

					// UVs
					for (unsigned int uvIndex = 0; uvIndex < AI_MAX_NUMBER_OF_TEXTURECOORDS; ++uvIndex)
					{
						if (assimpMesh->HasTextureCoords(uvIndex))
						{
							uvs.push_back(std::vector<float>());
							for (index = 0; index < assimpMesh->mNumVertices; index++)
							{
								uvs[uvIndex].push_back(assimpMesh->mTextureCoords[uvIndex][index].x);
								uvs[uvIndex].push_back(assimpMesh->mTextureCoords[uvIndex][index].y);
							}
						}
					}

					// Normals
					if (assimpMesh->HasNormals())
					{
						for (index = 0; index < assimpMesh->mNumVertices; index++)
						{
							normals.push_back(assimpMesh->mNormals[index].x);
							normals.push_back(assimpMesh->mNormals[index].y);
							normals.push_back(assimpMesh->mNormals[index].z);
						}
					}

					// Tangents
					if (assimpMesh->HasTangentsAndBitangents())
					{
						for (index = 0; index < assimpMesh->mNumVertices; index++)
						{
							tangents.push_back(assimpMesh->mTangents[index].x);
							tangents.push_back(assimpMesh->mTangents[index].y);
							tangents.push_back(assimpMesh->mTangents[index].z);

							bitangents.push_back(assimpMesh->mBitangents[index].x);
							bitangents.push_back(assimpMesh->mBitangents[index].y);
							bitangents.push_back(assimpMesh->mBitangents[index].z);
						}
					}

					//Indices
					for (unsigned int i = 0; i < assimpMesh->mNumFaces; i++)
					{
						aiFace assimpFace = assimpMesh->mFaces[i];
						for (unsigned int j = 0; j < assimpFace.mNumIndices; j++)
							indices.push_back(assimpFace.mIndices[j]);
					}

					myMesh->SetVertices(vertices);
					myMesh->SetColors(colors);
					myMesh->SetNormals(normals);
					myMesh->SetUVs(uvs);
					myMesh->SetTangents(tangents);
					myMesh->SetBitangents(bitangents);
					myMesh->SetIndices(indices);
					
					if (this->m_materialList.size() != 0 && this->m_materialList.size() >= assimpMesh->mMaterialIndex)
						myMesh->SetMaterial(this->m_materialList[assimpMesh->mMaterialIndex]);

					return myMesh;
				}
				catch (std::out_of_range e)
				{
					//throw std::exception("Error during model information extraction. Index out of range.");
					throw std::exception(e);
				}
				catch (std::exception e)
				{
					//throw std::exception(e.what());
					throw std::exception(e);
				}
			}
			
			MaterialResourceData* GraphicModelResourceLoader::ExtractMaterialFrom(aiMaterial* material)
			{
				try
				{
					float				  shininess = 0.0f;	// WavefrontMaterial token: Ns
					float				  indexOfRefraction = 0.0f;	// WavefrontMaterial token: Ni
					float				  opacity = 1.0f;	// WavefrontMaterial token: d
					aiString			  myMaterialName = aiString("");;
					MaterialResourceData* myResultMaterial = new MaterialResourceData(this->m_resourceObserver);
					aiColor4D			  ambientColor;
					aiColor4D			  difuseColor;
					aiColor4D			  specularColor;

					if (aiGetMaterialString(material, AI_MATKEY_NAME, &myMaterialName) == AI_SUCCESS)
						myResultMaterial->SetName(myMaterialName.C_Str());

					if (aiGetMaterialColor(material, AI_MATKEY_COLOR_AMBIENT, &ambientColor) == AI_SUCCESS)
						myResultMaterial->SetAmbientColor(Color3(ambientColor.r, ambientColor.g, ambientColor.b));

					if (aiGetMaterialColor(material, AI_MATKEY_COLOR_DIFFUSE, &difuseColor) == AI_SUCCESS)
						myResultMaterial->SetDifuseColor(Color3(difuseColor.r, difuseColor.g, difuseColor.b));

					if (aiGetMaterialColor(material, AI_MATKEY_COLOR_SPECULAR, &specularColor) == AI_SUCCESS)
						myResultMaterial->SetSpecularColor(Color3(specularColor.r, specularColor.g, specularColor.b));

					if (aiGetMaterialFloat(material, AI_MATKEY_SHININESS, &shininess) == AI_SUCCESS)
						myResultMaterial->SetShininess(shininess / 4.0f);

					if (aiGetMaterialFloat(material, AI_MATKEY_OPACITY, &opacity) == AI_SUCCESS)
						myResultMaterial->SetOpacity(opacity);

					if (aiGetMaterialFloat(material, AI_MATKEY_REFRACTI, &indexOfRefraction) == AI_SUCCESS)
						myResultMaterial->SetIndexOfRefraction(indexOfRefraction);

					myResultMaterial->AddAmbientTexture(ExtractMaterialTextures(material, aiTextureType_AMBIENT));
					myResultMaterial->AddDifuseTexture(ExtractMaterialTextures(material, aiTextureType_DIFFUSE));
					myResultMaterial->AddSpecularTexture(ExtractMaterialTextures(material, aiTextureType_SPECULAR));
					myResultMaterial->AddDisplacementMapTexture(ExtractMaterialTextures(material, aiTextureType_DISPLACEMENT));
					myResultMaterial->AddNormalTexture(ExtractMaterialTextures(material, aiTextureType_NORMALS));
					myResultMaterial->AddOpacityTexture(ExtractMaterialTextures(material, aiTextureType_OPACITY));
					myResultMaterial->AddHeightMapTexture(ExtractMaterialTextures(material, aiTextureType_HEIGHT));
					myResultMaterial->AddShininessTexture(ExtractMaterialTextures(material, aiTextureType_SHININESS));

					return myResultMaterial;
				}
				catch (std::exception exception)
				{
					std::string errorMessage = "Error during material information extraction. ";
					errorMessage += exception.what();

					throw Utilities::Exception::BaseException(__FILE__, __LINE__, errorMessage);
				}
			}
			
			WeakImageResourceData GraphicModelResourceLoader::GetImageResourceData(const std::string& path)
			{
				return this->m_resourceCache->GetHandle(Resource(path))->GetResourceData<ImageResourceData>();
			}
			
			WeakImageResourceDataVector GraphicModelResourceLoader::ExtractMaterialTextures(aiMaterial* material, aiTextureType textureType)
			{
				unsigned short			textureIndex = 0;
				unsigned short			textureCount = 0;
				aiString				texturePath = aiString("");
				WeakImageResourceDataVector	textureList;

				textureCount = material->GetTextureCount(textureType);
				for (textureIndex = 0; textureIndex < textureCount; ++textureIndex)
				{
					material->GetTexture(textureType, textureIndex, &texturePath);
					textureList.push_back(GetImageResourceData(texturePath.C_Str()));
				}

				return textureList;
			}
	
			Mat4 GraphicModelResourceLoader::GetAssimNodeTransformation(aiNode* node) const
			{
				aiMatrix4x4 nodeTransformation = node->mTransformation;
				Mat4 result;

				result[0][0] = nodeTransformation[0][0];
				result[0][1] = nodeTransformation[0][1];
				result[0][2] = nodeTransformation[0][2];
				result[0][3] = nodeTransformation[0][3];

				result[1][0] = nodeTransformation[1][0];
				result[1][1] = nodeTransformation[1][1];
				result[1][2] = nodeTransformation[1][2];
				result[1][3] = nodeTransformation[1][3];

				result[2][0] = nodeTransformation[2][0];
				result[2][1] = nodeTransformation[2][1];
				result[2][2] = nodeTransformation[2][2];
				result[2][3] = nodeTransformation[2][3];

				result[3][0] = nodeTransformation[3][0];
				result[3][1] = nodeTransformation[3][1];
				result[3][2] = nodeTransformation[3][2];
				result[3][3] = nodeTransformation[3][3];

				return result;
			}

			std::string GraphicModelResourceLoader::Pattern() const { return "*.dae *.blend *.3ds *.obj *.ifc *.fbx *.xgl *.ply *.dxf *.lwo *.lws *.irrmesh *.mdl *.hmp *.ter"; }
			bool GraphicModelResourceLoader::IsPatternAccepted(const std::string pattern) const
			{
				auto temp = pattern;
				std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				return Pattern().find(temp) != std::string::npos;
			}
			int64_t GraphicModelResourceLoader::GetRawResourceSize(const Resource& resource) const { return Utilities::File::GetFileSize(resource.GetFilePath()); }
			IResourceData* GraphicModelResourceLoader::Load(const Resource& resource)
			{
				this->m_rootNode = std::make_shared<MeshNodeResourceData>(this->m_resourceObserver);

				Assimp::Importer assimpImporter;
				const aiScene* assimpScene = assimpImporter.ReadFile(resource.GetFilePath(),
					aiProcess_GenSmoothNormals | aiProcess_Triangulate | /*aiProcess_GenUVCoords*/
					aiProcess_CalcTangentSpace | aiProcess_FlipUVs);

				if (assimpScene == nullptr /*|| assimpScene->mFlags != AI_SCENE_FLAGS_INCOMPLETE */ || assimpScene->mRootNode == nullptr)
					throw Utilities::Exception::FileNotFoundException(__FILE__, __LINE__, "Error during file '" + resource.GetFilePath() + "' parsing.");

				ProcessMaterials(assimpScene);

				unsigned int index = 0;
				ProcessoObjects(assimpScene->mRootNode, assimpScene, &index);

				auto result = new GraphicModelResourceData(this->m_resourceObserver, this->m_rootNode, this->m_materialList);

				//this->m_materialList.clear();
				//this->m_rootNode.reset(nullptr);

				return result;
			};
		};
	};
};
