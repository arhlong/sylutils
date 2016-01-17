#include <ostream>
#include "sylstring.h"

namespace syl
{
	String::String()
	{
		data = new char[1];
		data[0] = '\0';
	}

	String::String(const char *s)
	{
		data = new char[strlen(s) + 1];
		strcpy(data,s);
	}

	String::String(const String &s)
	{
		data = new char[strlen(s.data) + 1];
		strcpy(data,s.data);
	}

	String& String::operator=(const String &s)
	{
		if(this != &s)
		{
			delete [] data;
			data = new char[strlen(s.data) + 1];
			strcpy(data,s.data);
		}

		return *this;
	}

	String::~String()
	{
	   	delete [] data;
	}

	char* String::c_str() const
	{
		return data;
	}

	std::ostream& operator<<(std::ostream &os,const String &s)
	{
		return os<<s.data;
	}
}
