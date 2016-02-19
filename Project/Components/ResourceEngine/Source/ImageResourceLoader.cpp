#include "../include/ImageResourceLoader.h"

namespace ResourceEngine
{
	namespace Loader
	{
		namespace Offline
		{
			using ImageResourceData = Data::ImageResourceData;
			using IResourceData = Data::IResourceData;

			ImageResourceLoader::ImageResourceLoader(IResourceObserver* resourceObserver) : IResourceLoader(resourceObserver) {}
			ImageResourceLoader::~ImageResourceLoader(void) {}

			std::string ImageResourceLoader::Pattern() const { return ".bmp .jpg .png .dds .tga .hdr .tif"; }
			bool ImageResourceLoader::IsPatternAccepted(const std::string pattern) const
			{
				auto temp = pattern;
				std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

				return Pattern().find(temp) != std::string::npos;
			}
			__int64 ImageResourceLoader::GetRawResourceSize(const Resource& resource) const { return Utilities::File::GetFileSize(resource.GetFilePath()); }
			IResourceData* ImageResourceLoader::Load(const Resource& resource) const
			{
				const char* path = resource.GetFilePath().c_str();
				Data::ImageData myImageDataResult;

				// Checks if the file exists
				std::unique_ptr<std::ifstream> inFile = std::unique_ptr<std::ifstream>(Utilities::File::OpenFile(resource.GetFilePath()));
				inFile->close();

				FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path, 0);
				FIBITMAP* tempImage = FreeImage_Load(format, path);
				auto convertedImage = FreeImage_ConvertTo32Bits(tempImage);

				FreeImage_Unload(tempImage);
				FreeImage_FlipVertical(convertedImage);

				myImageDataResult.width = FreeImage_GetWidth(convertedImage);
				myImageDataResult.height = FreeImage_GetHeight(convertedImage);

				size_t pixelsCount = myImageDataResult.width * myImageDataResult.height;
				size_t bufferSize = 4 * pixelsCount;
				char*  pixels = (char*)FreeImage_GetBits(convertedImage);

				myImageDataResult.buffer.resize(bufferSize);
				for (size_t pixelIndex = 0; pixelIndex < pixelsCount; pixelIndex++)
				{
					myImageDataResult.buffer[pixelIndex * 4 + 0] = pixels[pixelIndex * 4 + 2];
					myImageDataResult.buffer[pixelIndex * 4 + 1] = pixels[pixelIndex * 4 + 1];
					myImageDataResult.buffer[pixelIndex * 4 + 2] = pixels[pixelIndex * 4 + 0];
					myImageDataResult.buffer[pixelIndex * 4 + 3] = pixels[pixelIndex * 4 + 3];
				}
				FreeImage_Unload(convertedImage);
				pixels = nullptr;

				return new ImageResourceData(this->m_resourceObserver, std::move(myImageDataResult));
			}
		};
	}; 
}; 