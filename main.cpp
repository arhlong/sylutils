#include <iostream>
#include <string>
#include <memory>

int main()
{
	std::shared_ptr<std::string> p1(new std::string("hello world!"));
	std::shared_ptr<std::string> p2 = p1;

	std::unique_ptr<std::string> p3(new std::string("hello girl!"));
	std::auto_ptr<std::string> p4(new std::string("hello arhlong!"));

    return 0;
}
