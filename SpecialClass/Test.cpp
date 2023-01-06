#include <iostream>
using namespace std;

class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() {}

	// C++98
	// 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
	// 2.声明成私有
	HeapOnly(const HeapOnly&);

	// or
	// C++11 
	HeapOnly(const HeapOnly&) = delete;
};

class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly() {}
};

class StackOnly
{
public:
	StackOnly() {}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

class CopyBan
{
	// ...

private:
	CopyBan(const CopyBan&);
	CopyBan& operator=(const CopyBan&);
	//...
};

class CopyBan
{
	// ...
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
	//...
};

class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};
class A final
{
	// ....
};

// 饿汉模式
// 优点：简单
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}

private:
	// 构造函数私有
	Singleton() {};

	// C++98 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	// or

	// C++11
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	static Singleton m_instance;
};

Singleton Singleton::m_instance; // 在程序入口之前就完成单例对象的初始化

// 懒汉
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类 
	class CGarbo {
	public:
		~CGarbo() {
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton() {};
	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx; //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;
void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}
// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}