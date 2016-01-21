#include <iostream>
#include <memory>
#include "sylptr.h"
#include "sylstring.h"
#include "sylsingleton.h"

std::mutex* syl::TimerManager::mtx = new std::mutex;
syl::TimerManager* syl::TimerManager::p = 0;

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

	syl::TimerManager* t = syl::TimerManager::instance();
	t->showName();
	t->setName("test sigleton");
	t->showName();
	std::cout<<"t addr:"<<(int*)t<<std::endl;

	syl::TimerManager* t2 = syl::TimerManager::instance();
	t2->showName();
	std::cout<<"t2 addr:"<<(int*)t2<<std::endl;

	//syl::TimerManager t3 = *t2;
	//t3.showName();

	std::cin.get();
    return 0;
}
