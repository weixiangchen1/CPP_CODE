#include <iostream>
using namespace std;
//
//class Person{
//public:
//	virtual void BuyTicket(){ cout << "买票-全票" << endl; }
//};
//
//class Student : public Person{
//public:
//	void BuyTicket() { cout << "买票-半票" << endl; }
//};
//
//void Func(Person& p){
//	p.BuyTicket();
//}
//
//int main(){
//	Person p;
//	Student s;
//
//	Func(p);
//	Func(s);
//
//	return 0;
//}
//
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//// 只有派生类Student的析构函数重写了Person的析构函数，
//// 下面的delete对象调用析构函数，才能构成态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}
//
//const double PI = 3.14;
//class Shape {
//public:
//	virtual double getArea() = 0;
//	virtual double getPerim() = 0;
//};
//
//class Circle : public Shape
//{
//public:
//	Circle(double r)
//		:_r(r)
//	{}
//
//	double getArea() {
//		return 3.14 * _r * _r;
//	}
//
//	double getPerim() {
//		return 2 * 3.14 * _r;
//	}
//
//private:
//	double _r;
//};
//
//class Rectangle :public Shape
//{
//
//public:
//	Rectangle(double x, double y) 
//		:_x(x)
//		,_y(y)
//	{}
//
//	double getArea()
//	{
//		return _x * _y;
//	}
//
//	double getPerim()
//	{
//		return 2 * (_x + _y);
//	}
//
//private:
//	double _x;
//	double _y;
//};
//
//void print(Shape* p) 
//{
//	cout << "Area:" << p->getArea() << endl;
//	cout << "Perimeter:" << p->getPerim() << endl;
//}
//
//int main() {
//	double r, l, w;
//	cin >> r;
//	cin >> l >> w;
//	Shape* p = NULL;
//	p = new Circle(r);
//	print(p);//输出圆面积与周长
//	p = new Rectangle(l, w);
//	print(p);//输出矩形面积与周长
//	return 0;
//}
//
//class A
//{
//private:
//	A(int a)
//		:_a(a)
//	{}
//
//protected:
//	int _a;
//};
//
//class B : A
//{};
//
//int main()
//{
//	B b;
//	return 0;
//}
//
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};
//
//class Car {
//public:
//	void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	char _a = 'a';
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	return 0;
//}
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Derive::Func2()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	int* p = (int*)malloc(4);
//	printf("堆:%p\n", p);
//
//	int a = 0;
//	printf("栈:%p\n", &a);
//
//	static int b = 0;
//	printf("数据段:%p\n", &b);
//
//	const char* str = "aaaaaaa";
//	printf("常量区:%p\n", str);
//
//	printf("代码段:%p\n", &Base::Func1);
//
//	Base bs;
//	printf("虚函数表:%p\n", *((int*)&bs));
//
//	return 0;
//}
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//
//	return 0;
//}

//void Func(Person* p)
//{
//	p->BuyTicket();
//}
//int main()
//{
//	Person mike;
//	Func(&mike);
//	mike.BuyTicket();
//	return 0;
//}
//void Func(Person* p)
//{
//		...
//		p->BuyTicket();
//		// p中存的是mike对象的指针，将p移动到eax中
//		001940DE mov eax, dword ptr[p]
//		// [eax]就是取eax值指向的内容，这里相当于把mike对象头4个字节(虚表指针)移动到了edx
//		001940E1 mov edx, dword ptr[eax]
//		// [edx]就是取edx值指向的内容，这里相当于把虚表中的头4字节存的虚函数指针移动到了eax
//		00B823EE mov eax, dword ptr[edx]
//		// call eax中存虚函数的指针。这里可以看出满足多态的调用，不是在编译时确定的，是运行起来以后到对象的
//		中取找的。
//		001940EA call eax
//		00头1940EC cmp esi, esp
//}
//int main()
//{
//		...
//		// 首先BuyTicket虽然是虚函数，但是mike是对象，不满足多态的条件，所以这里是普通函数的调用转换成地址
//		时，是在编译时已经从符号表确认了函数的地址，直接call 地址
//		mike.BuyTicket();
//		00195182 lea ecx, [mike]
//		00195185 call Person::BuyTicket(01914F6h)
//		...
//}
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//
//	return 0;
//}
//
//
//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};


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
//
//int main()
//{
//	Derive d;
//#ifdef _Win64
//	PrintVFTable((VF_PTR*)*((long long*)&d));
//#else
//	PrintVFTable((VF_PTR*)*((int*)&d));
//#endif
//
//	return 0;
//}

int main()
{
	Derive d;
	PrintVFTable((VF_PTR*)*((void**)&d));

	return 0;
}