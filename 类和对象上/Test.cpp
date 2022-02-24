#include <iostream>
using namespace std;
//
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 2, 6);
//	d1.Print();
//
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d(2022, 2, 24);
//	d.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Show();
//}
//
//class a
//{
//public:
//	void printa()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	a* p = nullptr;
//	p->printa();
//}
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//class Date
//{
//public:
//	Date(int year = 1, int month = 0, int day = 0)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{
//		cout << "Date()" << endl;
//	}
//	Date(const Date& d)
//		:_year(d._year),
//		_month(d._month),
//		_day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//};
//
//void f(Date& d)
//{}
//
//int main()
//{
//	Date d1(2022, 2, 24);
//	f(d1);
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}
	//Date& operator++()
	//{
	//	*this = *this + 1;
	//	return *this;
	//}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2022, 2, 24);
	Date d2(2022, 2, 25);
	if (d1.operator>(d2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}
