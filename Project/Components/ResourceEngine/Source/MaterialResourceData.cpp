#include "../include/MaterialResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		using Color3 = SME::Color3;

		MaterialResourceData::MaterialResourceData(IResourceObserver* observer, const std::string& name, Color3 ka, Color3 kd, Color3 ks)
			: IResourceData(observer)
		{
			Initialize(name, ka, ka, ks);
		}
		MaterialResourceData::~MaterialResourceData()
		{
			this->m_ambientTexture.clear();
			this->m_difuseTexture.clear();
			this->m_specularTexture.clear();
			this->m_shininessTexture.clear();
			this->m_opacityTexture.clear();
			this->m_heightMapTexture.clear();
			this->m_normalTexture.clear();
			this->m_displacementMapTexture.clear();
			this->m_stencilDecalTexture.clear();
		}
		void MaterialResourceData::Initialize(const std::string& name, Color3 ka, Color3 kd, Color3 ks)
		{
			SetName(name);
			SetAmbientColor(ka);
			SetDifuseColor(kd);
			SetSpecularColor(ks);
			SetOpacity(1.0f);
			SetShininess(1.0f);
			SetSpecularExponent(1.0f);
			SetOpticalDensity(1.0f);
			SetIndexOfRefraction(1.0f);
		}
		unsigned int MaterialResourceData::GetImageResourceDataSizeInBytes(WeakImageResourceDataVector list) const
		{
			unsigned int   sizeInBytes = 0;
			unsigned short index       = 0;
	
			for (index = 0; index < list.size(); ++index)
			{
				if(auto imageResourceData = list[index].lock())
					sizeInBytes += imageResourceData->Size();
			}

			return sizeInBytes;
		}

		size_t	MaterialResourceData::Size() const 
		{
			unsigned int sizeInBytes = 0;

			sizeInBytes += 5 * sizeof(float);
			sizeInBytes += 3 * sizeof(Color3);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_ambientTexture);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_difuseTexture);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_specularTexture);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_shininessTexture);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_opacityTexture);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_heightMapTexture);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_normalTexture);
			sizeInBytes += GetImageResourceDataSizeInBytes(this->m_displacementMapTexture);
			//sizeInBytes += GetImageResourceDataSizeInBytes(this->m_stencilDecalTexture);

			return sizeInBytes;
		}
		std::string	MaterialResourceData::Type() const { return std::string("MaterialResourceData"); }

		std::string MaterialResourceData::GetName(void) const { return this->m_name; }

		Color3 MaterialResourceData::GetAmbientColor(void) const { return this->m_ambientColor; }
		Color3 MaterialResourceData::GetDifuseColor(void) const { return this->m_difuseColor; }
		Color3 MaterialResourceData::GetSpecularColor(void) const { return this->m_specularColor; }
			   
		float MaterialResourceData::GetIndexOfRefraction(void) const { return this->m_indexOfRefraction; }
		float MaterialResourceData::GetShininess(void) const { return this->m_shininess; }
		float MaterialResourceData::GetSpecularExponent(void) const { return this->m_specularExponent; }
		float MaterialResourceData::GetOpacity(void) const { return this->m_opacity; }
		float MaterialResourceData::GetOpticalDensity(void) const { return this->m_opticalDensity; }
			
		WeakImageResourceData MaterialResourceData::GetAmbientTexture(unsigned int index) const { return this->m_ambientTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetDifuseTexture(unsigned int index) const { return this->m_difuseTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetSpecularTexture(unsigned int index) const { return this->m_specularTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetShininessTexture(unsigned int index) const { return this->m_shininessTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetOpacityTexture(unsigned int index) const { return this->m_opacityTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetHeightMapTexture(unsigned int index) const { return this->m_heightMapTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetNormalTexture(unsigned int index) const { return this->m_normalTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetDisplacementMapTexture(unsigned int index) const { return this->m_displacementMapTexture[index]; }
		WeakImageResourceData MaterialResourceData::GetStenceilDecalTexture(unsigned int index) const { return this->m_stencilDecalTexture[index]; }
			
		bool MaterialResourceData::HasAmbientTexture(void) const { return this->m_ambientTexture.size() > 0; }
		bool MaterialResourceData::HasDifuseTexture(void) const { return this->m_difuseTexture.size() > 0; }
		bool MaterialResourceData::HasSpecularTexture(void) const { return this->m_specularTexture.size() > 0; }
		bool MaterialResourceData::HasShininessTexture(void) const { return this->m_shininessTexture.size() > 0; }
		bool MaterialResourceData::HasOpacityTexture(void) const { return this->m_opacityTexture.size() > 0; }
		bool MaterialResourceData::HasHeightMapTexture(void) const { return this->m_heightMapTexture.size() > 0; }
		bool MaterialResourceData::HasNormalTexture(void) const { return this->m_normalTexture.size() > 0; }
		bool MaterialResourceData::HasDisplacementMapTexture(void) const { return this->m_displacementMapTexture.size() > 0; }
		bool MaterialResourceData::HasStenceilDecalTexture(void) const { return this->m_stencilDecalTexture.size() > 0; }
			 
		void MaterialResourceData::SetAmbientColor(Color3 ambientColor) { this->m_ambientColor = ambientColor; }
		void MaterialResourceData::SetDifuseColor(Color3 difuseColor) { this->m_difuseColor = difuseColor; }
		void MaterialResourceData::SetSpecularColor(Color3 specularColor) { this->m_specularColor = specularColor; }
		void MaterialResourceData::SetIndexOfRefraction(float indexOfRefraction) { this->m_indexOfRefraction = indexOfRefraction; }
		void MaterialResourceData::SetSpecularExponent(float specularExponent) { this->m_specularExponent = specularExponent; }
		void MaterialResourceData::SetShininess(float shininess) { this->m_shininess = shininess; }
		void MaterialResourceData::SetOpacity(float opacity) { this->m_opacity = opacity; }
		void MaterialResourceData::SetOpticalDensity(float opticalDensity) { this->m_opticalDensity = opticalDensity; }
		void MaterialResourceData::SetName(const std::string& name) { this->m_name = std::string(name); }
			 
		void MaterialResourceData::AddAmbientTexture(WeakImageResourceData ambientTexture) 
		{ 
			if (auto texture = ambientTexture.lock())
				this->m_ambientTexture.push_back(ambientTexture); 
		}
		void MaterialResourceData::AddDifuseTexture(WeakImageResourceData difuseTexture) 
		{ 
			if (auto texture = difuseTexture.lock())
				this->m_difuseTexture.push_back(difuseTexture); 
		}
		void MaterialResourceData::AddSpecularTexture(WeakImageResourceData specularTexture) 
		{ 
			if (auto texture = specularTexture.lock())
				this->m_specularTexture.push_back(specularTexture);
		}
		void MaterialResourceData::AddShininessTexture(WeakImageResourceData specularHighlight) 
		{ 
			if (auto texture = specularHighlight.lock())
				this->m_shininessTexture.push_back(specularHighlight);
		}
		void MaterialResourceData::AddOpacityTexture(WeakImageResourceData alphaTexture) 
		{ 
			if (auto texture = alphaTexture.lock())
				this->m_opacityTexture.push_back(alphaTexture);
		}
		void MaterialResourceData::AddHeightMapTexture(WeakImageResourceData heightMap) 
		{ 
			if (auto texture = heightMap.lock())
				this->m_heightMapTexture.push_back(heightMap);
		}
		void MaterialResourceData::AddNormalTexture(WeakImageResourceData bumpmap) 
		{ 
			if (auto texture = bumpmap.lock())
				this->m_normalTexture.push_back(bumpmap);
		}
		void MaterialResourceData::AddDisplacementMapTexture(WeakImageResourceData displacementMap)
		{ 
			if (auto texture = displacementMap.lock())
				this->m_displacementMapTexture.push_back(displacementMap);
		}
		void MaterialResourceData::AddStencilDecalTexture(WeakImageResourceData stencilDecal) 
		{ 
			if (auto texture = stencilDecal.lock())
				this->m_stencilDecalTexture.push_back(stencilDecal);
		}
			 
		void MaterialResourceData::AddAmbientTexture(WeakImageResourceDataVector ambientTextureList) { this->m_ambientTexture.insert(this->m_ambientTexture.end(), ambientTextureList.begin(), ambientTextureList.end()); }
		void MaterialResourceData::AddDifuseTexture(WeakImageResourceDataVector difuseTextureList) { this->m_difuseTexture.insert(this->m_difuseTexture.end(), difuseTextureList.begin(), difuseTextureList.end()); }
		void MaterialResourceData::AddSpecularTexture(WeakImageResourceDataVector specularTextureList) { this->m_specularTexture.insert(this->m_specularTexture.end(), specularTextureList.begin(), specularTextureList.end()); }
		void MaterialResourceData::AddShininessTexture(WeakImageResourceDataVector specularHighlightList) { this->m_shininessTexture.insert(this->m_shininessTexture.end(), specularHighlightList.begin(), specularHighlightList.end()); }
		void MaterialResourceData::AddOpacityTexture(WeakImageResourceDataVector alphaTextureList) { this->m_opacityTexture.insert(this->m_opacityTexture.end(), alphaTextureList.begin(), alphaTextureList.end()); }
		void MaterialResourceData::AddHeightMapTexture(WeakImageResourceDataVector heightMapList) { this->m_heightMapTexture.insert(this->m_heightMapTexture.end(), heightMapList.begin(), heightMapList.end()); }
		void MaterialResourceData::AddNormalTexture(WeakImageResourceDataVector bumpmapList) { this->m_normalTexture.insert(this->m_normalTexture.end(), bumpmapList.begin(), bumpmapList.end()); }
		void MaterialResourceData::AddDisplacementMapTexture(WeakImageResourceDataVector displacementMapList) { this->m_displacementMapTexture.insert(this->m_displacementMapTexture.end(), displacementMapList.begin(), displacementMapList.end()); }
		void MaterialResourceData::AddStencilDecalTexture(WeakImageResourceDataVector stencilDecalList) { this->m_stencilDecalTexture.insert(this->m_stencilDecalTexture.end(), stencilDecalList.begin(), stencilDecalList.end()); }
	};
};
