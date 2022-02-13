#include <iostream>
using namespace std;

// 全缺省函数
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "Func()" << endl;
//}
//
// 半缺省函数
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

// 函数重载
// 函数参数的类型、顺序和个数不同
// 返回值不同不构成函数重载
//1、类型不同
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
////2、顺序不同
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
////3、个数不同
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
//// 1、缺省值不同，不能构成重载
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
//// 2、构成重载，但是使用时会有问题 ： f(); // 调用存在歧义
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
//	// f(); // 调用存在歧义
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
//	int& ra = a; // 权限放大，报错
//	const int& ra = a;// 权限不变
//	int b = 10; 
//	const int& b = 10; // 权限缩小
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

