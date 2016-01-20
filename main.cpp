#include <iostream>
#include <memory>
#include "sylptr.h"
#include "sylstring.h"

int main()
{
	char *s1 = "s1";
	syl::string s2(s1);
	syl::shared_ptr<syl::string> p1(new syl::string("hello world!"));
	std::cout<<p1->c_str()<<std::endl;
	std::cout<<*p1<<std::endl;
	std::cout<<s2<<std::endl;

	syl::shared_ptr<syl::string> p2 = p1;
	//syl::shared_ptr<syl::string> p3 = syl::shared_ptr<syl::string>(&s2);
	std::cout<<*p2<<std::endl;
	//std::cout<<*p3<<std::endl;
	std::shared_ptr<syl::string> p3 = std::shared_ptr<syl::string>(&s2);
	std::cout<<p3<<std::endl;

	std::cin.get();
    return 0;
}
