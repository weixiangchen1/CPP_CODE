@[TOC]

# 	C语言的类型转换
在C语言中，**如果赋值运算符左右两侧类型不同，或者形参与实参类型不匹配，或者返回值类型与接收返回值类型不一致**时，就需要发生类型转化，C语言中总共有两种形式的类型转换：**隐式类型转换和显式类型转换。**

>  **隐式类型转化**：编译器在编译阶段自动进行，能转就转，不能转就编译失败
> **显式类型转化**：需要用户自己处理

```cpp
int main()
{
	// 隐式类型转换
	int i = 1;
	double d = i;
	printf("%d %.2f\n", i, d);

	// 强制类型转换
	int* p = &i;
	int address = (int)p;
	printf("%p %d\n", p, address);

	return 0;
}
```
---

# 为什么C++需要四种类型转换
C风格的转换格式很简单，但是有不少缺点的：
1. 隐式类型转化有些情况下可能会出问题：比如数据精度丢失
2. 显式类型转换将所有情况混合在一起，代码不够清晰

因此C++提出了自己的类型转化风格，分别是**static_cast，const_cast，reinterpret_cast和dynamic_cast**，注意因为C++要兼容C语言，所以C++中还可以使用C语言的转化风格。

---

# C++强制类型转换

**标准C++为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符：static_cast、reinterpret_cast、const_cast、dynamic_cast。**

## static_cast
**static_cast用于非多态类型的转换（静态转换），编译器隐式执行的任何类型转换都可用static_cast，但它不能用于两个不相关的类型进行转换**

```cpp
int main()
{
	double d = 12.34;
	int i = static_cast<int>(d);
	cout << i << endl;

	return 0;
}
```
但是static_cast不能用于两个不相关类型之间的转换：

```cpp
int* p = &i;
int address = static_cast<int>(p);
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/76ba408b9bc04233b46f95457234f043.png)

---
## reinterpret_cast

**reinterpret_cast操作符通常为操作数的位模式提供较低层次的重新解释，用于将一种类型转换为另一种不同的类型：**

```cpp
int main()
{
	int i = 10;
	int* p = &i;
	int* address = reinterpret_cast<int*>(p);

	return 0;
}
```
reinterpret_cast有很bug的用法，reinterpret_cast可以让编译器以FUNC的视角看待DoSomething函数并调用：

```cpp
typedef void (*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}

int main()
{
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();

	return 0;
}
```

**运行结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/41e40b384e8c400b86e69c45a218f085.png)



---

## const_cast
**const_cast用于删除变量的const属性，转换后就可以对const变量的值进行修改：**

```cpp
int main()
{
	const int a = 10;
	int* p = const_cast<int*>(&a);

	*p = 20;
	cout << *p << endl;

	return 0;
}
```
**运行结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/d5d7eb3228264b2eaa1a1bbd867e6a9e.png)
但是，我们如果同时打印原变量a，我们发现a的值并没有改变：
![在这里插入图片描述](https://img-blog.csdnimg.cn/302945137d884209b8907d92adc26893.png)

这是因为编译器做了优化，在发现变量a是const属性时，默认变量a不会被改变，就将变量a存放到寄存器中，打印出来的值是直接从寄存器取出来的值，修改的是内存中的值，如果不想让编译器做出优化，可以使用```volatile```关键字对变量进行修饰，在读取变量时就会从内存中读取：

![在这里插入图片描述](https://img-blog.csdnimg.cn/eda4673242a14cef9058e0dc9f9572cc.png)

---

## dynamic_cast
**dynamic_cast用于将一个父类对象的指针/引用转换为子类对象的指针或引用(动态转换)**

> **向上转型**：子类对象指针/引用->父类指针/引用(不需要转换，赋值兼容规则)
> **向下转型**：父类对象指针/引用->子类指针/引用(用dynamic_cast转型是安全的)

当我们在函数中用父类的指针或引用接受参数时，接收的参数有可能指向父类对象也有可能指向子类对象，当接收的参数指向父类对象时，不需要做任何处理，当接收的参数指向子类对象时，有时就需要将该对象转换为原来的子类对象。

dynamic_cast可以做到将父类对象转换为子类对象，如果要转换的类型原本就是父类对象，返回nullptr，否则返回转换成功后的对象指针。

```cpp
class A
{
public:
	virtual void fun() {}
};

class B : public A
{};

void func(A* pa)
{
	B* pb = dynamic_cast<B*>(pa);
	if (pb == nullptr) {
		cout << "转换失败" << endl;
	}
	else {
		cout << "pb: " << pb << endl;
	}
}

int main()
{
	A a;
	B b;
	func(&a);
	func(&b);

	return 0;
}
```

**实验结果：**

![在这里插入图片描述](https://img-blog.csdnimg.cn/d2f92a50c8e94b73af853c5df549402c.png)

---

## explicit
**explicit可以防止经过构造函数进行的隐式类型转换的发生。**

```cpp
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
	A a2 = 1;
}
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/b50de067291d4822bbcd0a31ccff6931.png)
实际上```A a2 = 1;```在底层会将1经由构造函数构造出一个对象，最后再将该对象赋给a2，explicit可以有效防止这种隐式类型转换。

---

# RTTI
RTTI：Run-time Type identification的简称，即：运行时类型识别。
C++通过以下方式来支持RTTI：
1. typeid运算符
2. dynamic_cast运算符

---
