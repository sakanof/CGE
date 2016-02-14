#ifndef ResourceEngine_Data_ImageResourceData_H
#define ResourceEngine_Data_ImageResourceData_H

// Standard Includes
#include <vector>

// Utilities Includes
#include <Utilities\Include\Memory.hpp>

// GameEngine Includes
#include "IResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		enum class ImageType
		{
			BMP,
			JPG,
			PNG,
			DDS,
			TGA,
			HDR,
			TIFF
		};

		using BufferData = std::vector < unsigned char >;
		struct ImageData
		{
			unsigned int width;
			unsigned int height;
			ImageType	 type;
			BufferData	 buffer;
		};
		
		class RESOURCE_ENGINE_API ImageResourceData : public IResourceData
		{
		private:
			ImageData m_imageData;

		public:
			ImageResourceData(ImageData imageData);
			~ImageResourceData();

		public:
			unsigned int Size() const;
			std::string Type() const;

			ImageData GetImageData() const;
		};
	}; 
}; 

#endif // ResourceEngine_Data_ImageResourceData_H