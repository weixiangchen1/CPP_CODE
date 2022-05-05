#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#include "priority_queue.h"
void test_priority_queue()
{
	//priority_queue<int, vector<int>, greater<int>> pq;
	priority_queue<int> pq;
	pq.push(1);
	pq.push(5);
	pq.push(5);
	pq.push(7);
	pq.push(9);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

}

struct LessPDate
{
	bool operator()(const date* d1, const date* d2) const
	{
		//return *d1 < *d2;
		return (d1->_year < d2->_year) ||
			(d1->_year == d2->_year && d1->_month < d2->_month) ||
			(d1->_year == d2->_year && d1->_month == d2->_month && d1->_day < d2->_day);
	}
};

void test_priority_queue2()
{
	//priority_queue<date> pq;
	priority_queue<date, vector<date>, greater<date>> pq;

	pq.push(date(2022, 3, 26));
	pq.push(date(2021, 10, 26));
	pq.push(date(2023, 3, 26));

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
	cout << endl;
}

void test_priority_queue3()
{
	//priority_queue<date> pq;
	priority_queue<date*, vector<date*>, LessPDate> pq;

	pq.push(new date(2022, 3, 26));
	pq.push(new date(2021, 10, 26));
	pq.push(new date(2023, 3, 26));

	while (!pq.empty())
	{
		cout << *pq.top();
		pq.pop();
	}
	cout << endl;
}

int main()
{
	//test_priority_queue();
	//test_priority_queue2();
	test_priority_queue3();
	//cwx::test01();

	return 0;
}