#include <iostream>
using namespace std;

//int main()
//{
//	// 隐式类型转换
//	int i = 1;
//	double d = i;
//	printf("%d %.2f\n", i, d);
//
//	// 强制类型转换
//	int* p = &i;
//	int address = (int)p;
//	printf("%p %d\n", p, address);
//
//	return 0;
//}

// static_cast
//int main()
//{
//	double d = 12.34;
//	int i = static_cast<int>(d);
//	cout << i << endl;
//
//	int* p = &i;
//	int address = static_cast<int>(p);  //error
//
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	int* p = &i;
//	int* address = reinterpret_cast<int*>(p);
//
//	return 0;
//}

//typedef void (*FUNC)();
//int DoSomething(int i)
//{
//	cout << "DoSomething" << endl;
//	return 0;
//}
//
//int main()
//{
//	FUNC f = reinterpret_cast<FUNC>(DoSomething);
//	f();
//
//	return 0;
//}


//int main()
//{
//	volatile const int a = 10;
//	int* p = const_cast<int*>(&a);
//
//	*p = 20;
//	cout << a << endl;
//	cout << *p << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void fun() {}
//};
//
//class B : public A
//{};
//
//void func(A* pa)
//{
//	B* pb = dynamic_cast<B*>(pa);
//	if (pb == nullptr) {
//		cout << "转换失败" << endl;
//	}
//	else {
//		cout << "pb: " << pb << endl;
//	}
//}
//
//int main()
//{
//	A a;
//	B b;
//	func(&a);
//	func(&b);
//
//	return 0;
//}

class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};

int main()
{
	A a1(1);
	// 隐式转换-> A tmp(1); A a2(tmp);
	A a2 = 1; //error
}