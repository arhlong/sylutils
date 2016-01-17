#ifndef __SYL_SINGLETON__
#define __SYL_SINGLETON__
#include <mutex>
#include <iostream>

namespace syl
{
	template<typename T>
	class Singleton
	{
	protected:
		static std::mutex  *mtx;
		static T* p;
		Singleton()
		{
			std::cout<<"construct the base class singleton."<<std::endl;
		}

	public:
		Singleton<T>& operator=(const Singleton<T> &obj) = delete;
		Singleton(const Singleton<T>& obj) = delete;
		static T* instance()
		{
			if(0 == p)
			{
				mtx->lock();
				if(0 == p)
				{
					p = new T();
				}
				mtx->unlock();
			}

			return p;
		}

		virtual ~Singleton()
		{
			std::cout<<"desconstruct the base class singleton."<<std::endl;
		}
	};

	template<typename T> std::mutex* Singleton<T>::mtx = new std::mutex;
	template<typename T> T* Singleton<T>::p = 0;
}

#endif
