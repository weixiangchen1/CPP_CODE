//#include <iostream>
//#include <algorithm>
//#include <numeric>
//#include <string>
//using namespace std;
//
////int main()
////{
////	string s1;
////	cin >> s1;
////
////	cout << s1 << endl;
////	string s2(s1);
////	cout << s2 << endl;
////
////	string s3("hello");
////	cout << s3 << endl;
////
////	return 0;
////}
////
////int main()
////{
////	string s("hello world");
////
////	cout << s.size() << endl;
////	cout << s.length() << endl;
////	cout << s.max_size() << endl;
////	cout << s.capacity() << endl;
////	cout << s << endl;
////	s.clear();
////	cout << s << endl;
////	cout << s.size() << endl;
////	cout << s.capacity() << endl;
////		
////
////	return 0;
////}
//
//void test_string01()
//{
//	string s = "hello world";
//	//±éÀú1
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	//±éÀú2
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		*it++;
//	}
//	cout << endl;
//
//	//±éÀú3
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string::const_reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//}
//
//void test_string02()
//{
//	string s1;
//	s1.reserve(5);
//
//	string s2;
//	s2.resize(5, 0);
//
//	string s3("hello world");
//	s3.reserve(100);
//
//	string s4("hello world");
//	s4.resize(100, 5);
//
//}
//
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//
//	cout << "capacity changed: " << sz << '\n';
//	cout << "making s grow:\n";
//	for (int i = 0; i < 1000; ++i)
//	{
//		//s.push_back('c');
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//	s.resize(5);
//	string(s).swap(s);
//	cout << "size " << s.size() << endl;
//	cout << "capacity changed: " << s.capacity() << '\n';
//}
//
//void test_string03()
//{
//	string s("hello world");
//	cout << s << endl;
//	cout << s.c_str() << endl;
//
//	//string file("text.txt");
//	////FILE* fout = fopen(file.c_str(), "w");
//	//size_t pos = file.find('.');
//	//if (pos != string::npos)
//	//{
//	//	string suffix = file.substr(pos, file.size() - pos);
//	//	cout << suffix << endl;
//	//}
//
//	string file("test.txt.zip");
//	size_t pos = file.rfind('.');
//	if (pos != string::npos)
//	{
//		string suffix = file.substr(pos, file.size() - pos);
//		cout << suffix << endl;
//	}
//
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	size_t pos1 = url.find(':');
//	string protocol = url.substr(0, pos1);
//	cout << protocol << endl;
//
//	size_t pos2 = url.find('/', pos1 + 3);
//	string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
//	cout << domain << endl;
//
//	size_t pos3 = url.find('/', pos2);
//	string uri = url.substr(pos3);
//	cout << uri << endl;
//
//}
//
//void test_string04()
//{
//	string s("hello world");
//	s += '!';
//	cout << s << endl;
//
//	s.insert(s.end(), '?');
//	cout << s << endl;
//
//	s.erase(0, 1);
//	s.erase(s.size() - 1, 1);
//	cout << s << endl;
//
//	s.erase(4);
//	cout << s << endl;
//}
//
//int main()
//{
//	//test_string01();
//	//test_string02();
//	//TestPushBack();
//	//test_string03();
//	test_string04();
//
//	return 0;
//}
//


#include<iostream>
using namespace std;
class Test {
    int val;
public:
    Test()
    {
        cout << "Default.\n";
    }
    Test(int i) :val(i)
    {
        cout << "Con.\n";
    }
    Test(const Test& t) {
        val = t.val; cout << "Copy Con." << endl;
    }
};
int main() {
    Test t1(6);
    Test t2 = t1;
    Test t3;
    t3 = t1;
    return 0;
}
