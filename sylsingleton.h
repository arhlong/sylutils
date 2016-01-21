#ifndef __SYL_SINGLETON__
#define __SYL_SINGLETON__
#include <mutex>

namespace syl
{
	class TimerManager
	{
	private:
		std::string name;

		static std::mutex  *mtx;
		static TimerManager* p;
		TimerManager();

	public:
		TimerManager& operator=(const TimerManager &t) = delete;
		TimerManager(const TimerManager& t) = delete;
		static TimerManager* instance();
		~TimerManager();
		void setName(const std::string &s);
		void showName();
	};
}

#endif
