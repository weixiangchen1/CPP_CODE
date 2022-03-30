#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void test_vector01()
{
	vector<int> v1;
	vector<int> v2(10, 8);
	vector<int> v3(++v2.begin(), --v2.end());
	vector<int> v4(v3);

	string s("hello world");
	vector<char> v5(s.begin(), s.end());
}

void test_vector02()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//±éÀú
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

void test_vector03()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	cout << v.size() << endl;
	cout << v.max_size() << endl;
	cout << v.capacity() << endl;

	v.assign(10, 5);
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

void test_vector04()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.reserve(100);
	v.resize(50, 5);
	v.resize(10);
}

void test_vector05()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator ret1 = find(v.begin(), v.end(), 3);
	if (ret1 != v.end())
	{
		cout << "Yes" << endl;
		v.insert(ret1, 30);
	}

	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	vector<int>::iterator ret2 = find(v.begin(), v.end(), 30);
	if (ret2 != v.end())
	{
		v.erase(ret2);
	}

	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv;
//		vv.resize(numRows);
//		for (int i = 0; i < numRows; ++i)
//		{
//			vv[i].resize(i + 1);
//			vv[i][0] = 1;
//			vv[i][vv[i].size() - 1] = 1;
//		}
//
//		for (int i = 0; i < numRows; ++i)
//		{
//			for (int j = 0; j < vv[i].size(); ++j)
//			{
//				if (vv[i][j] == 0)
//				{
//					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//				}
//			}
//		}
//
//		return vv;
//
//	}
//};

class Solution {
public:
	bool isPalindrome(string s) {
		string cur;
		for (int i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]) || isdigit(s[i]))
			{
				if (isupper(s[i]))
				{
					tolower(s[i]);
				}
				cur += s[i];
			}
		}
		string ret = cur;
		reverse(cur.begin(), cur.end());

		if (cur == ret)
			return true;
		else
			return false;

	}
};
int main()
{
	//test_vector01();
	//test_vector02();
	//test_vector03();
	////test_vector04();
	//test_vector05();

	//size_t sz;
	//std::vector<int> foo;
	//sz = foo.capacity();
	//std::cout << "making foo grow:\n";
	//for (int i = 0; i < 100; ++i) {
	//	foo.push_back(i);
	//	if (sz != foo.capacity()) {
	//		sz = foo.capacity();
	//		std::cout << "capacity changed: " << sz << '\n';
	//	}
	//}
	Solution st;
	st.isPalindrome("A man, a plan, a canal: Panama");

	return 0;
}

