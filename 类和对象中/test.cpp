#include <iostream>
using namespace std;

//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int i)
//		:_N(10),  // ���������ñ����ڳ�ʼ���б��ʼ��
//		ref(i),
//		_aa(-1)
//	{
//
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	const int _N;
//	int& ref;
//	A _aa;
//};
//
//int main()
//{
//	int i = 0;
//	Date(2022, 2, 28, i);
//
//
//	return 0;
//}
//class A
//{
//public:
//	A(int a = 0)
//	{
//		cout << "A(int a = 0)" << endl;
//		_a = a;
//	}
//
//	A(const A& aa)
//	{
//		cout << "A(const A& aa)" << endl;
//		_a = aa._a;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		_a = aa._a;
//
//		return *this;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	//Date(int year, int month, int day, const A& aa)
//	//{
//	//	_aa = aa;
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	Date(int year, int month, int day, const A& aa)
//		:_aa(aa),
//		_year(year),
//		_month(month),
//		_day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//};
//
//int main()
//{
//	A aa(10);
//	Date d1(2022, 3, 1, aa);
//
//	return 0;
//}
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
////��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	aa.Print();
//}
//class Date
//{
//public:
//	Date(int year = 0)
//		:_year(year)
//	{}
//	//explicit Date(int year)
//	//	:_year(year)
//	//{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1(2018);
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
//	d1 = 2019;
//}
//
//int main()
//{
//	TestDate();
//
//	return 0;
//}
//
//class A
//{
//public:
//	A()
//	{
//		sCount++;
//	}
//
//	A(A& aa)
//	{
//		sCount++;
//	}
//	static int GetCount()
//	{
//		return sCount;
//	}
//
//private:
//	int _a;
//public:
//	static int sCount;
//
//};
//
//int A::sCount = 0;
//
//void f(A a)
//{
//
//}
//
//int main()
//{
//	A a1;
//	A a2 = a1;
//	f(a1);
//
//	cout << A::sCount << endl;
//	cout << a1.sCount << endl;
//	cout << a1.GetCount() << endl;
//	cout << a2.GetCount() << endl;
//	cout << A::GetCount() << endl;
//
//
//	return 0;
//}
//
//class Sum
//{
//public:
//	Sum()
//	{
//		_ret += _i;
//		++_i;
//	}
//
//	static int GetRet()
//	{
//		return _ret;
//	}
//
//	static void Init()
//	{
//		_i = 1;
//		_ret = 0;
//	}
//
//private:
//	static int _i;
//	static int _ret;
//};
//
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n)
//	{
//		Sum::Init();
//		Sum* p = new Sum[n];
//		delete[] p;
//		return Sum::GetRet();
//	}
//};
//
//int main()
//{
//	Solution st;
//	cout << st.Sum_Solution(10) << endl;
//
//
//	return 0;
//}

