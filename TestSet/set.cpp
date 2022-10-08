#include <iostream>
#include <set>
using namespace std;

void test_set()
{
	set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(1);
	s.insert(2);
	s.insert(6);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::iterator pos = s.find(5);
	if (pos != s.end())
	{
		s.erase(pos);
	}

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_multiset()
{
	multiset<int> s;
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(4);
	
	// find多个相同的值时，返回中序的第一个
	//multiset<int>::iterator pos = s.find(4);
	//while (pos != s.end())
	//{
	//	cout << *pos << " ";
	//	pos++;
	//}
	//cout << endl;

	//multiset<int>::iterator pos = s.find(1);
	//while (pos != s.end() && *pos == 1)
	//{
	//	auto next = pos;
	//	next++;

	//	s.erase(pos);
	//	pos = next;
	//}
	
	cout << s.erase(1) << endl;

	for (auto& e: s)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_set();
	test_multiset();
	return 0;
}