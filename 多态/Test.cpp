#include <iostream>
using namespace std;
//
//class Person{
//public:
//	virtual void BuyTicket(){ cout << "��Ʊ-ȫƱ" << endl; }
//};
//
//class Student : public Person{
//public:
//	void BuyTicket() { cout << "��Ʊ-��Ʊ" << endl; }
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
//// ֻ��������Student������������д��Person������������
//// �����delete��������������������ܹ���̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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
//	print(p);//���Բ������ܳ�
//	p = new Rectangle(l, w);
//	print(p);//�������������ܳ�
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
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};
//
//class Car {
//public:
//	void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
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
//	printf("��:%p\n", p);
//
//	int a = 0;
//	printf("ջ:%p\n", &a);
//
//	static int b = 0;
//	printf("���ݶ�:%p\n", &b);
//
//	const char* str = "aaaaaaa";
//	printf("������:%p\n", str);
//
//	printf("�����:%p\n", &Base::Func1);
//
//	Base bs;
//	printf("�麯����:%p\n", *((int*)&bs));
//
//	return 0;
//}
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//		// p�д����mike�����ָ�룬��p�ƶ���eax��
//		001940DE mov eax, dword ptr[p]
//		// [eax]����ȡeaxֵָ������ݣ������൱�ڰ�mike����ͷ4���ֽ�(���ָ��)�ƶ�����edx
//		001940E1 mov edx, dword ptr[eax]
//		// [edx]����ȡedxֵָ������ݣ������൱�ڰ�����е�ͷ4�ֽڴ���麯��ָ���ƶ�����eax
//		00B823EE mov eax, dword ptr[edx]
//		// call eax�д��麯����ָ�롣������Կ��������̬�ĵ��ã������ڱ���ʱȷ���ģ������������Ժ󵽶����
//		��ȡ�ҵġ�
//		001940EA call eax
//		00ͷ1940EC cmp esi, esp
//}
//int main()
//{
//		...
//		// ����BuyTicket��Ȼ���麯��������mike�Ƕ��󣬲������̬��������������������ͨ�����ĵ���ת���ɵ�ַ
//		ʱ�����ڱ���ʱ�Ѿ��ӷ��ű�ȷ���˺����ĵ�ַ��ֱ��call ��ַ
//		mike.BuyTicket();
//		00195182 lea ecx, [mike]
//		00195185 call Person::BuyTicket(01914F6h)
//		...
//}
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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