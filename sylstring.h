#ifndef __SYL_STRING__
#define __SYL_STRING__
#include <string.h>

namespace syl
{
class string
{
public:
	string(const char *s = 0);
	string(const string &s);
	string& operator=(const string &s);
	~string();
	char* c_str() const;
	friend std::ostream& operator<<(std::ostream &os,const string &s);

private:
	char *data;
};
}

#endif
