#include "timer.h"
#include <iostream>

TimerManager::~TimerManager()
{
	std::cout<<"desconstruct the class TimerManager."<<std::endl;
}

void TimerManager::setName(String s)
{
	name =s;
}

void TimerManager::showName()
{
    std::cout<<name<<std::endl;
}
