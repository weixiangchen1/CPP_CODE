#include <iostream>
#include <string>
using namespace std;

//string构造函数
void test01()
{
	string s1;
	cout << "s1 = " << s1 << endl;

	const char* str = "hello world";
	string s2(str);
	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(5, 'x');
	cout << "s4 = " << s4 << endl;
}

//string赋值操作
void test02()
{
	string str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'x';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello world");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello world", 5);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}

//string字符串拼接
void test03()
{
	string s1 = "我";
	s1 += "爱玩游戏";
	cout << "s1 = " << s1 << endl;

	s1 += ':';
	cout << "s1 = " << s1 << endl;

	string s2 = "LOL DNF";
	s1 += s2;
	cout << "s1 = " << s1 << endl;

	string s3 = "I";
	s3.append(" love ");
	s3.append("game abcde", 4);
	//s3.append(s2);
	//s3.append(s2, 0, 3);
	//s3.append(s2, 4, 3);
	cout << "s3 = " << s3 << endl;

}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}