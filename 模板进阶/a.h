#pragma once
#include <iostream>
using namespace std;
// ģ�岻֧�������Ͷ������
// ��a.cpp�У������������û��ʵ�����ĺ������ɾ���ĺ�������
// ��Test.cpp�У�����Add����ʱ�������ӵ�ʱ���ȥѰ�ҷ��ű�����Ѱ�ҷ��ŵ�ַ
// ������Ϊû�����ɾ�����ţ���������ʱ�ᱨ��
//
// ���������2.�����������һ��
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

