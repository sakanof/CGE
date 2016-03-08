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
			ImageResourceData(IResourceObserver* observer, ImageData imageData);
			~ImageResourceData();

		public:
			unsigned int Size() const;
			std::string Type() const;

			ImageData GetImageData() const;
		};
		ExplicitExportDataContainers(ImageResourceData)

		using SharedImageResourceData       = std::shared_ptr < ImageResourceData >;
		using WeakImageResourceData         = std::weak_ptr < ImageResourceData >;
		using SharedImageResourceDataVector = std::vector < std::shared_ptr<ImageResourceData> >;
		using WeakImageResourceDataVector   = std::vector < std::weak_ptr<ImageResourceData> >;
		using SharedImageResourceDataList   = std::list < std::shared_ptr<ImageResourceData> >;
		using WeakImageResourceDataList     = std::list < std::weak_ptr<ImageResourceData> >;
	};
}; 

#endif // ResourceEngine_Data_ImageResourceData_H