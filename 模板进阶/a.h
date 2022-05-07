#pragma once
#include <iostream>
using namespace std;
// 模板不支持声明和定义分离
// 在a.cpp中，编译器不会对没有实例化的函数生成具体的函数符号
// 在Test.cpp中，调用Add函数时，在链接的时候会去寻找符号表里面寻找符号地址
// 但是因为没有生成具体符号，所以连接时会报错
//
// 解决方案：2.声明定义放在一起
template<class T>
T Add(const T& left, const T& right);

template<class T>
T Add(const T& left, const T& right)
{
	cout << left + right << endl;
	return left + right;
}

template<class T>
class A
{
public:
	A(const T& a);
	void f();
private:
	T _a;
};

template<class T>
A<T>::A(const T& a)
	:_a(a)
{}

template<class T>
void A<T>::f()
{
	cout << "A<T>" << endl;
}

