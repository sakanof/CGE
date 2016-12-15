#ifndef ResourceEngine_Data_ImageResourceData_H
#define ResourceEngine_Data_ImageResourceData_H

// Standard Includes
#include <vector>

// Utilities Includes
#include <Utilities/Include/Memory.hpp>

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
		public:
			typedef std::weak_ptr<ImageResourceData> WeakPointer;
			typedef std::shared_ptr<ImageResourceData> StrongPointer;

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

		using SharedImageResourceData       = ImageResourceData::StrongPointer;
		using WeakImageResourceData         = ImageResourceData::WeakPointer;
		using SharedImageResourceDataVector = std::vector < SharedImageResourceData >;
		using WeakImageResourceDataVector   = std::vector < WeakImageResourceData >;
		using SharedImageResourceDataList   = std::list < SharedImageResourceData >;
		using WeakImageResourceDataList     = std::list < WeakImageResourceData >;
	};
}; 

#endif // ResourceEngine_Data_ImageResourceData_H
