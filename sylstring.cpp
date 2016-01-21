#include <ostream>
#include "sylstring.h"

namespace syl
{
	string::string()
	{
		data = new char[1];
		data[0] = '\0';
	}

	string::string(const char *s)
	{
		data = new char[strlen(s) + 1];
		strcpy(data,s);
	}

	string::string(const string &s)
	{
		data = new char[strlen(s.data) + 1];
		strcpy(data,s.data);
	}

	string& string::operator=(const string &s)
	{
		if(this != &s)
		{
			delete [] data;
			data = new char[strlen(s.data) + 1];
			strcpy(data,s.data);
		}

		return *this;
	}

	string::~string()
	{
	   	delete [] data;
	}

	char* string::c_str() const
	{
		return data;
	}

	std::ostream& operator<<(std::ostream &os,const string &s)
	{
		return os<<s.data;
	}
}
