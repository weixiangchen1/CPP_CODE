#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
#include <memory>
using namespace std;

//double division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
//	int* array = new int[10];
//	int len, time;
//	cin >> len >> time;
//
//	try
//	{
//		cout << division(len, time) << endl;
//	}
//	catch (...)  // 拦截异常，不是要处理异常，而是要正常释放资源
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;  // 捕获到什么对象就重新抛出什么对象
//	}
//
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//		// 记录日志
//	}
//
//	return 0;
//}

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~SmartPtr()
	{
		cout << "delete: " << _ptr << endl;
		delete _ptr;
	}

private:
	T* _ptr;
};


//double division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void func()
//{
//	int*ptr = new int;
//	SmartPtr<int> sp(ptr);
//	int len, time;
//	cin >> len >> time;
//	
//	cout << division(len, time) << endl;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(sp1); // error
//	return 0;
//}
//
//
//int main()
//{
//	std::auto_ptr<int> ap1(new int(10));
//	std::auto_ptr<int> ap2(ap1);
//	*ap1 = 20;   //error
// 
// 	std::unique_ptr<int> up1(new int);
//  std::unique_ptr<int> up2(up1); // error
//
// 	std::shared_ptr<int> sp1(new int(10));
//  std::shared_ptr<int> sp2(sp1);
//
//  std::shared_ptr<int> sp3(new int(20));
//  sp3 = sp2;
// 
//	return 0;
//}
//

namespace cwx
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			// 管理权的转移
			ap._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}

	private:
		T* _ptr;
	};

	template<class T>
	struct default_delete
	{
		void operator()(const T* ptr)
		{
			delete ptr;
		}
	};

	template<class T, class D = default_delete<T>>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		// 防拷贝
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~unique_ptr()
		{
			if (_ptr)
			{
				D del;
				del(_ptr);
			}
		}

	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
			, _pmtx(new mutex)
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pRefCount(sp._pRefCount)
			, _pmtx(sp._pmtx)
		{
			AddRef();
		}

		void AddRef()
		{
			_pmtx->lock();

			++(*_pRefCount);

			_pmtx->unlock();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();

				_ptr = sp._ptr;
				_pRefCount = sp._pRefCount;
				AddRef();
			}

			return *this;
		}

		void Release()
		{
			_pmtx->lock();

			bool flag = false;
			if (--(*_pRefCount) == 0 && _ptr)
			{
				delete _ptr;
				delete _pRefCount;
				flag = true;
			}

			_pmtx->unlock();
			if (flag)
			{
				delete _pmtx;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get() const
		{
			return _ptr;
		}

		~shared_ptr()
		{
			Release();
		}

	private:
		T* _ptr;
		int* _pRefCount;
		mutex* _pmtx;
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}

//
//int main()
//{
//	cwx::shared_ptr<int> sp1(new int(10));
//	cwx::shared_ptr<int> sp2(sp1);
//
//	cwx::shared_ptr<int> sp3(new int(20));
//	sp3 = sp2;
//
//	return 0;
//}

//
//struct ListNode
//{
//	int _val;
//	weak_ptr<ListNode> _prev;
//	weak_ptr<ListNode> _next;
//
//	~ListNode() { cout << "~ListNode()" << endl; }
//};
//
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	return 0;
//}

template<class T>
struct DelArray
{
	void operator()(const T* ptr)
	{
		delete[] ptr;
	}
};

template<class T>
struct DelFile
{
	void operator()(FILE* file_name)
	{
		cout << "fclose: " << file_name << endl;
		fclose(file_name);
	}
};

class A
{
public:
	A() {}
	~A() { cout << "~A()" << endl; }
private:
	int _a = 10;
};

int main()
{
	unique_ptr<int, DelArray<int>> up1(new int[10]);
	unique_ptr<FILE, DelFile<FILE>> up2(fopen("test.txt", "w"));

	return 0;
}