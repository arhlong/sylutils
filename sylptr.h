#ifndef __SYL_PTR__
#define __SYL_PTR__

namespace syl
{
template<typename T>
class Shared_ptr
{
public:
	explicit Shared_ptr(T *p = 0)
		:ptr(p),count(new int(1))
	{
	}

	Shared_ptr(const Shared_ptr<T> &p)
		:ptr(p.ptr),count(p.count)
	{
		increase();
	}

	~Shared_ptr()
	{
		dispose();
	}

	Shared_ptr<T>& operator=(const Shared_ptr<T> &p)
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
