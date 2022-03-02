#include <iostream>
#include <cmath>
using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int* arr = new int[n + 1];
//	arr[0] = arr[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	for (int i = 0; i <= n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//	delete[]arr;
//
//	return 0;
//}
//
//double sroot(int x)
//{
//	return sqrt(x);
//}
//
//double sroot(long long x)
//{
//	return sqrt(x);
//}
//
//double sroot(double x)
//{
//	return sqrt(x);
//}
//
//int main()
//{
//	int x = 0;
//	long long y = 0;
//	double z = 0.0;
//	cin >> x >> y >> z;
//	cout << sroot(x) << endl;
//	cout << sroot(y) << endl;
//	cout << sroot(z) << endl;
//
//	return 0;
//}

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//
//// C++11 -- 打补丁
//class A
//{
//public:
//	// 如果你再初始化列表阶段，没有对成员变量初始化，它就会使用缺省值初始化
//	A()
//	{}
//private:           // 要注意的是这里不是初始化，因为这里是声明，不能初始化
//	int _a1 = 0;  // 这个里是给成员变量缺省值
//	B _bb1 = 10;
//	B _bb2 = B(20);
//	int* p = (int*)malloc(4*10);
//	// vs2019支持
//	//int arr[10] = { 1, 2, 3, 4, 5 };
//
//	// 静态的不能这样给缺省值，必须在类外面全局位置定义初始化
//	// static int _sCount = 0;
//};
//
//
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//
//// C++11 -- 打补丁
//class A
//{
//public:
//	// 如果你再初始化列表阶段，没有对成员变量初始化，它就会使用缺省值初始化
//	A()
//	{}
//private:           // 要注意的是这里不是初始化，因为这里是声明，不能初始化
//	int _a1 = 0;  // 这个里是给成员变量缺省值
//	B _bb1 = 10;
//	B _bb2 = B(20);
//	int* p = (int*)malloc(4*10);
//	// vs2019支持
//	//int arr[10] = { 1, 2, 3, 4, 5 };
//
//	// 静态的不能这样给缺省值，必须在类外面全局位置定义初始化
//	// static int _sCount = 0;
//};
//
//int main()
//{
//	A aa;
//
//	return 0;
//}
//
//class Time
//{
//	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//	//friend class Time;
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour = 0;
//		_t._minute = 0;
//		_t._second = 0;
//	}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//class Time
//{
//	friend class Date;
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour),
//		_minute(minute),
//		_second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 0)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	return 0;
//}

class A
{
	friend class B;
private:
	static int k;
	int h;
public:
	class B
	{
		friend class A;
	public:
		void f(const A& a)
		{
			cout << a.h << endl;
			cout << a.k << endl;
		}
	private:
		int b;
	};

	void ff(B _b)
	{
		cout << _b.b << endl;
	}

};

int main()
{
	return 0;
}