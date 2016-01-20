#ifndef __SYL_PTR__
#define __SYL_PTR__

namespace syl
{
template <class T>
class shared_ptr
{
public:
	explicit shared_ptr(T *p = 0)
		:ptr(p),count(new int(1))
	{
	}

	shared_ptr(const shared_ptr<T> &p)
		:ptr(p.ptr),count(p.count)
	{
		increase();
	}

	~shared_ptr()
	{
		dispose();
	}

	shared_ptr<T>& operator=(const shared_ptr<T> &p)
	{
		if(this != &p)
		{
			dispose();
			ptr = p.ptr;
			count = p.count;
			increase();
		}

		return *this;
	}

	T* operator->() const
	{
		return ptr;
	}

	T& operator*() const
	{
		return *ptr;
	}

private:
	void increase()
	{
		if(count)
		{
			++*count;
		}
	}

	void dispose()
	{
		if(count && --*count == 0)
		{
			delete ptr;
			delete count;
		}
	}

private:
	T *ptr;
	int *count;
};
}

#endif
