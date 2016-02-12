#ifndef Utilities_Memory_H
#define Utilities_Memory_H

namespace Utilities
{
	namespace Memory
	{
		template<typename T>
		void SafeDelete(T* toDelete)
		{
			delete toDelete;
			toDelete = nullptr;
		}

		template<typename T>
		void SafeDeleteArray(T* toDeleteArray)
		{
			delete[] toDeleteArray;
			toDeleteArray = nullptr;
		}
	};
}; 

#endif // Utilities_Memory_H