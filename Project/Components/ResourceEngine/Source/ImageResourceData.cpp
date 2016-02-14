#include "../include/ImageResourceData.h"

namespace ResourceEngine
{
	namespace Data
	{
		ImageResourceData::ImageResourceData(ImageData imageData)
			: m_imageData(imageData) {}
		ImageResourceData::~ImageResourceData() {}
		unsigned int  ImageResourceData::Size() const 
		{ 
			return (sizeof(size_t) * 2) +
				    sizeof(ImageType)   + 
					sizeof(unsigned char) * this->m_imageData.buffer.size();
		}
		std::string	ImageResourceData::Type() const { return "ImageResourceData"; }
		ImageData ImageResourceData::GetImageData() const { return this->m_imageData; }
	}; 
}; 