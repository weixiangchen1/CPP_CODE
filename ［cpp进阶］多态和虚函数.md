@[TOC]
![在这里插入图片描述](https://img-blog.csdnimg.cn/dd884ef4e3f849a4a814a0b008d4f0ae.png)
# 多态的概念

> 多态的概念：通俗来说，就是多种形态，**具体点就是去完成某个行为，当不同的对象去完成时会产生出不同的状态**。
> <br>
> 多态分为两种多态：
> 1.**静态的多态**：函数重载，调用同一个有不同行为。原理是在**编译时**实现。
> 2.**动态的多态**：一个父类的指针或引用去调用同一个函数，传递不同的对象，会调用不同的函数。原理是在**运行时**实现。
> <br>
> 多态按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
C++ 多态意味着调用成员函数时，会根据**调用函数的对象的类型**来执行不同的函数。
比如说：
买票这个行为，当普通人买票时，是**全价买票**；学生买票时，是**半价买票**；军人买票时是**优先买票**。
**买票这一个行为，不同的人做就有不同的行为和结果，这就是多态。**

# 多态的定义及实现
## 多态的构成条件

> 多态是在不同继承关系的类对象，去调用同一函数，产生了不同的行为。比如Student继承了Person。Person对象买票全价，Student对象买票半价。
> 
> 那么在继承中要**构成多态还有两个条件**：
> 1. **必须通过基类的指针或者引用调用虚函数。**
> 2. **被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写。**


```cpp
class Person
{
public:
	virtual void BuyTicket()
	{ 
		cout << "买票-全票" << endl; 
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket() { 
		cout << "买票-半票" << endl; 
	}
};

void Func(Person& p)
{
	p.BuyTicket();
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/657da6b81af2446a812993af563d6818.png)
## 虚函数

> **虚函数：即被virtual修饰的非静态成员函数称为虚函数。**
> **ps:其他函数不能成为虚函数。**
> ```cpp
> class Person {
> public:
> 	virtual void BuyTicket() { cout << "买票-全价" << endl;}
> };
> ```
## 虚函数的重写
> **虚函数的重写(覆盖)**：**派生类中有一个跟基类完全相同的虚函数(即派生类虚函数与基类虚函数的返回值类型、函数名字、参数列表完全相同)**，称子类的虚函数重写了基类的**虚函数**。
> ```cpp
> class Person
> {
> public:
> 	virtual void BuyTicket() { cout << "买票-全票" << endl; }
> };
> class Student : public Person
> {
> public:
> 	virtual void BuyTicket() { cout << "买票-半票" << endl; }
> };
> ```
> 

注意：
**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;构成多态，传何种类型的对象，就调用的是这个函数的虚函数 -- 跟对象有关。
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;不构成多态，调用的是变量类型的函数 -- 跟类型有关。**

**构成多态**：![在这里插入图片描述](https://img-blog.csdnimg.cn/b113464dbad84e9c970c93f24b91d70a.png)
 **不构成多态**：
（返回值类型、函数名字、参数列表不同或者不是虚函数）
![在这里插入图片描述](https://img-blog.csdnimg.cn/b76bfac0ba184afca291ca46e64c1e21.png)
**在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/183a6634b013461e9d1b9171460a1518.png)
**虚函数重写的两个例外：**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 . **协变(基类与派生类虚函数返回值类型不同)**
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;派生类重写基类虚函数时，与基类虚函数返回值类型不同。即基类虚函数返回基类对象的指针或者引用，派生类虚函数返回派生类对象的指针或者引用时，称为协变。
```cpp
class A{};
class B : public A {};

class Person {
public:
	virtual A* f() {return new A;}
};

class Student : public Person {
public:
	virtual B* f() {return new B;}
};
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 2 .**析构函数的重写(基类与派生类析构函数的名字不同)**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字，都与基类的析构函数构成重写，虽然基类与派生类析构函数名字不同。虽然函数名不相同，看起来违背了重写的规则，其实不然，这里可以理解为编译器对析构函数的名称做了特殊处理，**编译后析构函数的名称统一处理成destructor**。

```cpp
class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};

// 只有派生类Student的析构函数重写了Person的析构函数，
// 下面的delete对象调用析构函数，才能构成态，才能保证p1和p2指向的对象正确的调用析构函数。
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}
```
**ps:只有在动态申请的子类对象给了父类对象指针管理时，才需要重写析构函数，其他的场景下，不重写析构函数都可以正常调用。**

## C++11 final和override
C++对函数重写的要求比较严格，但是有些情况下由于疏忽，可能会导致函数名字母次序写反而无法构成重载，而这种错误在编译期间是不会报出的，只有在程序运行时没有得到预期结果才来debug会得不偿失，因此：**C++11提供了override和final两个关键字，可以帮助用户检测是否重写。**

1.***final***：**修饰虚函数，表示该虚函数不能再被重写。**

在C++98，如果要设计一个不被继承的类，需要将该类的构造函数的访问限定符设为private：

```cpp
class A
{
private:
	A(int a)
		:_a(a)
	{}

protected:
	int _a;
};
```
这样的形式是间接限制，子类的构造函数无法调用父类的构造函数初始化成员，无法实例化出对象。

在C++11中，引入了final关键字，放在类名或者虚函数名之后，就直接限制了不能被子类继承或被子类的虚函数重写。

```cpp
class A final
{
protected:
	int _a;
};

class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-舒适" << endl; }
};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/e688664d2cde402cb547b50c26155e38.png)
2.***override*：检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。**

```cpp
class Car {
public:
	virtual void Drive() {}
};
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-舒适" << endl; }
};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/ea9a5bd38540430999e31dadda015529.png)
## 重载、覆盖(重写)、隐藏(重定义)的对比
![在这里插入图片描述](https://img-blog.csdnimg.cn/5761e8b40d03439f99fcfff541ad094d.png)
# 抽象类
## 抽象类的概念
在虚函数的后面写上 =0 ，则这个函数为纯虚函数。**包含纯虚函数的类叫做抽象类（也叫接口类），抽象类不能实例化出对象**。派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象。纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承。

```cpp
class Car
{
public:
	virtual void Drive() = 0;
};

class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-舒适" << endl;
	}
};

class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-操控" << endl;
	}
};
```
## 接口继承和实现继承
普通函数的继承是一种**实现继承**，派生类继承了基类函数，可以使用函数，继承的是函数的实现。虚函数的继承是一种**接口继承**，派生类继承的是基类虚函数的接口，目的是为了重写，达成多态，继承的是接口。所以如果不实现多态，不要把函数定义成虚函数。

<br>

# 多态的原理
## 虚函数表

**笔试题：sizeof(Base)是多少？**

```cpp
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	char _a = 'a';
	int _b = 1;
};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/1fdfa69c2aee43e28fa3abd2c8d78edc.png)
我们发现b对象是**12bytes**，**除了_a和_b成员，还多一个__vfptr放在对象的前面(注意有些平台可能会放到对象的最后面，这个跟平台有关)，对象中的这个指针我们叫做虚函数表指针(v代表virtual，f代表function)**。一个含有虚函数的类中都至少都有一个虚函数表指针，因为虚函数的地址要被放到虚函数表中，虚函数表也简称虚表。
![在这里插入图片描述](https://img-blog.csdnimg.cn/b74df011b92041efbf0501de9185b066.png)

```cpp
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Derive::Func2()" << endl;
	}
private:
	int _d = 2;
};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/1f6a5e25907941c1b862cc70331240d1.png)
通过以上代码调试，我们会发现虚函数表的地址和函数的地址对不上，这是为什么？
**通过vs2013下的汇编指令观察，实际上，虚函数表里面存的是call eax指令中jmp指令的地址，编译器再通过jmp指令跳转到函数的真实地址进行调用。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/7f9c0b130ab34b728496ce541b660d5b.png)
通过观察和测试，我们还发现了以下几点问题：
1. 派生类对象d中也有一个虚表指针，d对象由两部分构成，**一部分是父类继承下来的成员，虚表指针也就是存在部分的另一部分是自己的成员**。
2. 基类b对象和派生类d对象虚表是不一样的，这里我们发现**Func1完成了重写，所以d的虚表中存的是重写的Derive::Func1**，所以虚函数的重写也叫作覆盖，覆盖就是指虚表中虚函数的覆盖。**重写是语法的叫法，覆盖是原理层的叫法**。
3. 另外Func2继承下来后是虚函数，所以放进了虚表，Func3也继承下来了，但是不是虚函数，所以不会放进虚表。
4. 虚函数表本质是**一个存虚函数指针的指针数组**，一般情况这个数组最后面放了一个nullptr。
5. 总结一下派生类的虚表生成：a.**先将基类中的虚表内容拷贝一份到派生类虚表中 b.如果派生类重写了基类中某个虚函数，用派生类自己的虚函数覆盖虚表中基类的虚函数 c.派生类自己新增加的虚函数按其在派生类中的声明次序增加到派生类虚表的最后**。
6. 这里还有一个很容易混淆的问题：虚函数存在哪的？虚表存在哪的？ 答：虚函数存在虚表，虚表存在对象中。注意上面的回答的错的。但是很多童鞋都是这样深以为然的。注意**虚表存的是虚函数指针，不是虚函数，虚函数和普通函数一样的，都是存在代码段的，只是他的指针又存到了虚表中**。另外对象中存的不是虚表，存的是虚表指针。那么虚表存在哪的呢？实际我们去验证一下会发现vs下是存在代码段的。

```cpp
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
};

int main()
{
	int* p = (int*)malloc(4);
	printf("堆:%p\n", p);

	int a = 0;
	printf("栈:%p\n", &a);

	static int b = 0;
	printf("数据段:%p\n", &b);

	const char* str = "aaaaaaa";
	printf("常量区:%p\n", str);

	printf("代码段:%p\n", &Base::Func1);

	Base bs;
	printf("虚函数表:%p\n", *((int*)&bs));

	return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/3a249a1c3f5943a3bd9e1284f5017b5e.png)
通过验证我们可以发现，虚函数表是存在常量区和代码段之间的，**实际上虚函数表是存在代码段的。**

## 多态的原理
![在这里插入图片描述](https://img-blog.csdnimg.cn/657da6b81af2446a812993af563d6818.png)
```cpp
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);

	return 0;
}
```
1. 观察下图的红色箭头我们看到，p是指向mike对象时，p->BuyTicket在mike的虚表中找到虚函数是Person::BuyTicket。
2. 观察下图的蓝色箭头我们看到，p是指向johnson对象时，p->BuyTicket在johson的虚表中找到虚函数是Student::BuyTicket。
3. 这样就实现出了不同对象去完成同一行为时，展现出不同的形态。
4. 要达到多态，有两个条件，**一个是虚函数覆盖，一个是对象的指针或引用调用虚函数**。
5. 再通过下面的汇编代码分析，**看出满足多态以后的函数调用，不是在编译时确定的，是运行起来以后到对象的中取找的。不满足多态的函数调用时编译时确认好的**。
![在这里插入图片描述](https://img-blog.csdnimg.cn/e55876b1fbd1450582ac695bf11a13bb.png)

```cpp

void Func(Person* p)
{
	p->BuyTicket();
}

int main()
{
	Person mike;
	Func(&mike);
	mike.BuyTicket();
	return 0;
}

// 以下汇编代码中跟你这个问题不相关的都被去掉了
void Func(Person* p)
{
	...
	p->BuyTicket();
	// p中存的是mike对象的指针，将p移动到eax中
	001940DE mov eax, dword ptr[p]
	// [eax]就是取eax值指向的内容，这里相当于把mike对象头4个字节(虚表指针)移动到了edx
	001940E1 mov edx, dword ptr[eax]
	// [edx]就是取edx值指向的内容，这里相当于把虚表中的头4字节存的虚函数指针移动到了eax
	00B823EE mov eax, dword ptr[edx]
	// call eax中存虚函数的指针。这里可以看出满足多态的调用，不是在编译时确定的，是运行起来以后到对象的中取找的。
	001940EA call eax
	001940EC cmp esi, esp
}

int main()
{
	...
	// 首先BuyTicket虽然是虚函数，但是mike是对象，不满足多态的条件，所以这里是普通函数的调用转换成地址时，是在编译时已经从符号表确认了函数的地址，直接call 地址
	mike.BuyTicket();
	00195182 lea ecx, [mike]
	00195185 call Person::BuyTicket(01914F6h)
	...
}


```
## 动态绑定与静态绑定
1. 静态绑定又称为前期绑定(早绑定)，在**程序编译期间**确定了程序的行为，也称为**静态多态**，比如：**函数重载**
2. 动态绑定又称后期绑定(晚绑定)，是在**程序运行期间**，根据具体拿到的类型确定程序的具体行为，调用具体的函数，也称为**动态多态**。


# 单继承和多继承关系的虚函数表 
## 单继承中的虚函数表

```cpp
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};

class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};
```
观察下图中的监视窗口中我们发现看不见func3和func4。这里是编译器的监视窗口隐藏了这两个函数，也可以认为是他的一个小bug。那么我们如何查看d的虚表呢？下面我们使用代码打印出虚表中的函数。
![在这里插入图片描述](https://img-blog.csdnimg.cn/b78da8ebca11474dba3cd4fc9fa87447.png)

```cpp
typedef void(*VF_PTR)();

void PrintVFTable(VF_PTR* table)
{
	for (int i = 0; table[i] != nullptr; i++)
	{
		printf("vtf[%d]:%p->", i, table[i]);
		VF_PTR f = table[i];
		f();
	}

	cout << endl;
}

int main()
{
	Base b;
	Derive d;
	PrintVFTable((VF_PTR*)*((int*)&b));
	PrintVFTable((VF_PTR*)*((int*)&d));
	
	return 0;
}
```
**思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr。**

 1.先取b的地址，强转成一个int*的指针。
 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针。
 3.再强转成VF_PTR\*，因为虚表就是一个存VF_PTR类型(虚函数指针类型)的数组。
 4.虚表指针传递给PrintVTable进行打印虚表。
5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的-生成-清理解决方案，再编译就好了。


运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/bf483203ed3546d8a27b9e4488ad2891.png)
## 多继承中的虚函数表

```cpp
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/d3d0bb1a86944305bb7b9ca15376fab2.png)
通过代码来打印虚表:

```cpp

typedef void(*VF_PTR)();

void PrintVFTable(VF_PTR* table)
{
	for (int i = 0; table[i] != nullptr; i++)
	{
		printf("vtf[%d]:%p->", i, table[i]);
		VF_PTR f = table[i];
		f();
	}

	cout << endl;
}

int main()
{
	Derive d;
	PrintVFTable((VF_PTR*)*((int*)&d));
	PrintVFTable((VF_PTR*)*((int*)((char*)&d + sizeof(Base1))));

	system("pause");
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/0fef1d952a80463a8f3c88c65072a3d3.png)
上面代码显示的是在32位下的虚表打印，如果是在64位下，**需要把int\*改long long\***，或者**利用条件编译和void\*进行32位和64位下的自适应**：

```cpp
int main()
{
	Derive d;
#ifdef _Win64
	PrintVFTable((VF_PTR*)*((long long*)&d));
#else
	PrintVFTable((VF_PTR*)*((int*)&d));
#endif

	return 0;
}
```
```cpp

int main()
{
	Derive d;	
	PrintVFTable((VF_PTR*)*((void**)&d));

	return 0;
}
```

