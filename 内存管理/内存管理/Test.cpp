#include <iostream>
using namespace std;
//const int SIZE = 4;
//int main()
//{
//	int* p1 = new int;
//	int* p2 = new int(5);
//	int* p3 = new int[5];
//	int* p4 = new int[5]{ 1,2,3,4,5 };
//
//	delete p1;
//	delete p2;
//	delete[] p3;
//	delete[] p4;
//
//	return 0;
//}
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A()" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = new A; // 开空间 + 构造函数初始化
//	A* p2 = new A[5]; // 析构函数 + 释放空间
//	delete p1;
//	delete[]p2;
//	return 0;
//}
//
//void BuyMemory()
//{
//	char* p1 = new char[1024u * 1024u * 1024u * 2u - 1];
//	printf("%p\n", p1);
//}
//
//int main()
//{
//	try
//	{
//		BuyMemory();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//
//	return 0;
//}
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0),
//		_capacity(capacity)
//	{
//		_a = new int[capacity];
//		cout << "Stack()" << endl;
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack* p1 = new Stack[10];
//	Stack* p2 = (Stack*)operator new[](sizeof(Stack) * 10);
//
//
//	return 0;
//}
//
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}-
//private:
//	ListNode* _head;
//};
//int main()
//{
//	List l;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//void f()
//{
//	int c, f, h, j, i;
//	void* p = new char[0x7fffffff - 1];
//	cout << "new:" << p << endl;
//}
//
//int main()
//{
//	try
//	{
//		f();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//
//	return 0;
//}

