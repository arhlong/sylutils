#include <iostream>
#include <memory>
#include <mutex>
#include "sylptr.h"
#include "sylstring.h"
#include "timer.h"

using syl::String;
using syl::Shared_ptr;

class Base
{
private:
    String name;
public:
	Base()
	{
		std::cout<<"contruct class Base."<<std::endl;
	}

	virtual ~Base()
	{
		std::cout<<"descontruct class base."<<std::endl;
	}
};

class Derive : public Base
{
private:
	String name2;
public:
	Derive()
	{
		std::cout<<"contruct class derive."<<std::endl;
	}
	~Derive()
	{
		std::cout<<"descontruct class derive."<<std::endl;
	}

};

class Sing
{
private:
	String name;
	static Sing *p;
	static std::mutex *mtx;
	Sing()
	{
		std::cout<<"construct class Sing."<<std::endl;
	}

public:
	Sing(const Sing& s) = delete;
	Sing& operator=(const Sing& s) = delete;
	~Sing()
	{
		std::cout<<"descontruct class Sing."<<std::endl;
	}
	static Sing* instance()
	{
		if(0 == p)
		{
			mtx->lock();
			if(0 == p)
			{
				p = new Sing();
			}
			mtx->unlock();
		}

		return p;
	}
	void setName(String s)
	{
		name = s;
	}
};

Sing* Sing::p = 0;
std::mutex* Sing::mtx = new std::mutex;

int main()
{

	{
		char *s1 = "s1";
		String s2 = "s2";
		String s3;
		s3 = "s3";
		s3 = s1;
		String s4(s1);
		Shared_ptr<String> p1(new String("hello world!"));
		std::cout<<p1->c_str()<<std::endl;
		std::cout<<*p1<<std::endl;
		std::cout<<s2<<std::endl;

		Shared_ptr<String> p2 = p1;
		//syl::shared_ptr<syl::string> p3 = syl::shared_ptr<syl::string>(&s2);
		std::cout<<*p2<<std::endl;
		//std::cout<<*p3<<std::endl;

		TimerManager* t = TimerManager::instance();
		t->showName();
		t->setName("test sigleton");
		t->showName();
		std::cout<<"t addr:"<<(int*)t<<std::endl;

		TimerManager* t2 = TimerManager::instance();
		t2->showName();
		std::cout<<"t2 addr:"<<(int*)t2<<std::endl;
		//delete t2;

		//TimerManager t3;
		//TimerManager t3 = *t2;
		//t3 = *t2;
		//t2->showName("test 2");
		//t2->showName();
		//std::cout<<"t3 addr:"<<(int*)&t3<<std::endl;

		//delete syl::TimerManager::mtx;
		//syl::TimerManager t3 = *t2;
		//t3.showName();
		//delete t;

		Sing* sing1 = Sing::instance();
		sing1->setName("test sing");

		Derive d;
	}

	std::cin.get();
    return 0;
}
