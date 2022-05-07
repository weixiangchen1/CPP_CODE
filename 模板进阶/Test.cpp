#include <iostream>
using namespace std;
#include "a.h"

namespace cwx
{
	// 定义一个静态的栈
	template<class T, size_t N = 10>
	class stack
	{
	public:
		T& operator[](size_t index)
		{
			return _a[index];
		}

		const T& operator[](size_t index) const
		{
			return _a[index];
		}

		size_t size() const
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

	private:
		int _a[N];
		size_t _size;
	};
}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T1 _d2;
};

// 全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
};

// 偏特化
template<class T1>
class Data<T1, double>
{
public:
	Data() { cout << "Data<T1, double>" << endl; }
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};

template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
};

int main()
{
	//Data<int, int> d1;
	//Data<int, char> d2;
	//Data<char, double> d3;
	//Data<int*, int*> d4;
	//Data<int&, int&> d5;
	Add(1, 5);
	Add(1.1, 5.5);
	A<int> aa(10);

	return 0;
}