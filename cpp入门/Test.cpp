#include <iostream>
using namespace std;

// ȫȱʡ����
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "Func()" << endl;
//}
//
// ��ȱʡ����
//void Func(int a, int b = 20, int c = 30)
//{
////	cout << "Func(a)" << endl;
//}
//
//void Func(int a, int b, int c = 30)
//{
//	cout << "Func(a, b)" << endl;
//}
//
//int main()
//{
//	Func(1);
//	Func();
//
//	return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//namespace N
//{
//	int rand = 10;
//}
//
//int main()
//{
//	printf("%d\n", N::rand);
//
//	return 0;
//}

// ��������
// �������������͡�˳��͸�����ͬ
// ����ֵ��ͬ�����ɺ�������
//1�����Ͳ�ͬ
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
////2��˳��ͬ
//void Func(int a, char b)
//{
//	cout << "int a, char b" << endl;
//}
//
//void Func(char b, int a)
//{
//	cout << "char b, int a" << endl;
//}
//
////3��������ͬ
//void f(int a)
//{
//	cout << "int a" << endl;
//}
//
//void f(int a, int b)
//{
//	cout << "int a, int b" << endl;
//}
//
//// 1��ȱʡֵ��ͬ�����ܹ�������
//void f(int a)
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0)
//{
//	cout << "f(int a)" << endl;
//}
//
//// 2���������أ�����ʹ��ʱ�������� �� f(); // ���ô�������
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	// f(); // ���ô�������
//	 f(1);
//
//	return 0;
//}
//
//int main()
//{
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//    int a = 10;
//    int& b = a;
//
//    return 0;
//}
//
//int main()
//{
//	int a = 10;
//	int& ra;
//
//
//	return 0;
//}
//
//void TestConstRef()
//{
//	const int a = 10;
//	int& ra = a; // Ȩ�޷Ŵ󣬱���
//	const int& ra = a;// Ȩ�޲���
//	int b = 10; 
//	const int& b = 10; // Ȩ����С
//}
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
////}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int i = 0;
//	for (auto x : arr)
//	{
//		cout << x << " ";
//	}
//
//	return 0;
//}

