#include "..\include\String.h"


namespace Utilities
{
	namespace String
	{
		vector<string>	Split(const string& s, char delim)
		{
			vector<string> elems;

			const char* cstr = Trim(s).c_str();
			unsigned int strLength = (unsigned int)s.length();
			unsigned int start = 0;
			unsigned int end = 0;

			while (end <= strLength)
			{
				while (end <= strLength)
				{
					if (cstr[end] == delim)
						break;
					end++;
				}

				elems.push_back(string(s.substr(start, end - start)));
				start = end + 1;
				end = start;
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
					// Verifica se existe mais de um delimitador em sequencia
					// se sim, vai incrementando o offset ate terminar os delimitadores
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

			//if(elems.empty())
			//	elems.push_back(string(s));

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

			size_t i = 0;
			for (i = ret.length() - 1; i >= 0 && isEmpty; i--)
			{
				if (ret[i] != ' ')
					isEmpty = false;
			}
			if (i - 1 > 0)
				ret.erase(ret.length() - i + 1, i - 1);

			return ret;
		}
		string			Trim(const string& str)
		{
			return TrimBack(TrimFront(str));
		}
	};
};