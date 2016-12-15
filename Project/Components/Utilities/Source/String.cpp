#include "../Include/String.h"


namespace Utilities
{
	namespace String
	{
		vector<string>	Split(const string& s, char delim)
		{
			vector<string> elems;

			auto localStr = Trim(s);
			unsigned int strLength = (unsigned int)s.length();
			unsigned int start = 0;
			unsigned int end = 0;

			while (end <= strLength)
			{
				bool foundDelimiter = false;
				while (end <= strLength && !foundDelimiter)
				{
					if (localStr[end] == delim)
						foundDelimiter = true;

					end++;
				}

				elems.push_back(s.substr(start, end - start - 1));
				start = end;
				end += 1;
			}

			return elems;
		}
		vector<string>	Split(const string& s, const std::string& delim)
		{
			vector<string> elems;

			string localString = Trim(s);

			size_t index;
			size_t offset;
			do
			{
				index = localString.find(delim);
				offset = index + delim.length();

				if (index != string::npos)
				{
					string temp = localString;
					temp.erase(0, offset);
					bool notFound = false;
					do
					{
						if (temp.find(delim) == 0)
						{
							offset += delim.length();
							temp.erase(0, delim.length());
						}
						else
							notFound = true;
					} while (!notFound);

					string value = localString.substr(0, index);
					if (!value.empty())
						elems.push_back(value);

					localString = localString.erase(0, offset);
				}
				else if (elems.size() > 0 && !localString.empty())
					elems.push_back(localString);

			} while (index != string::npos);

			localString.clear();

			return elems;
		}
		string			Replace(const string& str, char characterToReplace, char newCharacter)
		{
			string ret = string(str);

			for (size_t i = 0; i < ret.length(); i++)
			{
				if (ret[i] == characterToReplace)
					ret[i] = newCharacter;
			}

			return ret;
		}
		string			TrimBack(const string& str)
		{
			string ret = string(str);
			bool isEmpty = true;

			size_t i = 0;
			for (i = 0; i < ret.length() && isEmpty; i++)
			{
				if (ret[i] != ' ')
					isEmpty = false;;
			}
			if (i - 1 > 0)
				ret.erase(0, i - 1);

			return ret;
		}
		string			TrimFront(const string& str)
		{
			string ret = string(str);
			bool isEmpty = true;

			int i = 0;
			for (i = ret.length() - 1; i >= 0 && isEmpty; i--)
			{
				if (ret[i] != ' ')
					isEmpty = false;
			}
			if (i < ret.length()-1)
				ret.erase(i + 2, ret.length() - i - 1);

			return ret;
		}
		string			Trim(const string& str)
		{
			return TrimBack(TrimFront(str));
		}
	};
};
