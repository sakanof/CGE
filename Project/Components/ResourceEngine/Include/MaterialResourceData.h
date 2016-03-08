#ifndef ResourceEngien_Data_MaterialResourceData_H
#define ResourceEngien_Data_MaterialResourceData_H

// Standard Includes
#include <memory>
#include <initializer_list>

// Math Includes
#include <SME\Include\SME.h>

// GameEngine Includes
#include "IResourceData.h"
#include "ImageResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		class RESOURCE_ENGINE_API MaterialResourceData : public IResourceData
		{
			using Color3 = SME::Color3;
		private:
			std::string m_name;

			Color3 m_ambientColor;
			Color3 m_difuseColor;
			Color3 m_specularColor;

			float m_shininess;
			float m_indexOfRefraction;
			float m_specularExponent;
			float m_opacity;
			float m_opticalDensity; // The amount of refraction is based on optical density

			ImageResourceDataVector	m_ambientTexture;
			ImageResourceDataVector	m_difuseTexture;
			ImageResourceDataVector	m_specularTexture;
			ImageResourceDataVector	m_shininessTexture;  // specular Highlight Component
			ImageResourceDataVector	m_opacityTexture;
			ImageResourceDataVector	m_heightMapTexture;
			ImageResourceDataVector	m_normalTexture;
			ImageResourceDataVector	m_displacementMapTexture;
			ImageResourceDataVector	m_stencilDecalTexture;

		public:
			MaterialResourceData(IResourceObserver* observer, const std::string& name = "Unknown", Color3 ka = Color3(1.0f, 1.0f, 1.0f), Color3 kd = Color3(1.0f, 1.0f, 1.0f), Color3 ks = Color3(1.0f, 1.0f, 1.0f));
			~MaterialResourceData();
		private:
			// Metodo de inicializacao dos atributos do material
			void Initialize(const std::string& name, Color3 ka, Color3 kd, Color3 ks);
			unsigned int GetImageResourceDataSizeInBytes(ImageResourceDataVector list) const;

		public:
			unsigned int Size() const;
			std::string	 Type() const;

			std::string GetName(void) const;

			Color3 GetAmbientColor(void) const;
			Color3 GetDifuseColor(void) const;
			Color3 GetSpecularColor(void) const;
			
			float GetIndexOfRefraction(void) const;
			float GetShininess(void) const;
			float GetSpecularExponent(void) const;
			float GetOpacity(void) const;
			float GetOpticalDensity(void) const;
			
			WeakImageResourceData GetAmbientTexture(unsigned int index) const;
			WeakImageResourceData GetDifuseTexture(unsigned int index) const;
			WeakImageResourceData GetSpecularTexture(unsigned int index) const;
			WeakImageResourceData GetShininessTexture(unsigned int index) const;
			WeakImageResourceData GetOpacityTexture(unsigned int index) const;
			WeakImageResourceData GetNormalTexture(unsigned int index) const;
			WeakImageResourceData GetHeightMapTexture(unsigned int index) const;
			WeakImageResourceData GetDisplacementMapTexture(unsigned int index) const;
			WeakImageResourceData GetStenceilDecalTexture(unsigned int index) const;

			bool HasAmbientTexture(void) const;
			bool HasDifuseTexture(void) const;
			bool HasSpecularTexture(void) const;
			bool HasShininessTexture(void) const;
			bool HasOpacityTexture(void) const;
			bool HasHeightMapTexture(void) const;
			bool HasNormalTexture(void) const;
			bool HasDisplacementMapTexture(void) const;
			bool HasStenceilDecalTexture(void) const;
				 
			void SetAmbientColor(Color3 ambientColor);
			void SetDifuseColor(Color3 difuseColor);
			void SetSpecularColor(Color3 specularColor);
			void SetIndexOfRefraction(float indexOfRefraction);
			void SetShininess(float shininess);
			void SetSpecularExponent(float specularExponent);
			void SetOpacity(float opacity);
			void SetName(const std::string& name);
			void SetOpticalDensity(float opticalDensity);
			
			void AddAmbientTexture(WeakImageResourceData ambientTexture);
			void AddDifuseTexture(WeakImageResourceData difuseTexture);
			void AddSpecularTexture(WeakImageResourceData specularTexture);
			void AddShininessTexture(WeakImageResourceData specularHighlight);
			void AddOpacityTexture(WeakImageResourceData alphaTexture);
			void AddHeightMapTexture(WeakImageResourceData heightMap);
			void AddNormalTexture(WeakImageResourceData bumpmap);
			void AddDisplacementMapTexture(WeakImageResourceData displacementMap);
			void AddStencilDecalTexture(WeakImageResourceData stencilDecal);
		
			void AddAmbientTexture(ImageResourceDataVector ambientTextureList);
			void AddDifuseTexture(ImageResourceDataVector difuseTextureList);
			void AddSpecularTexture(ImageResourceDataVector specularTextureList);
			void AddShininessTexture(ImageResourceDataVector specularHighlightList);
			void AddOpacityTexture(ImageResourceDataVector alphaTextureList);
			void AddHeightMapTexture(ImageResourceDataVector heightMapList);
			void AddNormalTexture(ImageResourceDataVector bumpmapList);
			void AddDisplacementMapTexture(ImageResourceDataVector displacementMapList);
			void AddStencilDecalTexture(ImageResourceDataVector stencilDecalList);
		};
		ExplicitExportDataContainers(MaterialResourceData)

		using SharedMaterialResourceData = std::shared_ptr < MaterialResourceData >;
		using MaterialResourceDataVector = std::vector < std::shared_ptr<MaterialResourceData> >;
		using MaterialResourceDataList   = std::list < std::shared_ptr<MaterialResourceData> >;
	};
};

#endif // ResourceEngien_Data_MaterialResourceData_H