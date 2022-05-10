#include <iostream>
#include <string>
using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
//protected:
//	string _name = "Durant";
//	int _age = 18;
//};
//
//class Student : public Person
//{
//protected:	
//	int _No;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	p.Print();
//	s.Print();
//
//	return 0;
//}
//
//class Person
//{
//protected:
//	string _name;
//	string _sex;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	int _No;
//};
//
//int main()
//{
//	Student s;
//	Person p;
//
//	// ����=���ࣺ���������ĸ�ֵ���ݣ��и�/��Ƭ
//	p = s;
//	Person* ptr = &s;
//	Person& ref = s;
//
//	// �����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	Student* pptr = (Student*)ptr;
//	Student& rref = (Student&)ref;
//	pptr->_No = 10;
//
//	return 0;
//}

//// ����͸������ͬ����Ա������/�ض���
//class Person
//{
//protected:
//	string _name = "Durant";
//	int _num = 35;
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//
//protected:
//	int _num = 11;
//};
//
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	return 0;
//}

// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء� 
//class A
//{
//public:
//	void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "fun(i)" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(10);
//	//b.fun(); // �޷����ã���������
//	b.A::fun();
//
//	return 0;
//}
//
//class Person
//{
//public:
//	Person(const char* name = "")
//		:_name(name)
//	{
//		cout << "Person(const char* name)" << endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "", const int& num = 0)
//		:Person(name)
//		,_num(num)
//	{
//		cout << "Student(const char* name, const int& num)" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);
//		}
//
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num;
//};
//
//// ����������������ʱ�����Զ����ø������������
//// ���������Լ�ʵ��������������ʱ������Ҫ��ʾ���ø�����������
//// �������ܱ�֤�����������Ա�������������Ա
//
//int main()
//{
//	Person p1;
//	Person p2(p1);
//
//	Student s1 = { "���", 200804004 };
//	Student s2(s1);
//
//	return 0;
//}

// ��Ԫ��ϵ���ܼ̳�
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

// ����ľ�̬��ԱΪ�����̳���ϵ�����ã��������������ٸ����࣬��ֻ��һ����̬��Աʵ��
//class Person
//{
//public:
//	Person()
//	{
//		++_count;
//	}
//public:
//	static int _count;
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _num;
//};
//
//class Greduate :public Student
//{
//protected:
//	string _course;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	Greduate g;
//
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	cout << Greduate::_count << endl;
//
//	return 0;
//}

// ���μ̳У���������Ͷ�����
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student :  virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher :  virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	Assistant a;
//	a.Student::_name = "wyq";
//	a.Teacher::_name = "cwx";
//	a._name = "111";
//
//	return 0;
//}

class A
{
public:
	int _a;
};

// class B : public A
class B : virtual public A
{
public:
	int _b;
};

// class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}