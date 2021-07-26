//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct Person
//{
//	char name[10];
//	int year;
//};
//
//void Myprint(int val)
//{
//	cout << val << endl;
//
//}
//
//void test01()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	vector<int>::iterator pBegin = v.begin();
//	vector<int>::iterator pEnd = v.end();
//
//	while (pBegin != pEnd)
//	{
//		cout << *pBegin << endl;
//		pBegin++;
//	}
//
//	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;
//	}*/
//
//	/*for_each(v.begin(), v.end(), Myprint);*/
//
//}
//
//void test02()
//{
//	vector<struct Person> v;
//	struct Person p1 = { "aaa", 10 };
//	struct Person p2 = { "bbb", 20 };
//	struct Person p3 = { "ccc", 30 };
//	struct Person p4 = { "ddd", 40 };
//	struct Person p5 = { "eee", 50 };
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//
//	for (vector<struct Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "Name:" << (*it).name << " Age:" << (*it).year << endl;
//
//	}
//}
//
//void test03()
//{
//	vector<vector<int>> v;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//
//	for (int i = 0; i < 4; i++)
//	{
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
//		{
//			cout << *vit << " ";
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	//test01();
//	//test02();
//	test03();
//	system("pause");
//	return 0;
//}
