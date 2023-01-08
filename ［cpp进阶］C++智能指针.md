@[TOC]

#  为什么需要智能指针?

**下面我们分析一段关于异常安全的代码：**

```cpp
#include <iostream>
using namespace std;

double division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "division by zero condition!";
	}
	return (double)a / (double)b;
}

void func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];
	int len, time;
	cin >> len >> time;

	try
	{
		cout << division(len, time) << endl;
	}
	catch (...)  // 拦截异常，不是要处理异常，而是要正常释放资源
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;  // 捕获到什么对象就重新抛出什么对象
	}

	cout << "delete []" << array << endl;
	delete[] array;
}

int main()
{
	try
	{
		func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
		// 记录日志
	}

	return 0;
}
```
**由于division函数可能会抛异常，所以如果直接在main函数捕捉异常，就会导致申请出来的array资源没有得到释放，就会导致内存泄漏问题。**

**怎么解决这个问题呢？**

 1. 在Func函数中拦截异常，将array资源释放掉，再将异常重新抛出。
 2. 申请资源后将指针交给智能指针管理。


---


# 智能指针的原理及使用

上述的异常问题，可以通过智能指针来解决。

## 智能指针的原理
智能指针运用了RAII的思想。RAII（Resource Acquisition Is Initialization）是一种**利用对象生命周期来控制程序资源**（如内存、文件句柄、网络连接、互斥量等等）的简单技术。

**在对象构造时获取资源，接着控制对资源的访问使之在对象的生命周期内始终保持有效，最后在对象析构的时候释放资源**。借此，我们实际上把管理一份资源的责任托管给了一个对象。这种做法有两大好处：
- 不需要显式地释放资源。
- 采用这种方式，对象所需的资源在其生命期内始终保持有效。



---

## 智能指针的使用

**设计一个智能指针SmartPtr：**

- 在构造SmartPtr时，将用户传入的资源管理起来
- 在析构SmartPtr时，将管理的资源释放
- 智能指针SmartPtr能像指针一样进行解引用操作

```cpp
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

```
**实验代码：**

```cpp
double division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "division by zero condition!";
	}
	return (double)a / (double)b;
}

void func()
{
	int* ptr = new int;
	SmartPtr<int> sp(ptr); // 使用智能指针管理ptr资源
	int len, time;
	cin >> len >> time;
	
	cout << division(len, time) << endl;
}

int main()
{
	try
	{
		func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}

	return 0;
}
```

**实验结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/c26e81565e864ded960b3aa27b8a6e09.png)

在func函数中，申请了ptr资源并交于SmartPtr进行管理，当出现除0错误，异常由division函数抛出，main函数捕捉时，**func函数的函数栈帧销毁，SmartPtr对象也被回收，SmartPtr对象销毁之前会调用析构函数释放管理的资源，这样就避免了内存泄漏的问题**。

但是这样的SmartPtr智能指针还有问题：

```cpp
int main()
{
	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2(sp1);
	return 0;
}
```
**运行结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/7f0e5998a6154ce39d8f28f36479e310.png)

SmartPtr智能指针不能进行拷贝构造，因为这样会释放两次资源，导致程序崩溃。

---

# C++中的智能指针

## C++智能指针的发展历程
- **C++98标准中产生了第一个智能指针```auto_ptr```**
- **C++ boost库中给出了更实用的scoped_ptr、shared_ptr和weak_ptr**
- **C++11标准中引入了unique_ptr、shared_ptr和weak_ptr，这些智能指针的实现原理都是参考boost库的，unique_ptr参考的是scoped_ptr**


---

## std::auto_ptr

### std::auto_ptr的使用
[C++ auto_ptr智能指针文档](https://cplusplus.com/reference/memory/auto_ptr/)

**```std::auto_ptr```的实现原理是管理权的转移。**

**实验代码：**

```cpp
#include <iostream>
#include <memory>

int main()
{
	std::auto_ptr<int> ap1(new int(10));
	std::auto_ptr<int> ap2(ap1);

	return 0;
}
```
**实验结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/38028beee1b5469998d358d6505c2819.png)
```std::auto_ptr```解决智能指针拷贝构造的问题是用管理权转移解决的，但是随之而来会带来另一个问题，管理权转移让```ap1```指针悬空了，如果用户对```std::auto_ptr```不熟悉，继续使用```ap1```进行一系列操作，而```ap1```已经悬空，这势必会导致程序的崩溃。

**实验代码：**

```cpp
#include <iostream>
#include <memory>

int main()
{
	std::auto_ptr<int> ap1(new int(10));
	std::auto_ptr<int> ap2(ap1);
	*ap1 = 20;

	return 0;
}
```
**实验结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/3031d927fddb49eca6b7516af564d4dd.png)

---

### std::auto_ptr的模拟实现
下面简化模拟实现了一份```auto_ptr```来了解它的原理：

```cpp
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

	private:
		T* _ptr;
	};
}
```

---

## std::unique_ptr
## std::unique_ptr的使用
```std::auto_ptr```管理权转移的方式，经过时间的证明，它是一个失败的设计。C++11中引入更加实用的```std::unique_ptr```和```std::shared_ptr```。

**```std::unique_ptr```是参考了boost库中的```scoped_ptr```，它的原理非常简单粗暴，它解决智能指针拷贝构造的方式是直接防拷贝。**

**实验代码：**

```cpp
#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2(up1);       // error

	return 0;
}
```


**实验结果：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/fcf7d2f5b879429db5bfa546bdcc70f1.png)




---
## std::unique_ptr的模拟实现
下面简化模拟实现了一份```unique_ptr```来了解它的原理：

```cpp
namespace cwx
{
	template<class T>
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
				delete _ptr;
			}
		}

	private:
		T* _ptr;
	};
}
```

---

## std::shared_ptr
### std::shared_ptr的使用

```std::unique_ptr```实现了简单粗暴的防拷贝，但是难以避免要需要用到拷贝。C++11引入了```std::unique_ptr```，```std::unique_ptr```使用了引用计数的技术来实现智能指针的拷贝问题。

**```std::unique_ptr```的原理：是通过引用计数的方式来实现多个```std::unique_ptr```对象之间共享资源。**

- **```std::unique_ptr```在其内部，给每个资源都维护了着一份计数，用来记录该份资源被几个对象共享。**
- **在对象被销毁时(也就是析构函数调用)，就说明当前对象不使用该资源了，对象的引用计数减一。**
-  **如果引用计数是0，就说明自己是最后一个使用该资源的对象，必须释放该资源。**
-  **如果引用计数不是0，就说明除了自己还有其他对象在使用该份资源，不能释放该资源，否则其他对象就成野指针了。**


**实验代码：**

```cpp
#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<int> sp1(new int(10));
	std::shared_ptr<int> sp2(sp1);

	std::shared_ptr<int> sp3(new int(20));
	sp3 = sp2;

	return 0;
}
```

**实验结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/31b075c1a08049f28b48d602b1516787.png)

**原理：**
- ```std::shared_ptr<int> sp1(new int(10));```定义了智能指针sp1，管理new出来的int空间，sp1对象中的引用计数加一，refs = 1
- ```std::shared_ptr<int> sp2(sp1);```定义了智能指针sp2，拷贝sp1，sp1和sp2对象中的引用计数加一，refs = 2
- ```std::shared_ptr<int> sp3(new int(20));```定义了智能指针sp3，管理new出来的int空间，sp3对象中的引用计数加一，refs = 1
- ```sp3 = sp2;```，sp3对象赋值拷贝sp2，原来sp3指向的空间的引用计数减一，refs = 0，则释放值为20的空间，sp3现在指向值为10的空间，sp1、sp2和sp3的引用计数加一，refs = 3
![在这里插入图片描述](https://img-blog.csdnimg.cn/b89c7a3ec71d4403bc6ccc7c2a565b91.png)


---
### std::shared_ptr的模拟实现

```cpp
namespace cwx
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pRefCount(sp._pRefCount)
		{
			++(*_pRefCount);
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				if (--(*_pRefCount) == 0 && _ptr)
				{
					delete _ptr;
					delete _pRefCount;
				}
				
				_ptr = sp._ptr;
				_pRefCount = sp._pRefCount;
				++(*_pRefCount);
			}

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

		~shared_ptr()
		{
			if (--(*_pRefCount) == 0 && _ptr)
			{
				delete _ptr;
				delete _pRefCount;
			}
		}

	private:
		T* _ptr;
		int* _pRefCount;
	};
}
```


---

### std::shared_ptr的线程安全问题
模拟实现的```shared_ptr```还存在线程安全的问题，由于管理同一个资源的多个对象的引用计数是共享的。

在多线程环境下可能会同时对同一个引用计数进行自增或自减操作，而自增和自减操作都不是原子操作，因此需要通过加锁来对引用计数进行保护，否
则就会导致线程安全问题。

**加锁后代码：**

- 将进行引用计数自增自减的代码封装成函数，便于加锁
- 引入mutex，对自增自减操作进行加锁

```cpp
namespace cwx
{
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
}
```


---

## std::weak_ptr
### std::shared_ptr的循环引用
**实验代码：**
```cpp
struct ListNode
{
	int _val;
	cwx::shared_ptr<ListNode> _prev;
	cwx::shared_ptr<ListNode> _next;
	~ListNode() { cout << "~ListNode()" << endl; }
};

int main()
{
	cwx::shared_ptr<ListNode> node1(new ListNode);
	cwx::shared_ptr<ListNode> node2(new ListNode);

	node1->_next = node2;
	node2->_prev = node1;

	return 0;
}
```

**实验结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/ec0aecc7e23444adb5ab839639b2dba9.png)

**实验原理**

程序创建了node1和node2两个链表结点，用shared_ptr智能指针管理，node1和node2的引用计数当前分别为1，node1的_next指向node2，node2的_prev指向node1，此时node1和node2的引用计数分别为2。

![在这里插入图片描述](https://img-blog.csdnimg.cn/745f7987ab9244609a58c19f43d17dd5.png)

程序运行结束后，node1和node2调用析构函数，引用计数减一，此时引用计数为1，然而程序已经结束，node1和node2开辟的空间并没有被释放，这种现象叫做循环引用。

---
### std::weak_ptr的使用
在上述的实验场景中，循环引用导致资源没有被释放的问题，需要使用```std::weak_ptr```来解决。

**```std::weak_ptr```的原理是可以获取并访问指向的资源，但是不参与引用计数。**

**实验代码：**

```cpp
struct ListNode
{
	int _val;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;

	~ListNode() { cout << "~ListNode()" << endl; }
};

int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);

	node1->_next = node2;
	node2->_prev = node1;

	return 0;
}
```


**实验结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/549cf2271a9149c186dd53e22864d7e5.png)

---

### std::weak_ptr的模拟实现
下面简化模拟实现了一份```weak_ptr```来了解它的原理：

```cpp
namespace cwx
{
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
		T* ptr;
	};
}
```

---

## 智能指针的定制删除器
模拟实现的智能指针默认都用delete释放资源，但是如果是申请一个数组资源，fopen打开一个文件，delete就会不匹配或者程序直接就崩溃了。

C++文档中，智能指针的接口定义了一个模板D，就是定制删除器。定制删除器本质是一个可调用对象，比如函数指针、仿函数或者lambda表达式。

![在这里插入图片描述](https://img-blog.csdnimg.cn/3f718a199e3d4f178a6a265266731a67.png)

下面给```unique_ptr```实现一个简化的定制删除器：

```cpp
namespace cwx
{
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
}

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

int main()
{
	unique_ptr<int, DelArray<int>> up1(new int[10]);
	unique_ptr<FILE, DelFile<FILE>> up2(fopen("test.txt", "w"));

	return 0;
}
```

---
