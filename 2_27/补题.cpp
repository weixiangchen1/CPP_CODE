#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//int Fib(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << Fib(n) << endl;
//
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int tmp = n;
//	int a = tmp % 10;
//	tmp /= 10;
//	int b = tmp % 10;
//	tmp /= 10;
//
//	cout << n << "=" << tmp * 100 << "+" << b * 10 << "+" << a << endl;
//
//
//	return 0;
//}

//int main()
//{
//	int n, count = 0;
//	cin >> n;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n & 1 == 1)
//		{
//			count++;
//		}
//		n >>= 1;
//	}
//	cout << count << endl;
//
//	return 0;
//}
//int main()
//{
//	int n, count1 = 0, count2 = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		if (i % 9 == 0)
//		{
//			count1++;
//		}
//	}
//
//	for (int i = 9; i < n; i += 10)
//	{
//		if (i % 9 != 0 && i%10 == 9)
//		{
//			count2++;
//		}
//	}
//
//	cout << count1 + count2 << endl;
//
//	return 0;
//}

//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#define MAX_TIME 10
//
//using namespace std;
//
//string stringReverse(string s)
//{
//	int i = 0, j = s.size() - 1;
//	while (i < j) {
//		swap(s[i++], s[j--]);
//	}
//	return s;
//}
//
//bool isPalindromic(string s)
//{
//	return s == stringReverse(s);
//}
//
//string addReverse(string s)
//{
//	string A = s;
//	string B = stringReverse(s);
//
//	string C = "";
//	char digit;
//	int step = 0;
//	for (int i = 0; i < A.size(); i++) {
//		digit = A[i] + B[i] - '0' + step;
//		if (digit > '9') {
//			digit -= 10;
//			step = 1;
//		}
//		else {
//			step = 0;
//		}
//		C += digit;
//	}
//	if (step) {
//		C += '1';
//	}
//
//	reverse(C.begin(), C.end());
//
//	return C;
//}
//
//int main()
//{
//	string num;
//	cin >> num;
//
//	bool isFound = false;
//
//	int count = 0;
//	while (count < MAX_TIME) {
//		if (!isPalindromic(num)) {
//			string A = num, B = stringReverse(num);
//			num = addReverse(num);
//			cout << A << " + " << B << " = " << num << endl;
//		}
//		else {
//			isFound = true;
//			cout << num << " is a palindromic number." << endl;
//			break;
//		}
//
//		count++;
//	}
//
//	if (!isFound) {
//		cout << "Not found in 10 iterations." << endl;
//	}
//
//	return 0;
//}
//
//void TestString01()
//{
//	string str1 = "hello world";
//	string str2(str1);
//	cout << str2 << endl;
//	string str3(str2, 0, 5);
//	cout << str3 << endl;
//	string str4(str2, 5);
//	cout << str4 << endl;
//
//}
//
//void TestString02()
//{
//	string str1 = "Hello World";
//	cout << str1.length() << endl;
//	cout << str1.size() << endl;
//	cout << str1.max_size() << endl;
//	cout << str1.capacity() << endl;
//
//	string str2 = "Hello World";
//	cout << str1.compare(str2) << endl;
//}
//
//void TestString03()
//{
//	string str1;
//	str1.push_back('a');
//	str1.push_back('b');
//	str1.push_back('c');
//	str1.insert(str1.begin(), 'd');
//	cout << str1 << endl;
//}
//
//void TestString04()
//{
//	string s1 = "Hello ";
//	string s2 = "world";
//	s1.append(s2);
//
//	cout << s1 << endl;
//
//	string s3 = "fuck ";
//	string s4 = "you";
//	s3 += s4;
//	cout << s3 << endl;
//}
//
//void TestString05()
//{
//	string s1 = "abcdef";
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i];
//	}
//	cout << endl;
//
//	string::iterator it = s1.begin();
//	for (; it != s1.end(); it++)
//	{
//		cout << *it;
//	}
//	cout << endl;
//
//	string::reverse_iterator rit = s1.rbegin();
//	for (; rit != s1.rend(); rit++)
//	{
//		cout << *rit;
//	}
//	cout << endl;
//}
//
//void TestString06()
//{
//	string s1 = "Hello World";
//	s1.erase(s1.begin());
//	s1.erase(1, 6);
//	cout << s1 << endl;
//}
//
//void TestString07()
//{
//	string s1 = "Hello World!";
//	s1.replace(s1.size() - 1, 1, 1, '.');
//	cout << s1 << endl;
//	s1.replace(s1.begin(), s1.begin() + 5, "boy");
//	cout << s1 << endl;
//	s1.replace(4, 5, "girl");
//	cout << s1 << endl;
//}
//
//void TestString08()
//{
//	string s1 = "ABCDE";
//	string::iterator it = s1.begin();
//	for (; it != s1.end(); it++)
//	{
//		*it = tolower(*it);
//	}
//	cout << s1 << endl;
//	for (auto& x : s1)
//	{
//		x = toupper(x);
//	}
//	cout << s1 << endl;
//}
//
//void TestString09()
//{
//	string s1 = "Hello World";
//	int pos = s1.find("World", 0);
//	cout << pos << endl;
//}
//
//int main()
//{
//	//TestString01();
//	//TestString02();
//	//TestString03();
//	//TestString04();
//	//TestString05();
//	//TestString06();
//	//TestString07();
//	//TestString08();
//	TestString09();
//	return 0;
//}
