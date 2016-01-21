#include <string>
#include <iostream>
#include "sylsingleton.h"

namespace syl
{
	TimerManager::TimerManager()
	{
	}

	TimerManager::~TimerManager()
	{
		delete mtx;
		delete p;
	}

	TimerManager* TimerManager::instance()
	{
		if(0 == p)
		{
			mtx->lock();
			if(0 == p)
			{
				p = new TimerManager();
			}
			mtx->unlock();
		}

		return p;
	}

	void TimerManager::setName(const syl::string &s)
	{
		name = s;
	}

	void TimerManager::showName()
	{
		std::cout<<name<<std::endl;
	}
}
