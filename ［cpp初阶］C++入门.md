@[toc]
# 命名空间

在C/C++中，变量、函数和后面要学到的类都是大量存在的，这些变量、函数和类的名称将都存在于**全局作用域**中，可能会导致很多冲突。使用命名空间的目的是**对标识符的名称进行本地化**，以**避免命名冲突或名字污染**，namespace关键字的出现就是针对这种问题的。  

## 命名空间定义

比如：

![在这里插入图片描述](https://img-blog.csdnimg.cn/fa0512a4077443f7b14b6d0ad3e0351e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)

rand是在stdlib.h中包含的一个函数，上面代码使用rand作为一个整型变量，就会造成**命名冲突**。


这个问题用命名空间就可以的到很好解决：
![在这里插入图片描述](https://img-blog.csdnimg.cn/5804197a5b9e4142aa8d8fbde2bf8693.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
定义命名空间，需要用到**namespace**关键字，后面跟**命名空间的名字**，然后接一对花括号，花括号中是命名空间的成员。命名空间的成员既可以是变量，也可以是函数。

```c++
//1. 普通的命名空间
namespace N1
{
    int a;
    double b;
    int Add(int x, int y)
    {
        return x + y;
    }
}
//2.命名空间可以嵌套
namespace N2
{
    int a;
    int b;
    int Add(int x, int y)
    {
        return x + y;
    }
    //N3是嵌套在命名空间N2中的一个命名空间
    namespace N3
    {
        int c;
        int d;
        int Sub(int x, int y)
        {
            return x - y;
        }
    }
}
```

总结：

+ **命名空间中既可以定义变量，又可以定义函数**。
+ **命名空间可以嵌套使用**。
+ **在同一个工程中，允许存在多个相同名称的命名空间，最终编译器会合成为同一个命名空间**。
+ **一个命名空间就定义了一个作用域，命名空间的内容都局限于该命名空间中**。

## 命名空间的使用

比如：

```c++
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
int main()
{
	printf("%d\n", a); 
	return 0;
}
```

**上面的使用是错误的，编译器无法识别a**。

命名空间的三种使用方式：

+ 加命名空间名字和作用域限定符

  ```cpp
  int main()
  {
  	printf("%d\n", N::a);
  	return 0;
  }
  ```

+ 使用using将命名空间中的成员引入

  ```cpp
  using N::a;
  int main()
  {
      printf("%d\n", a);
      return 0;
  }
  ```

+ 使用using namespace加命名空间名称引入

  ```cpp
  using namespace N;
  int main()
  {
      printf("%d\n", a);
      return 0;
  }
  ```

**注意：第三种使用方式会将命名空间N全部展开到main函数之前，用起来方便，但是命名空间对于变量和函数的隔离就失效了。**

#  C++输入输出

在C++中，使用cout和cin进行输入输出。

第一个C++程序：

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "hello world\n" << endl;
    
    return 0;
}
```

说明：

1. 使用**cout标准输出（控制台）**和**cin标准输入（键盘）**时，必须包含**<iostream>**头文件以及**std标准命名空间**。
2. 使用C++标准输入输出比较方便，不用像C语言一样控制数据格式输出。

```cpp
#include <iostream>
using namespace std;

int main()
{
	int a;
	double b;
	cin >> a >> b;
	cout << a << " " << b << endl;

	return 0;
}
```

# 缺省函数

**缺省参数**是**声明或定义函数时**为函数的参数指定一个**默认值**。在调用该函数时，如果没有指定实参则采用该
默认值，否则使用指定的实参 。

```cpp
void Test(int a = 10)
{
    cout << a << endl;
}
int main()
{
    Test(20);   //有传参时，使用指定的实参
    Test();		//没有传参时，使用参数默认值
}
```

## 缺省函数分类

+ **全缺省参数**（所有参数均给默认值）

  ```cpp
  void Test(int a = 10, int b = 20, int c = 30)
  {
      cout << "a = " << a << endl;
      cout << "b = " << b << endl;
      cout << "c = " << c << endl;
  }
  int main()
  {
      Test();
      Test(1);
      Test(1, 2);
      Test(1, 2, 3);
      
      return 0;
  }
  ```

+ **半缺省参数**（部分参数给默认值）

  ```cpp
  void Test(int a, int b = 20, int c = 30)
  {
      cout << "a = " << a << endl;
      cout << "b = " << b << endl;
      cout << "c = " << c << endl;
  }
  int main()
  {
      Test(1);
      Test(1, 2);
      Test(1, 2, 3);
      
      return 0;
  }
  ```

**注意**：

+ **半缺省参数必须从右往左给，不能间隔**。
+ **缺省函数不能在函数声明和定义中同时出现**。
+ **缺省值必须是常量或者全局变量**。
+ **C语言不支持缺省函数。**

# 函数重载

## 函数重载概念

**函数重载**:是函数的一种特殊情况，C++允许在**同一作用域**中声明几个功能类似的**同名函数**，这些同名函数的
形参列表**(参数个数 或 类型 或 顺序)**必须不同，常用来处理实现功能类似数据类型不同的问题。

```cpp
// 函数重载
// 函数参数的类型、顺序和个数不同
// 返回值不同不构成函数重载
//1、类型不同
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

//2、顺序不同
void Func(int a, char b)
{
	cout << "int a, char b" << endl;
}

void Func(char b, int a)
{
	cout << "char b, int a" << endl;
}

//3、个数不同
void Func(int a)
{
	cout << "int a" << endl;
}

void Func(int a, int b)
{
	cout << "int a, int b" << endl;
}
```

**几种特殊情况**：

```cpp
// 1、缺省值不同，不能构成重载
void f(int a)
{
	cout << "f()" << endl;
}

void f(int a = 0)
{
	cout << "f(int a)" << endl;
}

// 2、构成重载
void f()
{
	cout << "f()" << endl;
}

void f(int a = 0)
{
	cout << "f(int a)" << endl;
}
```

> 注意第二种，虽然两个函数构成重载，但是在函数调用f()时会存在歧义，编译器无法识别需要调用哪个函数，所以编译器会报错。

## 函数名修饰规则

**为什么C++支持函数重载而C语言不支持函数重载？**

一个程序要运行起来，需要经历：**预处理，编译，汇编和链接**四个阶段。

![<img src="C++入门.assets/image-20220128235404211.png" alt="image-20220128235404211" style="zoom:80%;" />](https://img-blog.csdnimg.cn/71c3b91857fb4804b1dc816751ff1f16.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


**假设我们定义了func.h  func.c  test.c 三个文件**。

![<img src="C++入门.assets/image-20220129004826254.png" alt="image-20220129004826254" style="zoom:50%;" />](https://img-blog.csdnimg.cn/82358971aa974535874b927064c411db.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


**文件会经历几个过程**：

1. **预处理**-> 头文件展开、宏的替换、条件编译、注释删除

   生成func.i 和 test.i 两个文件

2. **编译** -> 检查语法，生成汇编代码

   生成func.s 和 test.s 两个文件

3. **汇编**-> 汇编代码转化成二进制代码

   生成func.o 和 test.o 两个文件

4. **链接** -> 合并段表、合并符号表、符号表的重定位

   生成a.out 可执行文件

**在链接合并符号表时，编译器会通过修饰过后的函数名到符号表里面去找函数的地址来调用，在c和c++中函数名的修饰规则时不一样的**。

**C的函数名**：

![\[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-N9EdAjjL-1650863234988)(C++入门.assets/image-20220129005938194.png)\]](https://img-blog.csdnimg.cn/029cdaa0ddf940139ee506c9eec91cde.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


**C++的函数名**：

![\[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-g3ot2lWe-1650863234989)(C++入门.assets/image-20220129005855862.png)\]](https://img-blog.csdnimg.cn/8a04496670eb4684be6565e58c3bd9c9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


> **可以看到：**
>
> **C语言在编译的时候，两个重载函数名字相同，在func.o的符号表中存在歧义和冲突，在链接的时候也会存在歧义和冲突，因为C语言是用函数名直接去标识和查找，而重载函数的函数名相同，所以C语言不支持函数重载。**
>
> **C++在编译的时候，不是直接用函数名去表示和查找，C++存在函数名修饰规则，只要函数参数的个数，顺序或类型不同，修饰后的函数名就不同，在func.o的符号表里就不存在歧义和冲突，链接的时候，test.o调用两个重载函数名去查找地址时，也就不会冲突。**

## extern "C"

有时候在C++工程中可能需要**将某些函数按照C的风格来编译，在函数前加extern "C"，意思是告诉编译器，
将该函数按照C语言规则来编译**。  

1. 当C++的项目要调用C的库时：

   首先第一步要包一下要调用库的头文件：
![在这里插入图片描述](https://img-blog.csdnimg.cn/35e0a16e596842fcb2b9fc6689adc08d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


   ..表示上一层目录，两个..表示向上两层目录找到所需要的C静态库。

   当我们进行编译运行时，会出现问题：
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/b9eaeb0625024b9c9774178aa376d037.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)

   所以第二步要在工程属性中配置静态库的目录和添加静态库
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/33b78ffbb1cc409ba513e08e2c3ab693.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
![](https://img-blog.csdnimg.cn/3d32d0dcda84445c9e8fd857d207beee.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


   配置完之后，再次编译运行，会发现还是会报错：
![在这里插入图片描述](https://img-blog.csdnimg.cn/740ed9c710cc41acb3a34269c7ef8129.png)


   原因是：当前是C++的程序调用C的库，而C++和C的函数名修饰规则不一样，在链接的时候，C++项目无法通过C++函数名修饰规则修饰后的函数名找到C库中的函数名。

   所以第三步，在头文件前加上extern"C"，问题就解决了:
![在这里插入图片描述](https://img-blog.csdnimg.cn/c3cc5928727d490a953df6816453cd00.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


   

2. 当C的项目要调用C++的库时：

   ![](https://img-blog.csdnimg.cn/d6a0df6034b2417891cf084344295189.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


   此时运行程序还是会报错：

   ![在这里插入图片描述](https://img-blog.csdnimg.cn/44a14046b0a34d74b06a5c25d586b866.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


   这时候需要在C++的库中引入条件编译：

   ![在这里插入图片描述](https://img-blog.csdnimg.cn/2c5660e9e1264927bc42d2f63bc4699c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


   C++会默认定义__cplusplus这个符号，但是C语言不会，当头文件在C语言项目展开时，就不会包含extern "C"，这样就实现了用C项目调用C++的库。

   ![在这里插入图片描述](https://img-blog.csdnimg.cn/c957ad76a6dd4dac814193ad3566d1ed.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


# 引用

## 引用概念

**引用**不是新定义一个变量，而是给已存在变量**取了一个别名**，编译器不会为引用变量开辟内存空间，它和它
引用的变量**共用同一块内存空间**。  

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int& b = a;
    
    return 0;
}
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/ad262d9061824d659863ded68e5fcfb4.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


**引用的语法层的理解是没有开辟新的空间，只是对原来的a的空间取了一个新名字叫做b。**

## 引用特性

1. 引用在定义时必须初始化。
2. 一个变量可以有多个引用。
3. 引用一旦引用了一个实体，就不能再引用其他实体。

![\[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-ZC6TSBVq-1650863234992)(C++入门.assets/image-20220208164321196.png)\]](https://img-blog.csdnimg.cn/288b9d8ca7684cfeab086df27cab68cb.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


## 常引用

```cpp
void TestConstRef()
{
	const int a = 10;
	int& ra = a; // 权限放大，报错
	const int& ra = a;// 权限不变
	int b = 10; 
	const int& b = 10; // 权限缩小
}
```

## 使用场景

1. 做参数

   ```cpp
   void Swap(int& left, int& right)
   {
   	int temp = left;
   	left = right;
   	right = temp;
   }
   ```

2. 做返回值

   ```cpp
   int& Count()
   {
   	static int n = 0；
   	n++;
   	// ...
   	return n;
   }
   ```

注意：**如果函数返回时，出了函数作用域，如果返回对象还未还给系统，则可以使用引用返回，如果已经还给系统了，则必须使用传值返回** 。

## 引用和指针的区别  

在**语法概念**上引用就是一个别名，没有独立空间，和其引用实体共用同一块空间 。但是在**底层实现上**实际是有空间的，因为**引用是按照指针方式来实现的**。  

```cpp
int main()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
	return 0;
}
```

在汇编中，引用和指针的实现是一样的：

![在这里插入图片描述](https://img-blog.csdnimg.cn/9da81a05b209447786c2d3e85528dcbe.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


引用和指针的不同点:

**1. 引用在定义时必须初始化，指针没有要求
2. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型
   实体
3. 没有NULL引用，但有NULL指针
4.  在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占
   4个字节)
5. 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
6. 有多级指针，但是没有多级引用
7. 访问实体方式不同，指针需要显式解引用，引用编译器自己处理
8. 引用比指针使用起来相对更安全**  

# 内联函数

## 概念

以inline修饰的函数叫做内联函数，**编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销，内联函数提升程序运行的效率**。  

![在这里插入图片描述](https://img-blog.csdnimg.cn/add3c4d525b34325a1f8b68619070a56.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)


如果在上述函数前增加inline关键字将其改成内联函数，在编译期间编译器会用函数体替换函数的调用。

查看方式：

1. 在release模式下，查看编译器生成的汇编代码中是否存在call Add。
2. 在debug模式下，需要对编译器进行设置，否则不会展开。  

![在这里插入图片描述](https://img-blog.csdnimg.cn/e1fdd707fa6344ceb2c5ba414c72a6b5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/50276d6be9ed48578b3f8683bcbeb4ec.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)

## 特性

1. inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环/递归的函数不适宜使用作为内联函数。
2. inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环/递归等等，编译器优化时会忽略掉内联。
3. inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。

# auto关键字（C++11）
## auto简介

在早期C/C++中auto的含义是：使用auto修饰的变量，是具有自动存储器的局部变量，但遗憾的是一直没有人去使用它，大家可思考下为什么？
C++11中，标准委员会赋予了auto全新的含义即：**auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导而得**。

```cpp
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/45c75c6440014de2ad3d8ab7c9288b1a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)

**注意：**
 
 1. **使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类型。因此auto并非是一种“类型”的声明，而是一个类型声明时的“占位符”，编译器在编译期会将auto替换为变量实际的类型**。
  
## auto的使用细则
 1.**auto与指针和引用结合起来使用**
**用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&**

```cpp
int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	*a = 20;
	*b = 30;
	c = 40;
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/a568d477e9a34ab6b5cf0724b4e19c62.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)2.**在同一行定义多个变量**
**当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错，因为编译器实际只对第一个类型进行推导，然后用推导出来的类型定义其他变量。**

```cpp
void TestAuto()
{
	auto a = 1, b = 2;
	auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
}
```

运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/5383b29c64c040ee8894ca92709bb7a5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
## auto不能推导的场景
1.**auto不能作为函数的参数**

```cpp
// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
void TestAuto(auto a)
{}
```
2.**auto不能直接用来声明数组**

```cpp
void TestAuto()
{
int a[] = {1,2,3};
auto b[] = {4，5，6};
}
```
**3 .为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法
4.auto在实际中最常见的优势用法就是跟以后会讲到的C++11提供的新式for循环，还有lambda表达式等进行配合使用。**

# 基于范围的for循环(C++11)
## 范围for的语法
在C++98中如果要遍历一个数组，可以按照以下方式进行：

```cpp
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;
}
```
对于一个**有范围的集合**而言，由程序员来说明循环的范围是多余的，有时候还会容易犯错误。因此C++11中引入了基于范围的for循环。**for循环后的括号由冒号" ："分为两部分：第一部分是范围内用于迭代的变量，第二部分则表示被迭代的范围。**

```cpp
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
}
```
**注意：与普通循环类似，可以用continue来结束本次循环，也可以用break来跳出整个循环。**

## 范围for的使用条件

 1.**for循环迭代的范围必须是确定的**
 	**对于数组而言，就是数组中第一个元素和最后一个元素的范围**；对于类而言，应该提供begin和end的方法，begin和end就是for循环迭代的范围。
注意：以下代码就有问题，因为for的范围不确定。

```cpp
void TestFor(int array[])
{
	for(auto& e : array)
	cout<< e <<endl;
}
```
 2.**迭代的对象要实现++和==的操作。**

# 指针空值nullptr(C++11)
## C++98中的指针空值
在良好的C/C++编程习惯中，声明一个变量时最好给该变量一个合适的初始值，否则可能会出现不可预料的错误，比如未初始化的指针。如果一个指针没有合法的指向，我们基本都是按照如下方式对其进行初始化：

```cpp
void TestPtr()
{
	int* p1 = NULL;
	int* p2 = 0;
	// ……
}
```
NULL实际是一个宏，在传统的C头文件(stddef.h)中，可以看到如下代码：

```cpp
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif
```
可以看到，NULL可能被定义为字面常量0，或者被定义为无类型指针(void*)的常量。不论采取何种定义，在使用空值的指针时，都不可避免的会遇到一些麻烦，比如：

```cpp
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}
```
程序本意是想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，因此与程序的初衷相悖。
在C++98中，字面常量0既可以是一个整形数字，也可以是无类型的指针(void*)常量，但是编译器默认情况下将其看成是一个整形常量，如果要将其按照指针方式来使用，必须对其进行强转(void *)0。

注意：
**1. 在使用nullptr表示指针空值时，不需要包含头文件，因为nullptr是C++11作为新关键字引入的。**
**2. 在C++11中，sizeof(nullptr) 与 sizeof((void\*)0)所占的字节数相同.**
**3. 为了提高代码的健壮性，在后续表示指针空值时建议最好使用nullptr。**
