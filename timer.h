#ifndef __TIMER_H__
#define __TIMER_H__
#include "sylstring.h"
#include "sylsingleton.h"

using syl::Singleton;
using syl::String;

class TimerManager : public Singleton<TimerManager>
{
private:
    String name;

public:
	~TimerManager();
	void setName(const String s);
	void showName();
};
#endif
