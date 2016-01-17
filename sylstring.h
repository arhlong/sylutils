#ifndef __SYL_STRING__
#define __SYL_STRING__
#include <string.h>
#include <ostream>

namespace syl
{
class String
{
public:
	String();
	String(const char *s);
	String(const String &s);
	String& operator=(const String &s);
	~String();
	char* c_str() const;
	friend std::ostream& operator<<(std::ostream &os,const String &s);

private:
	char *data;
};
}

#endif
